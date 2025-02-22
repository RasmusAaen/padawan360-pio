#include <Arduino.h>
#include "config.h"
#include "I2C.h"
#include "Player.h"

void Player::play(byte bank, byte track) {
  char msg[6];
  snprintf(msg, sizeof(msg), "$%d%02d\r", bank, track);
  i2c::sendMessage(I2C_MP3, msg);
}

void Player::playRandom(byte bank, byte trackMin, byte trackMax) {
  // play a random sound
  char msg[6];
  snprintf(msg, sizeof(msg), "$%d%02d\r", bank, (int)random(trackMin,trackMax+1));
  i2c::sendMessage(I2C_MP3, msg);
}

void Player::volumeUp() {
  char msg[5] = "$V+\r";
  i2c::sendMessage(I2C_MP3, msg);
}

void Player::volumeDown() {
  char msg[5] = "$V-\r";
  i2c::sendMessage(I2C_MP3, msg);
}
