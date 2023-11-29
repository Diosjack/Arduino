
void RED_NO_ESTABLE(){
  lcd.clear ();
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("RED ICE");
  lcd.setCursor(0,1);
  lcd.print("NO ESTABLE");
  delay (4000);
}

void NORMALIZANDO(){
  lcd.clear();
  delay (500);
  lcd.setCursor (0,0);
  lcd.print("NORMALIZANDO");
  NORMALIZADO = 0;
  FALLO_GENERACION = 0 ;
        while (NORMALIZADO < 4){
              delay(2000);
              FORD_MEDIR();
                    if (VOLT_FORD > 100 and VOLT_FORD < 140){
                          NORMALIZADO = NORMALIZADO + 1;
                          lcd.clear();
                          delay (2000);
                          lcd.setCursor (0,0);
                          lcd.print ("NORMALIZANDO");
                          lcd.setCursor (0,1);
                          lcd.print ("Voltaje: ");     
                          lcd.print (VOLT_FORD);
                          lcd.print(" V");
                          
                    }
                    else{
                          NORMALIZADO = 0;
                          lcd.clear();
                          delay (2000);
                          lcd.setCursor (0,0);
                          lcd.print ("SE DETECTA");
                          lcd.setCursor (0,1);
                          lcd.print ("FALLO GENERACION");
                          FALLO_GENERACION = FALLO_GENERACION +1;
                                if (FALLO_GENERACION > 4){
                                      lcd.clear();
                                      delay (2000);
                                      lcd.setCursor (0,0);
                                      lcd.print ("VOLTAJE FUERA");
                                      lcd.setCursor (0,1);
                                      lcd.print ("DE RANGO SEGURO");
                                      delay(1000);
                                      lcd.clear();
                                      delay (2000);
                                      lcd.setCursor (0,0);
                                      lcd.print ("LLAMAR AL");
                                      lcd.setCursor (0,1);
                                      lcd.print ("SERVICIO TECNICO");
                                      digitalWrite (RELE1,HIGH);
                                      digitalWrite (RELE2,HIGH);
                                      digitalWrite (RELE3,HIGH);
                                      digitalWrite (RELE4,HIGH);
                                }
                    }
          }
}
void VOLVER_INTENTAR(){
  lcd.clear();
  delay(2000);
  lcd.setCursor (0,0);
  lcd.print("SIN GENERACION");
  lcd.setCursor(0,1);
  lcd.print("VOLVER INTENTAR");
  delay(3000);
  lcd.clear();
}
void RELOJ (){

          HORA = RTC.hours;
          MINUTO = RTC.minutes;
          DIA = RTC.dayofmonth;
          MES = RTC.month;
          if(MINUTO < 10 ){
            FECHA = (String(HORA) + ":"+ "0" + String(MINUTO) + "-"+String(DIA)+ "/" + String(MES));
          }
          else{
            FECHA = (String(HORA) + ":" + String(MINUTO) + "-"+String(DIA)+ "/" + String(MES));
          }         
}
void AGENDAR_FECHAS_ARRANQUE (){
      if (PRIMER_SET == false){
      //Revisa que ya se cumpla el arranque de mantenimiento
            if ((MINUTO == SET_MINUTO) and (HORA == SET_HORA) and (DIA == SET_DIA) and (MES == SET_MES)){
                  ESTABLECER_MANTENIMIENTO();
                  DURACION_MANTENIMIENTO();
                  MANTE_TIEMPO = 12;
                  INICIAR_MANTE = true;
            }
      }
      if ( PRIMER_SET == true){
          MANTE_TIEMPO = 2;
          SET_MINUTO = MINUTO + 5;
          SET_HORA = HORA;
          SET_DIA = DIA;
          SET_MES = MES;
          CORRECCION_FECHA();
          if(SET_MINUTO < 10 ){
            SET_FECHA = (String(SET_HORA) + ":"+ "0" + String(SET_MINUTO) + "-"+ String(SET_DIA)+ "/" + String(SET_MES));
          }
          else{
            SET_FECHA = (String(SET_HORA) + ":" + String(SET_MINUTO) + "-"+ String(SET_DIA)+ "/" + String(SET_MES));
          }
          PRIMER_SET = false;
      }
      
  
}
void REVISAR_FECHA_APAGAR (){
  if ((MINUTO == SET_MINUTO_D) and (HORA == SET_HORA_D) and (DIA == SET_DIA_D) and (MES == SET_MES_D)){
      DESCONECTAR_FORD_MANTE();
    }
}
void ESTABLECER_MANTENIMIENTO(){
  
  SET_MINUTO = 50;
  SET_HORA = 6;
  SET_DIA = DIA + 4;
  SET_MES = MES;
  CORRECCION_FECHA();
  if(SET_MINUTO < 10 ){
    SET_FECHA = (String(SET_HORA) + ":"+ "0" + String(SET_MINUTO) + "-"+String(SET_DIA)+ "/" + String(SET_MES));
  }
  else{
    SET_FECHA = (String(SET_HORA) + ":" + String(SET_MINUTO) + "-"+String(SET_DIA)+ "/" + String(SET_MES));
  }
   
  
}

void DURACION_MANTENIMIENTO(){
  SET_MINUTO_D = MINUTO + MANTE_TIEMPO;
  SET_HORA_D = HORA;
  SET_DIA_D = DIA;
  SET_MES_D = MES;
  CORRECCION_FECHA_D();
  if (SET_MINUTO_D < 10){ 
   SET_FECHA_D = (String(SET_HORA_D) + ":"+ "0" + String(SET_MINUTO_D) + "-"+String(SET_DIA_D)+ "/" + String(SET_MES_D)); 
  }
  else{
    SET_FECHA_D = (String(SET_HORA_D) + ":" + String(SET_MINUTO_D) + "-"+String(SET_DIA_D)+ "/" + String(SET_MES_D));  
  }
   
}

void CORRECCION_FECHA (){
                //Revisa el tiempo valido
                if ((SET_MINUTO>59)and (SET_HORA < 23)){
                  SET_MINUTO = SET_MINUTO - 59;
                  SET_HORA = SET_HORA + 1;
                }
                if ((SET_MINUTO>59)and (SET_HORA == 23)){
                  SET_MINUTO = SET_MINUTO - 59;
                  SET_HORA = 0;
                  SET_DIA = SET_DIA +1;
                }
                if ((SET_MINUTO > 59)and (SET_HORA > 23)){
                  SET_MINUTO = SET_MINUTO - 59;
                  SET_HORA = SET_HORA - 24;
                  SET_DIA = SET_DIA +1;
                }
                if (SET_HORA > 23){
                  SET_HORA = SET_HORA - 24;
                  SET_DIA = SET_DIA +1;
                }
                // Revisa que el dia sea valido
                if((SET_DIA>31) and (SET_MES == 1)){
                  SET_DIA = SET_DIA - 31;
                  SET_MES = SET_MES + 1;
                }
                if((SET_DIA>28) and (SET_MES == 2)){
                  SET_DIA = SET_DIA - 28;
                  SET_MES = SET_MES + 1;
                }
                if((SET_DIA>31) and (SET_MES == 3)){
                  SET_DIA = SET_DIA - 31;
                  SET_MES = SET_MES + 1;
                }
                if((SET_DIA>30) and (SET_MES == 4)){
                  SET_DIA = SET_DIA - 30;
                  SET_MES = SET_MES + 1;
                }
                if((SET_DIA>31) and (SET_MES == 5)){
                  SET_DIA = SET_DIA - 31;
                  SET_MES = SET_MES + 1;
                }
                if((SET_DIA>30) and (SET_MES == 6)){
                  SET_DIA = SET_DIA - 30;
                  SET_MES = SET_MES + 1;
                }
                if((SET_DIA>31) and (SET_MES == 7)){
                  SET_DIA = SET_DIA - 31;
                  SET_MES = SET_MES + 1;
                }
                if((SET_DIA>31) and (SET_MES == 8)){
                  SET_DIA = SET_DIA - 31;
                  SET_MES = SET_MES + 1;
                }
                if((SET_DIA>30) and (SET_MES == 9)){
                  SET_DIA = SET_DIA - 30;
                  SET_MES = SET_MES + 1;
                }
                if((SET_DIA>31) and (SET_MES == 10)){
                  SET_DIA = SET_DIA - 31;
                  SET_MES = SET_MES + 1;
                }
                if((SET_DIA>30) and (SET_MES == 11)){
                  SET_DIA = SET_DIA - 30;
                  SET_MES = SET_MES + 1;
                }
                if((SET_DIA>31) and (SET_MES == 12)){
                  SET_DIA = SET_DIA - 31;
                  SET_MES = 1;
                }
                
          }
 void CORRECCION_FECHA_D (){
                //Revisa el tiempo valido
                if ((SET_MINUTO_D > 59)and (SET_HORA_D < 23)){
                  SET_MINUTO_D = SET_MINUTO_D - 59;
                  SET_HORA_D = SET_HORA_D + 1;
                }
                if ((SET_MINUTO_D > 59)and (SET_HORA_D == 23)){
                  SET_MINUTO_D = SET_MINUTO_D - 59;
                  SET_HORA_D = 0;
                  SET_DIA_D = SET_DIA_D +1;
                  
                }
                if ((SET_MINUTO_D > 59)and (SET_HORA_D > 23)){
                  SET_MINUTO_D = SET_MINUTO_D - 59;
                  SET_HORA_D = SET_HORA_D - 24;
                  SET_DIA_D = SET_DIA_D +1;
                }
                if (SET_HORA_D > 23){
                  SET_HORA_D = SET_HORA_D - 24;
                  SET_DIA_D = SET_DIA_D +1;
                }
                // Revisa que el dia sea valido
                if((SET_DIA_D>31) and (SET_MES_D == 1)){
                  SET_DIA_D = SET_DIA_D - 31;
                  SET_MES_D = SET_MES_D + 1;
                }
                if((SET_DIA_D > 28) and (SET_MES_D == 2)){
                  SET_DIA_D = SET_DIA_D - 28;
                  SET_MES_D = SET_MES_D + 1;
                }
                if((SET_DIA_D > 31) and (SET_MES_D == 3)){
                  SET_DIA_D = SET_DIA_D - 31;
                  SET_MES_D = SET_MES_D + 1;
                }
                if((SET_DIA_D > 30) and (SET_MES_D == 4)){
                  SET_DIA_D = SET_DIA_D - 30;
                  SET_MES_D = SET_MES_D + 1;
                }
                if((SET_DIA_D > 31) and (SET_MES_D == 5)){
                  SET_DIA_D = SET_DIA_D - 31;
                  SET_MES_D = SET_MES_D + 1;
                }
                if((SET_DIA_D > 30) and (SET_MES_D == 6)){
                  SET_DIA_D = SET_DIA_D - 30;
                  SET_MES_D = SET_MES_D + 1;
                }
                if((SET_DIA_D > 31) and (SET_MES_D == 7)){
                  SET_DIA_D = SET_DIA_D - 31;
                  SET_MES_D = SET_MES_D + 1;
                }
                if((SET_DIA_D > 31) and (SET_MES_D == 8)){
                  SET_DIA_D = SET_DIA_D - 31;
                  SET_MES_D = SET_MES_D + 1;
                }
                if((SET_DIA_D > 30) and (SET_MES_D == 9)){
                  SET_DIA_D = SET_DIA_D - 30;
                  SET_MES_D = SET_MES_D + 1;
                }
                if((SET_DIA_D > 31) and (SET_MES_D == 10)){
                  SET_DIA_D = SET_DIA_D - 31;
                  SET_MES_D = SET_MES_D + 1;
                }
                if((SET_DIA_D > 30) and (SET_MES_D == 11)){
                  SET_DIA_D = SET_DIA_D - 30;
                  SET_MES_D = SET_MES_D + 1;
                }
                if((SET_DIA_D > 31) and (SET_MES_D == 12)){
                  SET_DIA_D = SET_DIA_D - 31;
                  SET_MES_D = 1;
                }
                
}
void VISUAL_ARRANQUE_MANTE(){
      lcd.clear();
      delay(1000);
      lcd.setCursor(0,0);
      lcd.print ("GENERADOR: ");
      lcd.setCursor(12,0);
      lcd.print (GENERADOR);
      lcd.setCursor(0,1);
      lcd.print ("VAR MANTE: "); 
      lcd.setCursor(12,1);
      lcd.print (GENERADOR_MANTE_ON);
      delay(3000);
      
}
void VISUAL_VOLTAJE(){
  lcd.clear();
      delay(1000);
      lcd.setCursor(0,0);
      lcd.print ("VOLT FORD: ");
      lcd.setCursor(12,0);
      lcd.print (VOLT_FORD); 
      lcd.setCursor(0,1);
      lcd.print ("GENERADOR: ");
      lcd.setCursor(12,1);
      lcd.print (GENERADOR); 
      delay(2000);
      lcd.clear();
}
void REVISAR_VOLTAJE_FORD(){
  if(ACABA_CONECTAR == false){
        FORD_MEDIR();
  }
  if (ACABA_CONECTAR == true){
      ACABA_CONECTAR = false;
      while (REVISIONES >5){
      FORD_MEDIR();
      VISUAL_ARRANQUE_MANTE();
      VISUAL_VOLTAJE();
      REVISIONES = REVISIONES + 1;
      }
  }
}
