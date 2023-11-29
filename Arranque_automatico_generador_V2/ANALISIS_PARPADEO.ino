void ANALISIS_PARPADEO(){
  TIEMPO_ICE = TIEMPO_ICE + 1;
  lcd.clear();
  delay(300);
  lcd.setCursor (0,0);
  lcd.print ("ANALIZANDO CAIDA");
  lcd.setCursor (0,1);
  lcd.print ("DE TENSION");
  delay(1000);
  lcd.clear();
  delay(300);
  lcd.setCursor (0,0);
  lcd.print ("PUEDE SER");
  lcd.setCursor (0,1);
  lcd.print ("MOMENTANEA"); 
  delay(1000);
  lcd.clear();
  delay(200);
  lcd.setCursor (0,0);
  lcd.print ("ICE HABILITADO");
  lcd.setCursor (0,1);
  lcd.print ("Voltaje: ");     
  lcd.print (VOLT_ICE);
  lcd.print(" V");
  delay(1000);
}

