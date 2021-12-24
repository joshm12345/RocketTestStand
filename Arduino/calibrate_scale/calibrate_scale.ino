#include "EEPROM.h"
#include "HX711.h"
HX711 scale;

uint8_t dataPin = 6;
uint8_t clockPin = 7;
long calibration;

void setup() {
Serial.begin(115200);
Serial.println(__FILE__);
Serial.print("LIBRARY VERSION: ");
Serial.println(HX711_LIB_VERSION);
Serial.println();

scale.begin(dataPin, clockPin);

Serial.print("UNITS: ");
Serial.println(scale.get_units(10));

Serial.println("\nEmpty the scale, press a key to continue");
while(!Serial.available());
while(Serial.available()) Serial.read();

scale.tare();
Serial.print("UNITS: ");
Serial.println(scale.get_units(10));

Serial.println("\nPut 1000 gr in the scale, press a key to continue");
while(!Serial.available());
while(Serial.available()) Serial.read();

scale.calibrate_scale(1000, 10);
Serial.print("UNITS: ");
Serial.println(scale.get_units(10));

//calibration offset is stored at EEPROM 0-7
calibration = scale.get_scale();
EEPROM.put(0, calibration);

Serial.println("\nScale is calibrated, press a key to continue");
while(!Serial.available());
while(Serial.available()) Serial.read();
}

void loop(){}
