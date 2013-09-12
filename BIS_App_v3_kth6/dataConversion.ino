unsigned int dataConversion() {

  xBIS =  (dataArray[7]-48) + 10*(dataArray[5]-48);  // Convert the ASCII DEC # to integer # for tenth and ones digits (XX)

  if (dataArray[4] != 32) {
    xBIS += 100*(dataArray[4]-48);    // Convert ASCII DEC # to integer # for tens digit  (XXX)
  }

  if (dataArray[3] != 32) {
    xBIS += 1000*(dataArray[3]-48);  // Convert ASCII DEC # to integer # for hundreds digit  (XXXX)
  }

  Serial.print(char(9));    // Print a tab space
  Serial.print(xBIS);       // Print the BIS index # (0 -> 1000) == (0.0 -> 100.0).
  return xBIS;
} 

