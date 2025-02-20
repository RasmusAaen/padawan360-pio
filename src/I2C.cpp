#include <Arduino.h>
#include <Wire.h>
#include "I2C.h"

void i2c::sendI2C(byte address, char *command) {
  Wire.beginTransmission(address);
  Wire.write(command);
  Wire.endTransmission();
}
