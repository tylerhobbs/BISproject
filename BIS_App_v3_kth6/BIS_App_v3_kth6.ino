/* BIS Index Extraction and Processing Program
 Created by: Tyler Hobbs, Matt Brown
 July 24, 2013
 */

#define analogPin 2
#define vertBarAscii 124

int countVertBar = 0;
int dataArray[8];
int count = 0;
int i=0;
unsigned int xBIS;
unsigned int indexBIS;
double pwmVal, tV;

void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // read from port 1 [RS-232], send to port 0 [COMP/ARDUINO]:
  if (Serial1.available()) {
    int inByte = Serial1.read();
    //Serial.write(inByte);

    if (countVertBar == 11) {                // Begin code for BIS Index # field data.
      dataExtractConverWrite(inByte);        // Extract, convert, and write the BIS Index # to the computer.
    }

    if (inByte == vertBarAscii) {  // Increment Vertical Bar field counter  
      countVertBar += 1;
    }

    if (countVertBar == 35)  {     // When end of line is reached, reset Vertical Bar field counter
      countVertBar = 0;
      Serial.println();
    }
  }

  // read from port 0 [COMP/ARDUINO], send to port 1 [RS-232]:
  if (Serial.available()) {
    int inByte = Serial.read();
    Serial1.write(inByte);
  }
}





