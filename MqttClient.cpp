#include "MqttClient.h"

MqttClient::MqttClient(BrokerCredentials &credentials)
    : credentials(credentials) {
  mqttClient.onConnect(onMqttConnect);
  mqttClient.onDisconnect(onMqttDisconnect);
  mqttClient.setServer(credentials.host, credentials.port);
}

void MqttClient::connect() { mqttClient.connect(); }

void MqttClient::onMqttConnect(bool sessionPresent) {}

void MqttClient::onMqttDisconnect(AsyncMqttClientDisconnectReason reason) {}
