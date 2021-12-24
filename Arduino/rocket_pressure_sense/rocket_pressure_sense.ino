#include <EEPROM.h>
#include "HX711.h"
HX711 scale;

uint8_t data_pin = 6;
uint8_t clock_pin = 7;
uint8_t trigger_pin = 13;
uint8_t det_pin = 14;

float calibration = 0.00f;

class rocket {
  public:
    void launchRocket() {
      float starting_weight = (scale.get_units(10));
      Serial.println(scale.get_units());
      digitalWrite(det_pin, HIGH);
      while(current_weight > starting_weight);
        Serial.println(scale.get_units());
        current_weight = scale.get_units();
      delay(50);
      Serial.println(scale.get_units());
    }
};


void setup() {
  pinMode(trigger_pin, INPUT);
  pinMode(clock_pin, OUTPUT);

  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("LIBRARY VERSION: ");
  Serial.println(HX711_LIB_VERSION);
  Serial.println();

  scale.begin(data_pin, clock_pin);

  //calibration offset is stored at EEPROM 0-7
  EEPROM.get(0, calibration);
  scale.set_scale(calibration);

  Serial.print("UNITS: ");
  Serial.println(scale.get_units(10));
}

void loop() {
  if (digitalRead(trigger_pin)){
    rocket launchRocket();
  }
}
