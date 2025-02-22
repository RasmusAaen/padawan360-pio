#include "Teeces.h"
#include "Config.h"
#include "I2C.h"

#include <Arduino.h>

void Teeces::test(displayid display)
{
  char msg[8];
  snprintf(msg, sizeof(msg), "@%iT0\r", display);
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::off(displayid display)
{
  char msg[8];
  snprintf(msg, sizeof(msg), "@%iT20\r", display);
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::random(displayid display)
{
  char msg[8];
  snprintf(msg, sizeof(msg), "@%iT1\r", display);
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::alarm()
{
  char msg[8] = "@0T3\r";
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::shortCircuit()
{
  char msg[8] = "@0T4\r";
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::scream()
{
  char msg[8] = "@0T5\r";
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::leia()
{
  char msg[8] = "@0T6\r";
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::starWars()
{
  char msg[8] = "@0T10\r";
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::march()
{
  char msg[8] = "@0T11\r";
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::bargraph(displayid display)
{
  if((display < 0) || (display > 3)) {
    return;
  }
  char msg[8];
  snprintf(msg, sizeof(msg), "@%iT92\r", display);
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::displayText(displayid display, char *text)
{
  if((display < 0) || (display > 3)) {
    return;
  }
  char msg[sizeof(text)];

  snprintf(msg, sizeof(msg), "@%iM%s\r", display, text);
  i2c::sendMessage(I2C_TEECES, msg);

  snprintf(msg, sizeof(msg), "@%iT100\r", display);
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::setLanguage(displayid display, language language)
{
  char msg[8];
  snprintf(msg, sizeof(msg), "@%iT%d\r", display, language);
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::setRandomApperance(displayid display, byte type)
{
  if((display < 0) || (display > 3)) {
    return;
  }
  char msg[8];
  snprintf(msg, sizeof(msg), "@%iR%d\r", display, type);
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::setPSIstate(displayid display, psistate state)
{
  if((display != 0) && (display != 4) && (display != 5)) {
    return;
  }
  char msg[8];
  snprintf(msg, sizeof(msg), "@%iS%d\r", display, state);
  i2c::sendMessage(I2C_TEECES, msg);
}
