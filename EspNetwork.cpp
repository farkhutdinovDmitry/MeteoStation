#include "EspNetwork.h"

EspNetwork::EspNetwork(BrokerCredentials brokerCredentials,
                       WiFiCredentials wiFiCredentials)
    : mqttClient(brokerCredentials), wiFi(wiFiCredentials) {}
