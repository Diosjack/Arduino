void ANALISIS_RED(){
  lcd.clear();
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("RED ICE ACTIVA");
  lcd.setCursor(0,1);
  lcd.print ("Voltaje: ");     
  lcd.print (VOLT_ICE);
  lcd.print(" V");
  delay (1000);
  lcd.clear();
  delay(500);
  lcd.setCursor(0,0);
  lcd.print("ANALIZANDO");
  lcd.setCursor(0,1);
  lcd.print ("REVISION: ");     
  lcd.print (TIEMPO);
  delay(2000);
}
