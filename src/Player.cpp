#include <Arduino.h>
#include "Config.h"
#include "I2C.h"
#include "Player.h"

void Player::play(byte bank, byte track) {
  char msg[8];
  snprintf(msg, sizeof(msg), "$%i%i\r", bank, track);
  i2c::sendMessage(I2C_MP3, msg);
}

void Player::playRandom(byte bank, byte trackMin, byte trackMax) {
  // play a random sound
  char msg[8];
  snprintf(msg, sizeof(msg), "$%i%i\r", bank, (int)random(trackMin,trackMax+1));
  i2c::sendMessage(I2C_MP3, msg);
}

void Player::volumeUp() {
  char msg[8] = "$V+\r";
  i2c::sendMessage(I2C_MP3, msg);
}

void Player::volumeDown() {
  char msg[8] = "$V-\r";
  i2c::sendMessage(I2C_MP3, msg);
}
