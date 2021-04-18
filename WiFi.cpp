#include "WiFi.h"

WiFi::WiFi(WiFiCredentials credentials) : credentials(credentials) {
  isConnected = false;
  connectHandler = WiFi.onStationModeGotIP(onConnect);
  disconnectHandler = WiFi.onStationModeDisconnected(onDisconnect);
}

void WiFi::connect() {
  //
  WiFi.begin(credentials.ssid, credentials.password);
}

bool WiFi::isConnected() { return WiFi.isConnected(); }

void WiFi::onConnect(const WiFiEventStationModeGotIP &event) {
  // notify - how? pattern observer?
}

void WiFi::onDisconnect(const WiFiEventStationModeDisconnected &event) {
  reconnectTimer.once(2, connect);
}
