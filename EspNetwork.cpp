#include "EspNetwork.h"

EspNetwork::EspNetwork(BrokerCredentials brokerCredentials,
                       WiFiCredentials wiFiCredentials) {
  wiFi(wiFiCredentials);
  mqttClient(&wiFi, brokerCredentials);
}

void EspNetwork::publish(const char *address, const char *message) {
  mqttClient.publish(address, message);
}

void EspNetwork::connect() {
  wiFi.connect();
  mqttClient.connectToMqtt();
}
