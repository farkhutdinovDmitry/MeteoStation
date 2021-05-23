#include "State.h"

State::State(EspNetwork network) {
  this->network = network;
  this->humidity = 0.0;
  this->temp = 0.0;
  this->pressure = 0.0;
}

void State::setTemp(float temp) {
  this->temp = temp;
  network.publish("temp", std::to_string(temp));
}

void State::setHumidity(float humidity) {
  this->humidity = humidity;
  network.publish("humidity", std::to_string(humidity));
}

void State::setPressure(float pressure) {
  this->pressure = pressure;
  network.publish("pressure", std::to_string(pressure));
}
