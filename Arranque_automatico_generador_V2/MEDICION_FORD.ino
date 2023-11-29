void FORD_MEDIR(){
  RunningStatistics inputStats;
  inputStats.setWindowSecs(windowLength);
  CONTEO = 0;
    while (CONTEO<5){
      LECTURA_FORD = analogRead (A1);
      inputStats.input(LECTURA_FORD);
      if ((unsigned long)(millis() - tiempoAnterior) >= periodo) {
        VOLT_FORD = intercept + slope * inputStats.sigma();
        VOLT_FORD = VOLT_FORD *(40.3231);
        tiempoAnterior = millis();
        delay(1);
        CONTEO = CONTEO +1;
      }
    }
    if (VOLT_FORD > 50) {
      GENERADOR = 1;
    }
    else{
      GENERADOR = 0;
      VOLT_FORD = 0;
    }
}

