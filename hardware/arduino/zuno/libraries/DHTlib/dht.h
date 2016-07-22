    //
//    FILE: dht.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.21
// PURPOSE: DHT Temperature & Humidity Sensor library for Arduino
//     URL: http://arduino.cc/playground/Main/DHTLib
//
// HISTORY:
// see dht.cpp file
//


// Adopted for Z-Uno.

#ifndef dht_h
#define dht_h

#include <Arduino.h>

#define DHT_LIB_VERSION "0.1.21"

#define DHTLIB_OK                       0
#define DHTLIB_ERROR_CHECKSUM           -1
#define DHTLIB_ERROR_TIMEOUT            -2
#define DHTLIB_ERROR_CONNECT            -3
#define DHTLIB_ERROR_ACK_L              -4
#define DHTLIB_ERROR_ACK_H              -5
#define DHTLIB_ERROR_NOT_ALLOWED_PIN    -6
#define DHTLIB_ERROR_ZUNO_PROBLEM       -7

#define DHTLIB_DHT11_WAKEUP         18
#define DHTLIB_DHT_WAKEUP           1

// max timeout is 100 usec.

class dht
{
public:
    dht() {};
    // return values:
    // DHTLIB_OK
    // DHTLIB_ERROR_CHECKSUM
    // DHTLIB_ERROR_TIMEOUT
    // DHTLIB_ERROR_CONNECT
    // DHTLIB_ERROR_ACK_L
    // DHTLIB_ERROR_ACK_H
    int8_t read11(uint8_t pin);
    int8_t read(uint8_t pin);

    inline int8_t read21(uint8_t pin) { return read(pin); };
    inline int8_t read22(uint8_t pin) { return read(pin); };
    inline int8_t read33(uint8_t pin) { return read(pin); };
    inline int8_t read44(uint8_t pin) { return read(pin); };

    int humidity;
    int temperature;

private:
    uint8_t bits[5];  // buffer to receive data
    int8_t _readSensor(uint8_t pin, uint8_t wakeupDelay);
};
#endif
//
// END OF FILE
//