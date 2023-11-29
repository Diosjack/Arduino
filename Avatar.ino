//Reles
int RELE = 9;
int RELE2 = 8;
//Variables de tiempo
int HORA = 20;
int MINUTO = 41;
int SEGUNDO = 50;
int HORA2 = 20;
int MINUTO2 = 41;
int SEGUNDO2 = 55;
//Variables del encoder
int BOTON = 7;
int DT = 4;
int CLK = 2;


#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd (0x27,16,2);
ThreeWire myWire(6,3,5); // IO, SCLK, 
RtcDS1302<ThreeWire> Rtc(myWire);
void setup() {
  Serial.begin(57600);
  pinMode(RELE, OUTPUT);
  pinMode(RELE2,OUTPUT);
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(BOTON,INPUT_PULLUP);
  digitalWrite(RELE,HIGH);
  digitalWrite(RELE2,HIGH);
  Rtc.Begin();
  RtcDateTime compiled = RtcDateTime(__DATE__,__TIME__);
  printDateTime(compiled);
  Serial.println();
  //lcd monitor
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Avatar");
  lcd.setCursor(0,1);
  lcd.print("Ing Erick Q.");
  delay(5000);
  lcd.clear();
}

void loop() {
  //programa encoder
  
  //programa para el reloj 
  RtcDateTime now = Rtc.GetDateTime();
  printDateTime(now);
  Serial.println();
  if(!now.IsValid()){
    Serial.println("Error en fecha y hora");
  }
  delay(1000);
}
#define countof(a) (sizeof(a) / sizeof(a[0]))
void printDateTime(const RtcDateTime& dt){
  //fecha
  char fecha[20];
  snprintf_P(fecha,
  countof(fecha),
  PSTR("%02u/%02u/%04u"),
  dt.Month(),
  dt.Day(),
  dt.Year());
  //hora
  char hora[20];
  snprintf_P(hora,
  countof(hora),
  PSTR("%02u:%02u:%02u"),
  dt.Hour(),
  dt.Minute(),
  dt.Second());
  //lcd
  lcd.setCursor(0,0);
  lcd.print("Fec: ");
  lcd.print(fecha);
  lcd.setCursor(0,1);
  lcd.print("Hora: ");
  lcd.print(hora);
  //Alarmas
  if(dt.Hour() == HORA and dt.Minute() == MINUTO and dt.Second() == SEGUNDO){
    digitalWrite(RELE,LOW);
    }
  if(dt.Hour() == HORA2 and dt.Minute() == MINUTO2 and dt.Second() == SEGUNDO2){
    digitalWrite(RELE2,LOW);
    
    }
  }
