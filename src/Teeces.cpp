#include "Teeces.h"
#include "config.h"
#include "I2C.h"

#include <Arduino.h>

void Teeces::test(displayid display)
{
  char msg[6];
  snprintf(msg, sizeof(msg), "@%dT0\r", display);
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::off(displayid display)
{
  char msg[7];
  snprintf(msg, sizeof(msg), "@%dT20\r", display);
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::random(displayid display)
{
  char msg[6];
  snprintf(msg, sizeof(msg), "@%dT1\r", display);
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::alarm()
{
  char msg[6] = "@0T3\r";
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::shortCircuit()
{
  char msg[6] = "@0T4\r";
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::scream()
{
  char msg[6] = "@0T5\r";
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::leia()
{
  char msg[6] = "@0T6\r";
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::starWars()
{
  char msg[7] = "@0T10\r";
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::march()
{
  char msg[7] = "@0T11\r";
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::bargraph(displayid display)
{
  if((display < 0) || (display > 3)) {
    return;
  }
  char msg[7];
  snprintf(msg, sizeof(msg), "@%dT92\r", display);
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::displayText(displayid display, char *text)
{
  if((display < 0) || (display > 3)) {
    return;
  }
  char msg[sizeof(text)+5];

  snprintf(msg, sizeof(msg), "@%dM%s\r", display, text);
  i2c::sendMessage(I2C_TEECES, msg);

  snprintf(msg, sizeof(msg), "@%dT100\r", display);
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::setLanguage(displayid display, language language)
{
  char msg[6];
  snprintf(msg, sizeof(msg), "@%dT%d\r", display, language);
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::setRandomApperance(displayid display, byte type)
{
  if((display < 0) || (display > 3)) {
    return;
  }
  char msg[6];
  snprintf(msg, sizeof(msg), "@%dR%d\r", display, type);
  i2c::sendMessage(I2C_TEECES, msg);
}

void Teeces::setPSIstate(displayid display, psistate state)
{
  if((display != 0) && (display != 4) && (display != 5)) {
    return;
  }
  char msg[6];
  snprintf(msg, sizeof(msg), "@%dS%d\r", display, state);
  i2c::sendMessage(I2C_TEECES, msg);
}
