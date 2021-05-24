#include "BmeWrapper.h"
#include "EspNetwork.h"
#include "State.h"

Ticker loopTicker;
BmeWrapper bme;
State *state;

void setup() {
  BrokerCredentials brokerCredentials("test.mosquitto.org", 1883);
  WiFiCredentials wiFiCredentias("TP-Link_513C", "55955430");
  EspNetwork network(brokerCredentials, wiFiCredentias);
  network.connect();
  state = new State(network);
  loopTicker.attach(10, []() {
    state->setTemp(bme.readTemperature());
    state->setHumidity(bme.readHumidity());
    state->setPressure(bme.readPressure());
  });
}

void loop() {}
