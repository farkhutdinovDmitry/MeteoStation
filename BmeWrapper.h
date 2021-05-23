#ifndef BMEWRAPPER_H
#define BMEWRAPPER_H

#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>

class BmeWrapper {
public:
  BmeWrapper();

  float readTemperature();
  float readHumidity();
  float readPressure();

private:
  Adafruit_BME280 bme;
};

#endif // BMEWRAPPER_H
