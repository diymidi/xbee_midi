#include <XBee.h>
#include <SoftwareSerial.h>

/*
MR-2 V0.1
 2013-1-10 PracticaUsage.com
 
 Receive data on XBee radio using a Software Serial Port
 then send it all to the Hardware Serial Port
 */

void setup()
{
 SoftwareSerial(xbeeSerial);
 xbeeSerial::xbeeSerial():xbeeSerial(2, 3); //RX,TX
 Serial.begin(31250);
 xbeeSerial.begin(38400); //can be any speed. XBee receives
 // at whatever speed the other XBee is transmitting
 Serial.print("MR-1 V01 xBee RCV"); //for debugging
}
 
void loop()
{
 SoftwareSerial(xbeeSerial);
 if (Serial.available()) { //send on standard Serial
 //anything from xbeeSerial
 Serial.print(" "); //for debugging
 Serial.print(xbeeSerial.read()); //for debugging
 Serial.write(xbeeSerial.read());
 }
}
