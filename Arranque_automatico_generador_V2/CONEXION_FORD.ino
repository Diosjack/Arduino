void CONECTAR_FORD(){
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print("DESCONECTANDO");
  lcd.setCursor (0,1);
  lcd.print("LINEA ICE");
  delay(1500);
  digitalWrite (RELE1,HIGH); 
  delay(3000);
  lcd.clear();
  delay(500);
  lcd.setCursor (0,0);
  lcd.print("CONECTANDO");
  lcd.setCursor (0,1);
  lcd.print("GENERADOR FORD");
  delay(1000);
  digitalWrite (RELE2,LOW);
  delay(6000);
  GENERADOR_MANTE_ON = false;
}
