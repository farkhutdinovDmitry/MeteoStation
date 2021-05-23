#ifndef STATE_H
#define STATE_H

#include "EspNetwork.h"

class State {
public:
  State(EspNetwork network);
  void setTemp(float temp);
  void setHumidity(float humidity);
  void setPressure(float pressure);

private:
  EspNetwork network;
  float temp, humidity, pressure;
};

#endif // STATE_H
