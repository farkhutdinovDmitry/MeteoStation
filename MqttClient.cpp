#include "MqttClient.h"

MqttClient::MqttClient(WiFi *wiFi_, BrokerCredentials &credentials)
    : wiFi(wiFi_), credentials(credentials) {
  mqttClient.onConnect(onMqttConnect);
  mqttClient.onDisconnect(onMqttDisconnect);
  mqttClient.setServer(credentials.host, credentials.port);
  wiFi->addObserver(this);
}

void MqttClient::publish(const char *address, const char *message) {
  mqttClient.publish(address, 1, true, message);
}

void MqttClient::connectToMqtt() { mqttClient.connect(); }

void MqttClient::onWiFiConnect() { connectToMqtt(); }

void MqttClient::onWiFiDisconnect() { mqttReconnectTimer.detach(); }

void MqttClient::onMqttConnect(bool sessionPresent) {}

void MqttClient::onMqttDisconnect(AsyncMqttClientDisconnectReason reason) {
  if (wiFi->isConnected()) {
    mqttReconnectTimer.once(2, connectToMqtt);
  }
}
