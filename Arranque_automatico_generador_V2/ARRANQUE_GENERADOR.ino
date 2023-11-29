void ARRANCAR(){
      FORD_MEDIR();
            if (GENERADOR == 0){
                  VISUAL_ARRANQUE_MANTE();
                  digitalWrite (RELE2,HIGH);
                  SHOCK.write (S_S);
                  lcd.clear();
                  delay(500);
                  lcd.setCursor(0,0);
                  lcd.print ("INICIA SECUENCIA");
                  lcd.setCursor(0,1);
                  lcd.print ("DE ARRANQUE");
                  delay(1200);
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print ("DESCONEXION");
                  lcd.setCursor(0,1);
                  lcd.print ("RED ICE");                    
                  delay(1500);                   
                  digitalWrite (RELE1, HIGH); // Abre el circuito que conecta el la energía del ICE
                  lcd.clear();
                  delay(500);
                  lcd.setCursor(0,0);
                  lcd.print ("CONECTA");
                  lcd.setCursor(0,1);
                  lcd.print ("IGNICION");                                       
                  delay(2000);
                  lcd.clear();
                  delay(800);
                  digitalWrite (RELE3, LOW); // Le da ignición al generador
                  lcd.clear();
                  delay(4000);
                  lcd.setCursor(0,0);
                  lcd.print ("EN MARCHA");
                  lcd.setCursor(0,1);
                  lcd.print ("MOTOR");                     
                  lcd.clear();
                  SHOCK.write (C_S);
                  delay (1500);                
                  digitalWrite (RELE4, LOW); // Manda a arrancar el generardor
                  delay (2500);
                  SHOCK.write (S_S);
                  delay (800);
                  digitalWrite (RELE4,HIGH); // saca el aranque
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print ("REVISANDO");
                  lcd.setCursor(0,1);
                  lcd.print ("VOLTAJE FORD");
                  delay(2000);  
            }
            else{
                 GENERADOR_MANTE_ON = false;
                 VISUAL_ARRANQUE_MANTE();
            }
            
  
}
  
