#include <Arduino.h>
#include "config.h"
#include "I2C.h"
#include "Player.h"

void Player::play(byte bank, byte track) {
  char msg[6];
  snprintf(msg, sizeof(msg), "$%d%02d\r", bank, track);
  i2c::sendMessage(I2C_MP3, msg);
}

void Player::playRandom() {
  char msg[4];
  snprintf(msg, sizeof(msg), "$R\r", (int)random(1,5), (int)random(1,11));
  i2c::sendMessage(I2C_MP3, msg);
}

void Player::playRandom(byte bank, byte trackMin, byte trackMax) {
  // play a random sound
  char msg[6];
  snprintf(msg, sizeof(msg), "$%d%02d\r", bank, (int)random(trackMin,trackMax+1));
  i2c::sendMessage(I2C_MP3, msg);
}

void Player::off() {
  i2c::sendMessage(I2C_MP3, "$O\r");
}

void Player::playLeia() {
  i2c::sendMessage(I2C_MP3, "$L\r");
}

void Player::playCantina() {
  i2c::sendMessage(I2C_MP3, "$C\r");
}

void Player::playCantinaBeep() {
  i2c::sendMessage(I2C_MP3, "$c\r");
}

void Player::playScream() {
  i2c::sendMessage(I2C_MP3, "$S\r");
}

void Player::playShortCircuit() {
  i2c::sendMessage(I2C_MP3, "$F\r");
}

void Player::playDisco() {
  i2c::sendMessage(I2C_MP3, "$D\r");
}

void Player::stop() {
  i2c::sendMessage(I2C_MP3, "$s\r");
}

void Player::volumeUp() {
  i2c::sendMessage(I2C_MP3, "$V+\r");
}

void Player::volumeDown() {
  i2c::sendMessage(I2C_MP3, "$V-\r");
}

void Player::volumeMid() {
  i2c::sendMessage(I2C_MP3, "$m\r");
}

void Player::volumeMax() {
  i2c::sendMessage(I2C_MP3, "$f\r");
}

void Player::volumeMin() {
  i2c::sendMessage(I2C_MP3, "$p\r");
}

void Player::playStarWars() {
  i2c::sendMessage(I2C_MP3, "$W\r");
}

void Player::playStarWarsBeep() {
  i2c::sendMessage(I2C_MP3, "$w\r");
}

void Player::playMarch() {
  i2c::sendMessage(I2C_MP3, "$M\r");
}

void Player::playMarchBeep() {
  i2c::sendMessage(I2C_MP3, "$i\r");
}

void Player::playStartup() {
  i2c::sendMessage(I2C_MP3, "$B\r");
}
