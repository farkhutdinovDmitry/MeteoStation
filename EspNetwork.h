#ifndef ESPNETWORK_H
#define ESPNETWORK_H

#include "MqttClient.h"
#include "WiFi.h"

class EspNetwork {
public:
  EspNetwork(BrokerCredentials brokerCredentials,
             WiFiCredentials wiFiCredentials);
  void publish(const char *, const char *message);
  void connect();

private:
  MqttClient mqttClient;
  WiFi wiFi;
};

#endif // ESPNETWORK_H
