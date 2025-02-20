#ifndef __HOLOS_H__
#define __HOLOS_H__

#include <Arduino.h>

/**
 * Class to abstract the Holos functionality implemented in the BetterDuino firmware.
 * Communicates ovre I2C with the Dome Master MarcDuino
 *
 * @see https://github.com/RealNobser/BetterDuinoFirmwareV4
 */
class Holos {
public:
  enum holoid
  {
    ALL   = 0,
    FRONT = 1,
    REAR  = 2,
    TOP   = 3
  };

  /**
   * Random Holo movement.
   * @param  ::holoid The Holo ID.
   */
  static void random(holoid holoid);

  /**
   * Turns Holo Light on.
   * @param  ::holoid The Holo ID.
   */
  static void on(holoid holoid);

  /**
   * Turns Holo Light off.
   * @param  ::holoid The Holo ID.
   */
  static void off(holoid holoid);

  /**
   * Turns RGB Holo Light on.
   * @param  ::holoid The Holo ID.
   * @param  r Red value (0-255).
   * @param  g Green value (0-255).
   * @param  b Blue value (0-255).
   * @param  brightness Brightness value (0-255).
   */
  static void colorOn(holoid holoid, byte r, byte g, byte b, byte brightness);

  /**
   * Sets RGB Holo Light color.
   * @param  ::holoid The Holo ID.
   * @param  r Red value (0-255).
   * @param  g Green value (0-255).
   * @param  b Blue value (0-255).
   * @param  brightness Brightness value (0-255).
   */
  static void setColor(holoid holoid, byte r, byte g, byte b, byte brightness);

  /**
   * Holo vertical movement under RC control, horizontal centered
   * @param  ::holoid The Holo ID.
   */
  static void verticalMovement(holoid holoid);

  /**
   * Holo movement test. Goes through a loop of holo movements to assist in adjusting holo servos mechanical setup.
   * @param  ::holoid The Holo ID.
   */
  static void test(holoid holoid);

  /**
   * stop/reset Holos random movement, turns lights off, and RC off.
   * @param  ::holoid The Holo ID.
   */
  static void stop(holoid holoid);

  /**
   * hold: stop holo, do not change light level.
   * @param  ::holoid The Holo ID.
   */
  static void hold(holoid holoid);

  /**
   * Turn on Holo for xx seconds. 0 is off, 99 is on forever
   * @param  ::holoid The Holo ID.
   * @param  time Time in seconds.
   */
  static void timerOn(holoid holoid, byte time);

  /**
   * Turn on RGB Holo for xx seconds. 0 is off, 99 is on forever
   * @param  ::holoid The Holo ID.
   * @param  time Time in seconds.
   * @param  r Red value (0-255).
   * @param  g Green value (0-255).
   * @param  b Blue value (0-255).
   * @param  brightness Brightness value (0-255).
   */
  static void timerOnColor(holoid holoid, byte time, byte r, byte g, byte b, byte brightness);

  /**
   * Flicker Holo for xx seconds. 0 is off, 99 is on forever
   * @param  ::holoid The Holo ID.
   * @param  time Time in seconds.
   */
  static void flicker(holoid holoid, byte time);

  /**
   * Flicker RGB Holo for xx seconds. 0 is off, 99 is on forever
   * @param  ::holoid The Holo ID.
   * @param  time Time in seconds.
   * @param  r Red value (0-255).
   * @param  g Green value (0-255).
   * @param  b Blue value (0-255).
   * @param  brightness Brightness value (0-255).
   */
  static void flickerColor(holoid holoid, byte time, byte r, byte g, byte b, byte brightness);

  /**
   * Center Holo
   * @param  ::holoid The Holo ID.
   */
  static void center(holoid holoid);
};

#endif // __HOLOS_H__
