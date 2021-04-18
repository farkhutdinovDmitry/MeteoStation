#ifndef WIFI_H
#define WIFI_H

//#include wifi environment

struct WiFiCredentials {
  const char *ssid;
  const char *password;

  WiFiCredentials(const char *ssid, const char *password)
      : ssid(ssid), password(password) {}
};

class WiFi {
public:
  WiFi(WiFiCredentials credentials);

private:
  WiFiCredentials credentials;
  bool isConnected;

  Ticker reconnectTimer;
  WiFiEventHandler connectHandler;
  WiFiEventHandler disconnectHandler;

  void onConnect(const WiFiEventStationModeGotIP &event);
  void onDisconnect(const WiFiEventStationModeDisconnected &event);
};

#endif // WIFI_H
