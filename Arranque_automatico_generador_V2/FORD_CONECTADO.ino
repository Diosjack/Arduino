void FORD_ACTIVO(){
  digitalWrite (RELE2,LOW);
  SHOCK.write (S_S);
  lcd.clear();
  delay(500);
  lcd.setCursor (0,0);
  lcd.print ("FORD HABILITADO");
  lcd.setCursor (0,1);
  lcd.print ("Voltaje: ");     
  lcd.print (VOLT_FORD);
  lcd.print(" V");
  delay(100);
}

