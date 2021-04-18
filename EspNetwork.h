#ifndef ESPNETWORK_H
#define ESPNETWORK_H

#include "MqttClient.h"
#include "WiFi.h"

class EspNetwork {
public:
  EspNetwork(BrokerCredentials brokerCredentials,
             WiFiCredentials wiFiCredentials);

private:
  MqttClient mqttClient;
  WiFi wiFi;
};

#endif // ESPNETWORK_H
