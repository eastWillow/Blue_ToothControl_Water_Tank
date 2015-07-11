#include <LBT.h>
#include <LBTServer.h>
#define RELAY 12
void setup()
{
  initialMotor();
  Serial.begin(9600);
  bool success = LBTServer.begin((uint8_t*)"WaterTank");
  if ( !success )
  {
    Serial.println("Cannot begin Bluetooth Server successfully");
    // don't do anything else
    while (true);
  }
  else
  {
    Serial.println("Bluetooth Server begin successfully");
  }
  pinMode(9, OUTPUT);
  pinMode(13, INPUT_PULLUP);
  LBTServer.setTimeout(30);
}

void loop()
{
  pinMode(RELAY, OUTPUT);
  if (!LBTServer.connected())
  {
    // waiting for Spp Client to connect
    bool connected = LBTServer.accept(10);

    if ( !connected )
    {
      Serial.println("No connection request yet");
      // don't do anything else
      while (!LBTServer.accept(1)) {
        Serial.println("No connection request yet");
      }
    }
    else
    {
      Serial.println("Connected");
    }
  }
  else
  {
    char inChar;
    while (LBTServer.available() > 0) {
      //Serial.write(LBTServer.read());
      inChar = LBTServer.read();
      switch (inChar) {
        case 'N':
          Serial.println("Forward");
          leftMotor(1023, HIGH, LOW);
          rightMotor(1023, LOW, HIGH);
          delay(20);
          break;
        case 'E':
          Serial.println("Right");
          leftMotor(1023, HIGH, LOW);
          rightMotor(1023, HIGH, LOW);
          delay(20);
          break;
        case  'W':
          Serial.println("Left");
          leftMotor(1023, LOW, HIGH);
          rightMotor(1023, LOW, HIGH);
          delay(20);
          break;
        case 'S':
          Serial.println("Backward");
          leftMotor(1023, LOW, HIGH);
          rightMotor(1023, HIGH, LOW);
          delay(20);
          break;
        case '1':
          Serial.println("RightForward");
          leftMotor(1023, HIGH, LOW);
          rightMotor(400, LOW, HIGH);
          delay(20);
          break;
        case '2':
          Serial.println("LeftForward");
          leftMotor(400, HIGH, LOW);
          rightMotor(1023, LOW, HIGH);
          delay(20);
          break;
        case '3':
          Serial.println("LeftBackward");
          leftMotor(400, LOW, HIGH);
          rightMotor(1023, HIGH, LOW);
          delay(20);
          break;
        case '4':
          Serial.println("RightBackward");
          leftMotor(1023, LOW, HIGH);
          rightMotor(400, HIGH, LOW);
          delay(20);
          break;
        case 'F':
          Serial.println("Fire!");
          digitalWrite(RELAY,HIGH);
          delay(20);
          break;
      }
    }
    leftMotor(0, LOW, LOW);
    rightMotor(0, LOW, LOW);
    digitalWrite(RELAY,LOW);
  }
}
