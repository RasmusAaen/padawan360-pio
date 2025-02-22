#include "Holos.h"
#include "config.h"
#include "I2C.h"

#include <Arduino.h>

void Holos::random(holoid holoid)
{
  char msg[7];
  snprintf(msg, sizeof(msg), "*RD%02d\r", holoid);
  i2c::sendMessage(I2C_HOLOS, msg);
}

void Holos::on(holoid holoid)
{
  char msg[7];
  snprintf(msg, sizeof(msg), "*ON%02d\r", holoid);
  i2c::sendMessage(I2C_HOLOS, msg);
}

void Holos::off(holoid holoid)
{
  char msg[7];
  snprintf(msg, sizeof(msg), "*OF%02d\r", holoid);
  i2c::sendMessage(I2C_HOLOS, msg);
}

void Holos::colorOn(holoid holoid, byte r, byte g, byte b, byte brightness)
{
  char msg[19];
  snprintf(msg, sizeof(msg), "*CO%02d%03d%03d%03d%03d\r", holoid, r, g, b, brightness);
  i2c::sendMessage(I2C_HOLOS, msg);
}

void Holos::setColor(holoid holoid, byte r, byte g, byte b, byte brightness)
{
  char msg[19];
  snprintf(msg, sizeof(msg), "*CL%02d%03d%03d%03d%03d\r", holoid, r, g, b, brightness);
  i2c::sendMessage(I2C_HOLOS, msg);
}

void Holos::verticalMovement(holoid holoid)
{
  char msg[7];
  snprintf(msg, sizeof(msg), "*RC%02d\r", holoid);
  i2c::sendMessage(I2C_HOLOS, msg);
}

void Holos::test(holoid holoid)
{
  char msg[7];
  snprintf(msg, sizeof(msg), "*TE%02d\r", holoid);
  i2c::sendMessage(I2C_HOLOS, msg);
}

void Holos::stop(holoid holoid)
{
  char msg[7];
  snprintf(msg, sizeof(msg), "*ST%02d\r", holoid);
  i2c::sendMessage(I2C_HOLOS, msg);
}

void Holos::hold(holoid holoid)
{
  char msg[7];
  snprintf(msg, sizeof(msg), "*HD%02d\r", holoid);
  i2c::sendMessage(I2C_HOLOS, msg);
}

void Holos::timerOn(holoid holoid, byte time)
{
  char msg[7];
  snprintf(msg, sizeof(msg), "*H%01d%02d\r", holoid, time);
  i2c::sendMessage(I2C_HOLOS, msg);
}

void Holos::timerOnColor(holoid holoid, byte time, byte r, byte g, byte b, byte brightness)
{
  char msg[21];
  snprintf(msg, sizeof(msg), "*H%01d%02d%03d%03d%03d%03d\r", holoid, time, r, g, b, brightness);
  i2c::sendMessage(I2C_HOLOS, msg);
}

void Holos::flicker(holoid holoid, byte time)
{
  char msg[7];
  snprintf(msg, sizeof(msg), "*F%01d%02d\r", holoid, time);
  i2c::sendMessage(I2C_HOLOS, msg);
}

void Holos::flickerColor(holoid holoid, byte time, byte r, byte g, byte b, byte brightness)
{
  char msg[21];
  snprintf(msg, sizeof(msg), "*F%01d%02d%03d%03d%03d%03d\r", holoid, time, r, g, b, brightness);
  i2c::sendMessage(I2C_HOLOS, msg);
}

void Holos::center(holoid holoid)
{
  char msg[7];
  snprintf(msg, sizeof(msg), "*CH%02d\r", holoid);
  i2c::sendMessage(I2C_HOLOS, msg);
}
