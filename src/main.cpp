#include <Arduino.h>
#include <Wire.h>
#include <Sabertooth.h>
#include <XBOXRECV.h>

#include "config.h"
#include "Player.h"
#include "Holos.h"
#include "Teeces.h"

//initialize motor controllers
Sabertooth Sabertooth2x(128, Serial1);
Sabertooth Syren10(128, Serial2);

//initialize XBox controller
USB Usb;
XBOXRECV Xbox(&Usb);

// Set some defaults for start up
// false = drive motors off ( left stick disabled ) at start
boolean isDriveEnabled = false;

// Automated functionality
// Used as a boolean to turn on/off automated functions like periodic random sounds and periodic dome turns
boolean isInAutomationMode = false;
unsigned long automateMillis = 0;
// Action number used to randomly choose a sound effect or a dome turn
byte automateAction = 0;
// set automateDelay to min and max seconds between sounds
byte automateDelay = random(5, 20);
//How much the dome may turn during automation.
int turnDirection = 20;

int driveThrottle = 0;
int domeThrottle = 0;
int turnThrottle = 0;
int throttleStickValue = 0;
int drivespeed = DRIVESPEED1;

boolean firstLoadOnConnect = false;

boolean isHPOn = false;

// Controller LEDs will go back to random blinking after some time so we need to re-set them periodically
unsigned long ledTimerMillis = 0;
void setControllerLEDs();

void setup() {
  Serial1.begin(SABERTOOTHBAUDRATE);
  Serial2.begin(DOMEBAUDRATE);

  Syren10.autobaud();
  Sabertooth2x.autobaud();

  // The Sabertooth won't act on mixed mode packet serial commands until
  // it has received power levels for BOTH throttle and turning, since it
  // mixes the two together to get diff-drive power levels for both motors.
  Sabertooth2x.drive(0);
  Sabertooth2x.turn(0);

  Sabertooth2x.setTimeout(950);
  Syren10.setTimeout(950);

  // Start I2C Bus.
  Wire.begin();

  if (Usb.Init() == -1) {
    while (1); //halt
  }
}

void loop() {
  Usb.Task();

  // if we're not connected, return so we don't bother doing anything else.
  // set all movement to 0 so if we lose connection we don't have a runaway droid!
  // a restraining bolt and jawa droid caller won't save us here!
  if (!Xbox.XboxReceiverConnected || !Xbox.Xbox360Connected[0]) {
    Sabertooth2x.drive(0);
    Sabertooth2x.turn(0);
    Syren10.motor(1, 0);
    firstLoadOnConnect = false;
    return;
  }

  // After the controller connects, Blink all the LEDs so we know drives are disengaged at start
  if (!firstLoadOnConnect) {
    firstLoadOnConnect = true;
    Player::play(1,10);
    //player.playSpecified(21);
    Xbox.setLedMode(SLOWBLINK, 0);
  }

  if (Xbox.getButtonClick(XBOX, 0)) {
    if(Xbox.getButtonPress(LB, 0) && Xbox.getButtonPress(LT, 0)){
      Xbox.disconnect(0);
    }
  }

  // The controller will start randomly blinking the LEDs after some time
  // To avoid this, we need to set the LEDs to the required state every second
  unsigned long now = millis();
  if(now - ledTimerMillis > 1000) {
    ledTimerMillis = now;
    setControllerLEDs();
  }

  // enable / disable right stick (droid movement) & play a sound to signal motor state
  if (Xbox.getButtonClick(START, 0)) {
    if (isDriveEnabled) {
      isDriveEnabled = false;
      setControllerLEDs();
//      Xbox.setLedMode(SLOWBLINK, 0);
      Player::play(1,21);
      //player.playSpecified(53);
    } else {
      isDriveEnabled = true;
      setControllerLEDs();
      Player::play(1,20);
      //player.playSpecified(52);
      // Set LED to indicate speed
      // if (drivespeed == DRIVESPEED1) {
      //   Xbox.setLedOn(LED1, 0);
      // } else if (drivespeed == DRIVESPEED2 && (DRIVESPEED3 != 0)) {
      //   Xbox.setLedOn(LED2, 0);
      // } else {
      //   Xbox.setLedOn(LED3, 0);
      // }
    }
  }

  //Toggle automation mode with the BACK button
  if (Xbox.getButtonClick(BACK, 0)) {
    if (isInAutomationMode) {
      isInAutomationMode = false;
      automateAction = 0;
      Player::play(1,21);
      //player.playSpecified(53);
    } else {
      isInAutomationMode = true;
      Player::play(1,20);
      //player.playSpecified(52);
    }
  }

  // Plays random sounds or dome movements for automations when in automation mode
  if (isInAutomationMode) {
    unsigned long currentMillis = millis();

    if (currentMillis - automateMillis > (automateDelay * 1000)) {
      automateMillis = millis();
      automateAction = random(1, 5);

      if (automateAction > 1) {
        Player::playRandom(1,1,19);
        //player.playSpecified(random(32, 52));
      }
      if (automateAction < 4) {
        Syren10.motor(1, turnDirection);

        delay(750);

        Syren10.motor(1, 0);

        if (turnDirection > 0) {
          turnDirection = -45;
        } else {
          turnDirection = 45;
        }
      }

      // sets the min, max seconds between automation actions - sounds and dome movement
      automateDelay = random(3,10);
    }
  }

  // Volume Control of MP3 Trigger
  // Hold LT and Press Up/down on D-pad to increase/decrease volume
  if (Xbox.getButtonClick(UP, 0)) {
    // volume up
    if (Xbox.getButtonPress(LT, 0)) {
      Player::volumeUp();
    }
  }
  if (Xbox.getButtonClick(DOWN, 0)) {
    //volume down
    if (Xbox.getButtonPress(LT, 0)) {
      Player::volumeDown();
    }
  }


  // Logic display brightness.
  // Hold LB and press up/down on dpad to increase/decrease brightness
  if (Xbox.getButtonClick(UP, 0)) {
    if (Xbox.getButtonPress(LB, 0)) {
      //triggerI2C(10, "24"); //RA: Can't find any logic in Teeces code to adjust logic display brightness...
    }
  }
  if (Xbox.getButtonClick(DOWN, 0)) {
    if (Xbox.getButtonPress(LB, 0)) {
      //triggerI2C(10, "25"); //RA: Can't find any logic in Teeces code to adjust logic display brightness...
    }
  }

  // GENERAL SOUND PLAYBACK AND DISPLAY CHANGING

  // Y Button and Y combo buttons
  if (Xbox.getButtonClick(Y, 0)) {
    if (Xbox.getButtonPress(LB, 0)) {
      Player::play(2,11);
      //player.playSpecified(8);
      Teeces::random(Teeces::ALL);

    } else if (Xbox.getButtonPress(LT, 0)) {
      Player::play(2,6);
      //player.playSpecified(2);
      Teeces::random(Teeces::ALL);
    } else if (Xbox.getButtonPress(LT, 0)) {
      Player::play(8,2);
      //player.playSpecified(9);
      Teeces::random(Teeces::ALL);
    } else {
      Player::playRandom(1,1,19);
      //player.playSpecified(random(13, 17));
      Teeces::random(Teeces::ALL);
    }
  }

  // A Button and A combo Buttons
  if (Xbox.getButtonClick(A, 0)) {
    if (Xbox.getButtonPress(LB, 0)) {
      Player::playShortCircuit();
      Teeces::shortCircuit();
      Holos::flicker(Holos::ALL, ShortCircuitDuration);
    } else if (Xbox.getButtonPress(LT, 0)) {
      Player::playScream();
      Teeces::alarm();
      Holos::flicker(Holos::ALL, AlarmDuration);
    } else if (Xbox.getButtonPress(LT, 0)) {
      Player::playMarch();
      Teeces::march();
    } else {
      Player::playRandom();
      Teeces::random(Teeces::ALL);
    }
  }

  // B Button and B combo Buttons
  if (Xbox.getButtonClick(B, 0)) {
    if (Xbox.getButtonPress(LB, 0)) {
      Player::play(1,12);
      //player.playSpecified(7);
      Teeces::random(Teeces::ALL);
    } else if (Xbox.getButtonPress(LT, 0)) {
      Player::play(3,1);
      //player.playSpecified(3);
      Teeces::random(Teeces::ALL);
    } else if (Xbox.getButtonPress(LT, 0)) {
      Player::playDisco();
      Teeces::bargraph(Teeces::ALL);
      Holos::flicker(Holos::ALL, CantinaDuration);
    } else {
      Player::playRandom();
      Teeces::random(Teeces::ALL);
    }
  }

  // X Button and X combo Buttons
  if (Xbox.getButtonClick(X, 0)) {
    // leia message LB+X
    if (Xbox.getButtonPress(LB, 0)) {
      Player::playLeia();
      Teeces::leia();
      Holos::flicker(Holos::FRONT, LeiaDuration);
    } else if (Xbox.getButtonPress(LT, 0)) {
      Player::play(6,2);
      //player.playSpecified(4);
      Teeces::shortCircuit();
    } else if (Xbox.getButtonPress(LT, 0)) {
      Player::play(8,1);
      //player.playSpecified(12);
      Teeces::random(Teeces::ALL);
    } else {
      Player::playRandom(3,1,8);
      //player.playSpecified(random(25, 32));
      Teeces::random(Teeces::ALL);
    }
  }

  // turn hp light on & off with Right Analog Stick Press (R3) for left stick drive mode
  // turn hp light on & off with Left Analog Stick Press (L3) for right stick drive mode
  if (Xbox.getButtonClick(R3, 0))  {
    // if hp light is on, turn it off
    if (isHPOn) {
      isHPOn = false;
      Holos::off(Holos::FRONT);
    } else {
      isHPOn = true;
      Holos::on(Holos::FRONT);
    }
  }

  // Change drivespeed if drive is enabled
  // Press Left Analog Stick (L3) for left stick drive mode
  // Press Right Analog Stick (R3) for right stick drive mode
  // Set LEDs for speed - 1 LED, Low. 2 LED - Med. 3 LED High
  if (Xbox.getButtonClick(L3, 0) && isDriveEnabled) {
    //if in lowest speed
    if (drivespeed == DRIVESPEED1) {
      //change to medium speed and play sound 3-tone
      drivespeed = DRIVESPEED2;
      Xbox.setLedOn(LED2, 0);
      Player::play(1,21);
      //player.playSpecified(53);
      Teeces::displayText(Teeces::ALL, (char*)"SPEED 2");
    } else if (drivespeed == DRIVESPEED2 && (DRIVESPEED3 != 0)) {
      //change to high speed and play sound scream
      drivespeed = DRIVESPEED3;
      Xbox.setLedOn(LED3, 0);
      Player::play(6,1);
      //player.playSpecified(1);
      Teeces::displayText(Teeces::ALL, (char*)"SPEED 3");
    } else {
      //we must be in high speed
      //change to low speed and play sound 2-tone
      drivespeed = DRIVESPEED1;
      Xbox.setLedOn(LED1, 0);
      Player::play(1,20);
      //player.playSpecified(52);
      Teeces::displayText(Teeces::ALL, (char*)"SPEED 1");
    }
  }

  // FOOT DRIVES
  // Xbox 360 analog stick values are signed 16 bit integer value
  // Sabertooth runs at 8 bit signed. -127 to 127 for speed (full speed reverse and  full speed forward)
  // Map the 360 stick values to our min/max current drive speed
  throttleStickValue = (map(Xbox.getAnalogHat(LeftHatY, 0), -32768, 32767, -drivespeed, drivespeed));
  if (throttleStickValue > -DRIVEDEADZONERANGE && throttleStickValue < DRIVEDEADZONERANGE) {
    // stick is in dead zone - don't drive
    driveThrottle = 0;
  } else {
    if (driveThrottle < throttleStickValue) {
      if (throttleStickValue - driveThrottle < (RAMPING + 1) ) {
        driveThrottle += RAMPING;
      } else {
        driveThrottle = throttleStickValue;
      }
    } else if (driveThrottle > throttleStickValue) {
      if (driveThrottle - throttleStickValue < (RAMPING + 1) ) {
        driveThrottle -= RAMPING;
      } else {
        driveThrottle = throttleStickValue;
      }
    }
  }

  turnThrottle = map(Xbox.getAnalogHat(LeftHatX, 0), -32768, 32767, -TURNSPEED, TURNSPEED);

  // DRIVE!
  // right stick (drive)
  if (isDriveEnabled) {
    // Only do deadzone check for turning here. Our Drive throttle speed has some math applied
    // for RAMPING and stuff, so just keep it separate here
    if (turnThrottle > -DRIVEDEADZONERANGE && turnThrottle < DRIVEDEADZONERANGE) {
      // stick is in dead zone - don't turn
      turnThrottle = 0;
    }
    Sabertooth2x.turn(-turnThrottle);
    Sabertooth2x.drive(driveThrottle);
  }

  // DOME DRIVE!
  domeThrottle = (map(Xbox.getAnalogHat(RightHatX, 0), -32768, 32767, DOMESPEED, -DOMESPEED));
  if (domeThrottle > -DOMEDEADZONERANGE && domeThrottle < DOMEDEADZONERANGE) {
    //stick in dead zone - don't spin dome
    domeThrottle = 0;
  }
  Syren10.motor(1, domeThrottle);
}

void setControllerLEDs() {
  if(isDriveEnabled) {
    if (drivespeed == DRIVESPEED1) {
      Xbox.setLedOn(LED1, 0);
    } else if (drivespeed == DRIVESPEED2 && (DRIVESPEED3 != 0)) {
      Xbox.setLedOn(LED2, 0);
    } else {
      Xbox.setLedOn(LED3, 0);
    }
  } else {
    Xbox.setLedMode(SLOWBLINK, 0);
  }
}
