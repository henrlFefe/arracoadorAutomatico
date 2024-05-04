#include "RTClib.h"
#define motor 8

RTC_DS3231 relogin;

char diaDaSemana[7][12] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sabado"};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  relogin.begin();

  #ifndef ESP8266
    while (!Serial);
  #endif

  if (! relogin.begin()) {
    Serial.println("Relógio não encontrado");
    Serial.flush();
    while (1) delay(10);
  }

  if (relogin.lostPower()) {
    Serial.println("Relógio perdeu conexão, reconfigure-o");
    relogin.adjust(DateTime(F(__DATE__), F(__TIME__)));  //ajustar as horas automaticamente
    // relogin.adjust(DateTime(2014, 1, 21, 3, 0, 0)); //ajustar as horas manualmente
  }
  relogin.adjust(DateTime(F(__DATE__), F(__TIME__)));  //ajustar as horas automaticamente
  // relogin.adjust(DateTime(2014, 1, 21, 3, 0, 0)); //ajustar as horas manualmente

  /*
  now.dayOfTheWeek(); dia da semana
  now.day(); dia em número
  now.month(); mês
  now.year(); ano
  now.hour(); hora
  now.minute(); minuto
  now.second(); segundo
  */

    pinMode(motor, OUTPUT);

}

void loop() {
  DateTime now = relogin.now();
  int tempo = 20;

  if (now.hour() == 7){
    while (now.minute() == 0 && now.second != tempo){
      giraOn();
    }
  }
  if (now.hour() == 12){
    while (now.minute() == 0 && now.second != tempo){
      giraOn();
    }
  }
  if (now.hour() == 18){
    while (now.minute() == 0 && now.second != tempo){
      giraOn();
    }
  }
}
void giraOn(){
  delay(3000);
  digitalWrite(motor, HIGH);
  delay(4000);
  digitalWrite(motor, LOW);
  delay(500);
}
void giraOff(){
  digitalWrite(motor, LOW);
  delay(1000);
  digitalWrite(motor, LOW);
  delay(500);  
}
