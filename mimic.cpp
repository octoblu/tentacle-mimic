#include "mimic.h"
#include <stdio.h>

#define server "tentacle.octoblu.com"
#define port 80

static const char uuid[]  = "ec1a3aa1-e5a0-4134-ab49-1bdac08b8616";
static const char token[] = "09fee3756f02154bb388b81b4c43cca263015085";

int main (int argc, char *argv[])
{
  StdioStream myStream;
  std::cout << "Hello World " << myStream.getInt();
  return 0;
}
