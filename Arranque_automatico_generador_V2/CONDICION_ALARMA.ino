void ALARMA(){
  while(VOLT_ICE < 100 ){
      digitalWrite (RELE1,HIGH);
      digitalWrite (RELE2,HIGH);
      digitalWrite (RELE3,HIGH);
      digitalWrite (RELE4,HIGH);
      lcd.clear();
      lcd.display();
      delay(100);
      lcd.setCursor(0,0);
      lcd.print ("ALARMA ACTIVA");
      delay(1000);
      lcd.setCursor(0,1);
      lcd.print ("SIN GENERACION");                                   
      delay(3000);
      lcd.noDisplay(); 
      ICE_MEDIR ();
  }
}

