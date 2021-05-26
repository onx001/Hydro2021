#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void bluetoothPrint(String BtStr)
{
    unsigned l = BtStr.length();
    for(int i=0; i<l; i++)
    {
        if(BtStr[i]!='\0')
            SerialBT.write(char(BtStr[i]));
    }

}

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Hydroponics");
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {


  String dataChunk1 = "data";
  String message;

  

  if (SerialBT.available()){

    bluetoothPrint(dataChunk1);
    
    char incomingChar = SerialBT.read();
    if (incomingChar != '\n'){
      message += String(incomingChar);
    }
    else{
      message = "";
    }
  }

  
  delay(20);
}
