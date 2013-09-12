void dataExtractConverWrite(int inByte) {
  if (count < 8) {
    dataArray[count] = inByte;
    Serial.print(char(dataArray[count]));
    count += 1;
  }

  else {
    count = 0;
    indexBIS = dataConversion();  // indexBIS = 0 -> 1000
    tV = (double) indexBIS/202;
    
    if (tV<4.95) pwmVal = 51.96*tV - 2.1412;
    
    else if (tV>=4.95) pwmVal = 255;
    
    if (pwmVal<0) pwmVal = 0;
    
    analogWrite(analogPin,pwmVal);     // Write the pwmValue to the analogPin. Scaled from (0 -> 255).
    
    // VIEW IT ON SERIAL PRINT
    Serial.print(indexBIS);
    Serial.print(char(9));
    Serial.print(tV);
    Serial.print(char(9));
    Serial.print(pwmVal);
    Serial.println(); 
  }
}


