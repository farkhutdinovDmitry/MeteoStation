#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H

// include mqtt environment

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

class MqttClient {
public:
  MqttClient(BrokerCredentials &credentials);
  void connect();

private:
  BrokerCredentials credentials;
  AsyncMqttClient mqttClient;

  void onMqttConnect(bool sessionPresent);
  void onMqttDisconnect(AsyncMqttClientDisconnectReason reason);
};

#endif // MQTTCLIENT_H
