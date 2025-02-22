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
  i2c::sendMessage(I2C_MP3, (char*)"$R\r");
}

void Player::playRandom(byte bank, byte trackMin, byte trackMax) {
  char msg[6];
  snprintf(msg, sizeof(msg), "$%d%02d\r", bank, (int)random(trackMin,trackMax+1));
  i2c::sendMessage(I2C_MP3, msg);
}

void Player::off() {
  i2c::sendMessage(I2C_MP3, (char*)"$O\r");
}

void Player::playLeia() {
  i2c::sendMessage(I2C_MP3, (char*)"$L\r");
}

void Player::playCantina() {
  i2c::sendMessage(I2C_MP3, (char*)"$C\r");
}

void Player::playCantinaBeep() {
  i2c::sendMessage(I2C_MP3, (char*)"$c\r");
}

void Player::playScream() {
  i2c::sendMessage(I2C_MP3, (char*)"$S\r");
}

void Player::playShortCircuit() {
  i2c::sendMessage(I2C_MP3, (char*)"$F\r");
}

void Player::playDisco() {
  i2c::sendMessage(I2C_MP3, (char*)"$D\r");
}

void Player::stop() {
  i2c::sendMessage(I2C_MP3, (char*)"$s\r");
}

void Player::volumeUp() {
  i2c::sendMessage(I2C_MP3, (char*)"$V+\r");
}

void Player::volumeDown() {
  i2c::sendMessage(I2C_MP3, (char*)"$V-\r");
}

void Player::volumeMid() {
  i2c::sendMessage(I2C_MP3, (char*)"$m\r");
}

void Player::volumeMax() {
  i2c::sendMessage(I2C_MP3, (char*)"$f\r");
}

void Player::volumeMin() {
  i2c::sendMessage(I2C_MP3, (char*)"$p\r");
}

void Player::playStarWars() {
  i2c::sendMessage(I2C_MP3, (char*)"$W\r");
}

void Player::playStarWarsBeep() {
  i2c::sendMessage(I2C_MP3, (char*)"$w\r");
}

void Player::playMarch() {
  i2c::sendMessage(I2C_MP3, (char*)"$M\r");
}

void Player::playMarchBeep() {
  i2c::sendMessage(I2C_MP3, (char*)"$i\r");
}

void Player::playStartup() {
  i2c::sendMessage(I2C_MP3, (char*)"$B\r");
}
