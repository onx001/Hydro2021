#include <WiFi.h>
#include <Arduino.h>
#define WIFI_NETWORK "dlink-C934"
#define WIFI_PASSWORD "oclib29236"
#define WIFI_TIMEOUT_MS 20000

void connectToWiFi()
{
    Serial.print("Connecting to wifi");
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD);

    unsigned long startAttemptTime = millis();

    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS)
    {
        Serial.print(".");
        delay(100);
    }
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("Failed");
    }
    else
    {
        Serial.print("Connected");
        Serial.println(WiFi.localIP());
    }
}

void setup()
{

    // put your setup code here, to run once:
    Serial.begin(9600);
    connectToWiFi();
    Serial.write("READY"); //let app know we are ready
}

void loop()
{
    Serial.println(WiFi.localIP());
    // put your main code here, to run repeatedly:
    if (Serial.available() != 0)
    { //if there are bytes to be read
        Serial.readString();
    }
}