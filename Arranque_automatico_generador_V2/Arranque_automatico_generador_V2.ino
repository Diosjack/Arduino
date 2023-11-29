#include <LiquidCrystal_I2C.h>
#include <FilterDerivative.h>
#include <FilterOnePole.h>
#include <Filters.h>
#include <RunningStatistics.h>
#include <Wire.h>
#include <Filters.h>
#include <Servo.h>
#include <MyRealTimeClock.h>

#define countof(a) (sizeof(a) / sizeof(a[0]))

LiquidCrystal_I2C lcd (0x27,16,2);
MyRealTimeClock RTC (9, 10, 11);
Servo SHOCK ;

bool PRIMER_SET = true;
bool INICIAR_MANTE = false;
bool GENERADOR_MANTE_ON = false;
bool ACABA_CONECTAR = false;
int MANTE_TIEMPO;
int REVISIONES = 0;
int MINUTO;
int HORA;
int DIA;
int MES;
int SET_MINUTO;
int SET_HORA;
int SET_DIA;
int SET_MES;
int SET_MINUTO_D;
int SET_HORA_D;
int SET_DIA_D;
int SET_MES_D;
String FECHA;
String SET_FECHA;
String SET_FECHA_D;
int PINSERVO = 3;
int PULSOMIN = 900;
int PULSOMAX = 2150;

float testFrequency = 60;
float windowLength = 40/testFrequency;
float intercept = -0.04;
float slope = 0.0405;
float VOLT_ICE;
float VOLT_FORD;
unsigned long periodo = 1000;
unsigned long tiempoAnterior = 0;

int RELE1 = 5;
int RELE2 = 6;
int RELE3 = 7;
int RELE4 = 8;
int LECTURA_ICE = 0;
int LECTURA_FORD = 1;
int FORD_ON;
int ICE_OFF;
int CONTEO;
int TIEMPO_ICE;
int INTENTO;
int NORMALIZADO;
int TIEMPO ;
int GENERADOR;
int FALLO_GENERACION;
int S_S = 0;
int C_S =180;

void setup() {
  //RTC.setDS1302Time(Segundos, Minutos, Hora, Milisegundos, Dia, Mes, Año)
  //RTC.setDS1302Time(0,12,4,0,19,10,2023);
  SHOCK.attach (PINSERVO,PULSOMIN,PULSOMAX);
  Serial.begin (57600);
  lcd.init();
  lcd.begin(16,2);
  lcd.backlight(); 
  lcd.clear();
  pinMode(RELE1,OUTPUT); // Conexión ICE
  pinMode(RELE2,OUTPUT); // Conecxión Generador
  pinMode(RELE3,OUTPUT); // Activa ignición de generador
  pinMode(RELE4,OUTPUT); // Activa el encendido del generador
  digitalWrite (RELE1,HIGH);
  digitalWrite (RELE2,HIGH);
  digitalWrite (RELE3,HIGH);
  digitalWrite (RELE4,HIGH);
  lcd.clear ();
  lcd.setCursor(3,0);
  lcd.print ("COSTA RICA");
  lcd.setCursor(4,1);
  lcd.print("EDM SA.");
  delay (5000);
  lcd.clear ();
  lcd.setCursor(0,0);
  lcd.print ("INGENIERO");
  lcd.setCursor(0,1);
  lcd.print("RONNY QUESADA");
  delay (5000);
  lcd.clear ();
  lcd.setCursor(5,0);
  lcd.print ("W Y M");
  lcd.setCursor(3,1);
  lcd.print("CONCENTRADOS");
  delay (4000);
  lcd.clear();
  delay (1000);
  lcd.setCursor(3,0);
  lcd.print ("INICIANDO");
  lcd.setCursor(4,1);
  lcd.print("SISTEMA");
  delay (4000);
  lcd.clear ();
  SHOCK.write(S_S);
}
void loop() {
lcd.display();
CONTEO = 0;
FORD_ON = 0;
TIEMPO = 0;
RTC.updateTime();
RELOJ ();
AGENDAR_FECHAS_ARRANQUE ();
ICE_MEDIR ();
FORD_MEDIR();

  if(VOLT_ICE >110 and VOLT_ICE < 135){
        if ((GENERADOR == 1) and (GENERADOR_MANTE_ON == false)){
              while (TIEMPO < 4){
                    ANALISIS_RED();
                    ICE_MEDIR ();
                          if (VOLT_ICE > 112 and VOLT_ICE < 135){
                                FORD_ON = FORD_ON + 1;
                                TIEMPO = TIEMPO +1;
                          }
                          else{
                                TIEMPO = TIEMPO + 1;    
                          }
                          
              }
              
              if (FORD_ON > 3){
                    DESCONECTAR_FORD();
              }
              else{
                    RED_NO_ESTABLE();
              }
        }
        else{
              ICE_ACTIVO ();
              if( GENERADOR_MANTE_ON == true){
                DISPLAY_MANTENIMIENTO ();
                REVISAR_FECHA_APAGAR ();
              }
              if ((INICIAR_MANTE == true) and (GENERADOR_MANTE_ON == false)){
                ARRANQUE_MANTENIMIENTO();
              }
        }
  }
  else {
        if (TIEMPO_ICE < 3){
              ANALISIS_PARPADEO();
        }
        else{
              
              if ((GENERADOR == 1) and (GENERADOR_MANTE_ON == false)){
                    FORD_ACTIVO();
              }
              else if  ((GENERADOR == 1) and (GENERADOR_MANTE_ON == true)){
                    NORMALIZANDO();
                    CONECTAR_FORD();
                    
              }
              else{ 
                    ARRANCAR();
                    delay (4000);
                    FORD_MEDIR();
                          if (GENERADOR == 1){
                                NORMALIZANDO();
                                CONECTAR_FORD();
                          }
                          else{
                                VOLVER_INTENTAR();
                                ARRANQUE_SEGUNDO_INTENTOS();
                                      if (GENERADOR == 1){
                                            NORMALIZANDO();
                                            CONECTAR_FORD();
                                      }
                                       else{
                                            ALARMA();
                                       }
                          }
              }
        }
  }
}
