  void ARRANQUE_SEGUNDO_INTENTOS(){
    delay(2000);
  FORD_MEDIR();    
  INTENTO = 1;
  while(GENERADOR == 0 and INTENTO < 6){
    if (INTENTO < 3){
      lcd.clear();
      delay(2000);
      lcd.setCursor (0,0);
      lcd.print("EN MARCHA");
      lcd.setCursor(0,1);
      lcd.print("MOTOR N=");
      lcd.print(INTENTO);
      SHOCK.write (S_S);
      delay(1000);
      SHOCK.write (C_S);
      delay(3000);           
      digitalWrite (RELE4, LOW); // Manda a arrancar el generardor
      delay (2000);
      SHOCK.write (S_S);
      delay (1000);
      digitalWrite (RELE4,HIGH); // saca el aranque
      lcd.clear();
      delay (5000);
      INTENTO = INTENTO + 1;
    }
    else{
      lcd.clear();
      delay(1000);
      lcd.setCursor (0,0);
      lcd.print("INTENTAR MARCHA");
      lcd.setCursor(0,1);
      lcd.print("SIN SHOCK ACTIVO");
      delay(2000);
      lcd.clear();
      lcd.setCursor (0,0);
      lcd.print("EN MARCHA");
      lcd.setCursor(0,1);
      lcd.print("MOTOR N=");
      lcd.print(INTENTO);
      SHOCK.write (S_S);
      delay(1000);  
      digitalWrite (RELE4, LOW); // Manda a arrancar el generardor
      delay (2500);
      SHOCK.write (S_S);
      delay (1000);
      digitalWrite (RELE4,HIGH); // saca el aranque
      delay (5000);
      INTENTO = INTENTO + 1;
    }
    FORD_MEDIR();
    if (VOLT_FORD > 90) {
      GENERADOR = 1;
    }
    else{
      GENERADOR = 0;
    }
  }
  }

  void ARRANQUE_MANTENIMIENTO(){
  INTENTO = 1;
  FORD_MEDIR();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print ("ARRANQUE DE");
  lcd.setCursor(0,1);
  lcd.print ("MANTENIMIENTO"); 
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print ("CONECTA");
  lcd.setCursor(0,1);
  lcd.print ("IGNICION");                                       
  delay(2000);
  lcd.clear();
  delay(100);
  digitalWrite (RELE3, LOW); // Le da ignición al generador
  INTENTO = 0;
  while(GENERADOR == 0 and INTENTO < 6){
    if (INTENTO < 3){
      lcd.clear();
      delay(2000);
      lcd.setCursor (0,0);
      lcd.print("ACTIVAR MARCHA");
      lcd.setCursor(0,1);
      lcd.print("INTENTO ");
      lcd.print(INTENTO);
      delay(1500);
      lcd.clear();
      SHOCK.write (S_S);
      delay(1000);
      SHOCK.write (C_S);
      delay(2000);           
      digitalWrite (RELE4, LOW); // Manda a arrancar el generardor
      delay (2000);
      SHOCK.write (S_S);
      delay (1000);
      digitalWrite (RELE4,HIGH); // saca el aranque
      INTENTO = INTENTO + 1;
    }
    else{
      lcd.clear();
      delay(1000);
      lcd.setCursor (0,0);
      lcd.print("INTENTAR MARCHA");
      lcd.setCursor(0,1);
      lcd.print("SIN SHOCK ACTIVO");
      lcd.clear();
      delay(800);
      lcd.setCursor (0,0);
      lcd.print("ACTIVAR MARCHA");
      lcd.setCursor(0,1);
      lcd.print("INTENTO ");
      lcd.print(INTENTO);
      SHOCK.write (S_S);
      delay(1000);  
      digitalWrite (RELE4, LOW); // Manda a arrancar el generardor
      delay (2500);
      SHOCK.write (S_S);
      delay (1000);
      digitalWrite (RELE4,HIGH); // saca el aranque
      INTENTO = INTENTO + 1;
    }
    delay(5000);
    FORD_MEDIR();
    if ( GENERADOR == 1) {
      GENERADOR_MANTE_ON = true;
      INICIAR_MANTE = false;
    }
    else{
      INICIAR_MANTE = false;
    }
  }
  }
