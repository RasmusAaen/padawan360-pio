#include <Arduino.h>
#include "Panels.h"
#include "config.h"
#include "I2C.h"

void Panels::sequence(byte sequence) {
  char msg[7];
  snprintf(msg, sizeof(msg), ":SE%02d\r", sequence);
  i2c::sendMessage(I2C_PANELS, msg);
}

void Panels::open(byte panel) {
  char msg[7];
  snprintf(msg, sizeof(msg), ":OP%02d\r", panel);
  i2c::sendMessage(I2C_PANELS, msg);
}

void Panels::close(byte panel) {
  char msg[7];
  snprintf(msg, sizeof(msg), ":CL%02d\r", panel);
  i2c::sendMessage(I2C_PANELS, msg);
}

void Panels::lock(byte panel) {
  char msg[7];
  snprintf(msg, sizeof(msg), ":LK%02d\r", panel);
  i2c::sendMessage(I2C_PANELS, msg);
}

void Panels::unlock(byte panel) {
  char msg[7];
  snprintf(msg, sizeof(msg), ":UL%02d\r", panel);
  i2c::sendMessage(I2C_PANELS, msg);
}

void Panels::lift(byte panel) {
  char msg[7];
  snprintf(msg, sizeof(msg), ":LI%02d\r", panel);
  i2c::sendMessage(I2C_PANELS, msg);
}

void Panels::rc(byte panel) {
  char msg[7];
  snprintf(msg, sizeof(msg), ":RC%02d\r", panel);
  i2c::sendMessage(I2C_PANELS, msg);
}

void Panels::stop(byte panel) {
  char msg[7];
  snprintf(msg, sizeof(msg), ":ST%02d\r", panel);
  i2c::sendMessage(I2C_PANELS, msg);
}

void Panels::hold(byte panel) {
  char msg[7];
  snprintf(msg, sizeof(msg), ":HD%02d\r", panel);
  i2c::sendMessage(I2C_PANELS, msg);
}

void Panels::move(byte panel, int position) {
  char msg[11];
  snprintf(msg, sizeof(msg), ":MV%02d%04d\r", panel, position);
  i2c::sendMessage(I2C_PANELS, msg);
}
