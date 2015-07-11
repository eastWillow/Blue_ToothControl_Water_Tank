#include <LBT.h>
#include <LBTServer.h>
  
void setup()
{
  Serial.begin(9600);
  bool success = LBTServer.begin((uint8_t*)"WaterTank");
  if( !success )
  {
      Serial.println("Cannot begin Bluetooth Server successfully");
      // don't do anything else
      while(true);
  }
  else
  {
      Serial.println("Bluetooth Server begin successfully");
  }
 pinMode(9, OUTPUT);
 pinMode(13,INPUT_PULLUP);
 LBTServer.setTimeout(30);
}
 
void loop()
{
  if(!LBTServer.connected())
    {
       // waiting for Spp Client to connect
       bool connected = LBTServer.accept(10);
 
       if( !connected )
       {
           Serial.println("No connection request yet");
           // don't do anything else
           while(!LBTServer.accept(1)){
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
        while(LBTServer.available() >0){
          //Serial.write(LBTServer.read());
          inChar = LBTServer.read();
          switch(inChar){
            case 'N':
              
              Serial.println("Forward");
              break;
            case 'E':
              Serial.println("Right");
              break;
            case  'W':
              Serial.println("Left");
              break;
            case 'S':
              Serial.println("Backward");
              break;
          }
        }
    }
}
