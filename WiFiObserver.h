#ifndef WIFIOBSERVER_H
#define WIFIOBSERVER_H

class WiFiObserver {
public:
  virtual void onWiFiConnect() = 0;
  virtual void onWiFiDisconnect() = 0;
};

#endif // WIFIOBSERVER_H
