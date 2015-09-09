#ifndef STDIO_STREAM_H
#define STDIO_STREAM_H

#include "Stream.h"

class StdioStream : public Stream {
  public:
    int available();
    int read(){};
    int peek(){};
    void flush(){};
    // virtual void setTimeout(unsigned long timeout);

    bool find(char *target){};
    bool find(uint8_t *target){};

    bool find(char *target, size_t length){};
    bool find(uint8_t *target, size_t length){};

    // virtual bool findUntil(char *target, char *terminator){};
    // virtual bool findUntil(uint8_t *target, char *terminator) { return findUntil((char *)target, terminator){}; }
    //
    // virtual bool findUntil(char *target, size_t targetLen, char *terminate, size_t termLen){};
    // virtual bool findUntil(uint8_t *target, size_t targetLen, char *terminate, size_t termLen) {return findUntil((char *)target, targetLen, terminate, termLen){}; }
    //
    // virtual long parseInt(){};
    //
    // virtual float parseFloat(){};

    size_t readBytes( char *buffer, size_t length){};
    size_t readBytes( uint8_t *buffer, size_t length){};

    size_t write(const uint8_t *buffer, size_t size){};

    // virtual size_t readBytesUntil( char terminator, char *buffer, size_t length);
    // virtual size_t readBytesUntil( char terminator, uint8_t *buffer, size_t length) { return readBytesUntil(terminator, (char *)buffer, length); }
    //
    // virtual String readString();
    // virtual String readStringUntil(char terminator);};
};

#endif
