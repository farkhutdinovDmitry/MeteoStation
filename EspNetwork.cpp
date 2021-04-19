#include "EspNetwork.h"

EspNetwork::EspNetwork(BrokerCredentials brokerCredentials,
                       WiFiCredentials wiFiCredentials) {
  wiFi(wiFiCredentials);
  mqttClient(&wiFi, brokerCredentials);
  wiFi.connect();
}
