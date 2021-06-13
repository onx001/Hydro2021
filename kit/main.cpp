#include <Arduino.h>
#define onboard 13 //pin for light

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    Serial.write("READY"); //let app know we are ready
}

void loop()
{
    // put your main code here, to run repeatedly:
    if (Serial.available() != 0)
    { //if there are bytes to be read
        Serial.readString();
    }
}