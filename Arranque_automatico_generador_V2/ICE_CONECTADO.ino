void ICE_ACTIVO (){
  SHOCK.write (S_S);
  digitalWrite (RELE1,LOW);
  lcd.clear();
  delay(400);
  lcd.setCursor (0,0);
  lcd.print ("ICE HABILITADO");
  lcd.setCursor (0,1);
  lcd.print ("Voltaje: ");     
  lcd.print (VOLT_ICE);
  lcd.print(" V");
  delay(2000);
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print ("FCH: ");
  lcd.setCursor (5,0);
  lcd.print (FECHA);   
  lcd.setCursor (0,1);
  lcd.print ("MTO: ");
  lcd.setCursor (5,1);
  lcd.print (SET_FECHA);  
  delay(500);
  
  ICE_OFF = 0;
  TIEMPO_ICE = 0;
}
void DISPLAY_MANTENIMIENTO (){
  lcd.clear();
  delay(200);
  lcd.setCursor (0,0);
  lcd.print ("ACTIVADO MODO");
  lcd.setCursor (0,1);
  lcd.print ("MANTENIMIENTO");     
  delay(1200);
  lcd.clear();
  delay(200);
  lcd.setCursor (0,0);
  lcd.print ("FC: ");
  lcd.setCursor (5,0);
  lcd.print (FECHA);   
  lcd.setCursor (0,1);
  lcd.print ("DX: ");
  lcd.setCursor (5,1);
  lcd.print (SET_FECHA_D);  
  delay(1200);
}
