#ifndef ethernetserver_h
#define ethernetserver_h

#include "Server.h"

class EthernetClient;

class EthernetServer : 
public Server {
private:
  uint16_t _port;
  void accept();
  void init();
public:
  EthernetServer(uint16_t);
  EthernetClient available();
  // 20181016 https://kmpelectronics.eu/ Plamen Kovandjiev - We added support for ESP32.
#ifdef ESP32
  virtual void begin(uint16_t port = 0);
#else
  virtual void begin();
#endif
  virtual size_t write(uint8_t);
  virtual size_t write(const uint8_t *buf, size_t size);
  using Print::write;
};

#endif