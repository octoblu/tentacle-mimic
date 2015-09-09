#include "mimic.h"
#include <stdio.h>

#define server "tentacle.octoblu.com"
#define port 80

static const char uuid[]  = "ec1a3aa1-e5a0-4134-ab49-1bdac08b8616";
static const char token[] = "09fee3756f02154bb388b81b4c43cca263015085";

void connectToServer();

int main (int argc, char *argv[])
{
  StdioStream stdioStream;
  TentacleArduino tentacle;
  Pseudopod pseudopod(stdioStream, stdioStream, tentacle);

  connectToServer();

  std::cout << "Hello World " << stdioStream.available();
  return 0;
}

void connectToServer() {
  // int connectionAttempts = 0;
  // Serial.println(F("Connecting to the server."));
  // Serial.flush();
  //
  // while(!conn.connect(server, port)) {
  //   Serial.println(F("Can't connect to the server."));
  //   Serial.flush();
  //   conn.stop();
  //   connectionAttempts++;
  // }
  //
  // size_t authSize = pseudopod.authenticate(uuid, token);
  // Serial.print(authSize);
  // Serial.println(F(" bytes written for authentication"));
}
