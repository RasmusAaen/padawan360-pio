#include <Arduino.h>
#include <Wire.h>
#include "I2C.h"

void i2c::sendMessage(byte address, char *message) {
  Wire.beginTransmission(address);
  Wire.write(message);
  Wire.endTransmission();
}
