#include "BmeWrapper.h"

BmeWrapper::BmeWrapper() {
  // Serial.println("-----Starting BMP sensor");
  if (!bme.begin(0x76)) {
    // Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1)
      ;
  }
  // Serial.println("-----BMP sensor started");
}

float BmeWrapper::readTemperature() { return bme.readTemperature(); }

float BmeWrapper::readHumidity() { return bme.readHumidity(); }

float BmeWrapper::readPressure() { return bme.readPressure() / 100.F; }
