#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>


#define SERVICE_UUID        "14dd8a7f-9847-4463-8bc9-5d296caa2ed8"
#define CHARACTERISTIC_UUID "16e0b758-bdf8-11eb-8529-0242ac130003"


class MyCallbacks: public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic)
  {
    std::string value = pCharacteristic->getValue();

    if (value.length() > 0)
    {
      Serial.println("*********");
      Serial.print("New value: ");
      for (int i = 0; i < value.length(); i++)
      {
        Serial.print(value[i]);
      }

      Serial.println();
      Serial.println("*********");
    }
  }
};


void setup() {
  Serial.begin(115200);
  Serial.println("Starting...");

  BLEDevice::init("Hydroponics");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristic->setValue("Connected!");
  pService->start();
  
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Setup Complete");
}

void loop() {

  
  std::string value = pCharacteristic->getValue();
  delay(2000);
}
