#include "WiFi.h"

WiFi::WiFi(WiFiCredentials credentials) : credentials(credentials) {
  connectHandler = WiFi.onStationModeGotIP(onConnect);
  disconnectHandler = WiFi.onStationModeDisconnected(onDisconnect);
}

void WiFi::addObserver(WiFiObserver *observer) {
  observers.push_back(observer);
}

void WiFi::connect() {
  //
  WiFi.begin(credentials.ssid, credentials.password);
}

bool WiFi::isConnected() { return WiFi.isConnected(); }

void WiFi::onConnect(const WiFiEventStationModeGotIP &event) {
  for (auto observer : observers) {
    observer->onWiFiConnect();
  }
}

void WiFi::onDisconnect(const WiFiEventStationModeDisconnected &event) {
  for (auto observer : observers) {
    observer->onWiFiDisconnect();
  }
  reconnectTimer.once(2, connect);
}
