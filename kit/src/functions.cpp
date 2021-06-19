// include library to read and write from flash memory
#include <EEPROM.h> //eeprom is where we store data

int waterValvePin = 0;
int valveAPin = 1; //arbitary pin numbers
int valveBPin = 2;
int valveCPin = 3;

int waterValveDuration = EEPROM.read(0); //read from stored data
int valveADuration = EEPROM.read(1);
int valveBDuration = EEPROM.read(2);
int valveCDuration = EEPROM.read(3);

int maxWaterLevel = 100; //arbitary water level

void main()
{
    if (getWaterLevel < minWaterLevel)
    {
        refill()
    }
}

void refill()
{
    openValve(valveA, valveADuration);
    openValve(valveB, valveBDuration);
    openValve(valveC, valveCDuration);
    openWaterValve();
}

void openValve(pin, duration) //the reason why we cannot use water sensor for this is that the change in water level is too negligible to be recorded accurately.
{                             //1 or 2ml change wont be seen at all
    digitalWrite(pin, HIGH);
    delay(duration);
    digitalWrite(pin, LOW);
}

void openWaterValve()
{
    digitalWrite(waterValvePin, HIGH);
    while (getWaterLevel() < maxWaterLevel)
    {
    } //keep valve open untill max water level reached
    digitalWrite(waterValvePin, LOW);
}

void getWaterLevel()
{
    //read water sensor
}