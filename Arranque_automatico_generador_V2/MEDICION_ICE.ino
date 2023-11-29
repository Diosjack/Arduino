void ICE_MEDIR(){
RunningStatistics inputStats;
inputStats.setWindowSecs(windowLength);
  CONTEO = 0;
    while (CONTEO<5){
      LECTURA_ICE = analogRead (A0);
      inputStats.input(LECTURA_ICE);
        if ((unsigned long)(millis() - tiempoAnterior) >= periodo) {
          VOLT_ICE = intercept + slope * inputStats.sigma();
          VOLT_ICE = VOLT_ICE *(40.3231);      
          tiempoAnterior = millis();
          delay(1);
          CONTEO = CONTEO +1;
        }
        if (VOLT_ICE <50){
        VOLT_ICE = 0;
        }
   }
}

