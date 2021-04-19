#ifndef WIFI_H
#define WIFI_H

//#include wifi environment
#include "WiFiObserver.h"
#include <vector>

struct WiFiCredentials {
  const char *ssid;
  const char *password;

  WiFiCredentials(const char *ssid, const char *password)
      : ssid(ssid), password(password) {}
};

class WiFi {
public:
  WiFi(WiFiCredentials credentials);
  void connect();
  bool isConnected();

  void addObserver(WiFiObserver *observer);

private:
  WiFiCredentials credentials;
  std::vector<WiFiObserver *> observers;

  Ticker reconnectTimer;
  WiFiEventHandler connectHandler;
  WiFiEventHandler disconnectHandler;

  void onConnect(const WiFiEventStationModeGotIP &event);
  void onDisconnect(const WiFiEventStationModeDisconnected &event);
};

#endif // WIFI_H
