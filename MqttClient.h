#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H

// include mqtt environment
#include "WiFi.h"
#include "WiFiObserver.h"

struct BrokerCredentials {
  const char *host;
  const int port;

  const char *login;
  const char *password;

  BrokerCredentials(const char *host, const int port)
      : host(host), port(port) {}

  BrokerCredentials(const char *host, const int port, const char *login,
                    const char *password)
      : BrokerCredentials(host, port) {
    this->login = login;
    this->password = password;
  }
};

class MqttClient : public WiFiObserver {
public:
  MqttClient(WiFi *wiFi_, BrokerCredentials &credentials);
  void publish(const char *address, const char *message);
  void connectToMqtt();
  void onWiFiConnect() override;
  void onWiFiDisconnect() override;

private:
  WiFi *wiFi;
  BrokerCredentials credentials;
  AsyncMqttClient mqttClient;
  Ticker mqttReconnectTimer;

  void onMqttConnect(bool sessionPresent);
  void onMqttDisconnect(AsyncMqttClientDisconnectReason reason);
};

#endif // MQTTCLIENT_H
