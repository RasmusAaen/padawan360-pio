#ifndef __TEECES_H__
#define __TEECES_H__

#include <Arduino.h>

/**
 * Class to abstract the Teeces functionality implemented in the BetterDuino firmware.
 * Communicates over I2C with the Dome Master MarcDuino which forwards the messages over serial to the Teeces board.
 *
 * @see Teeces source code
 */
class Teeces
{
public:
  /**
   * The different Teeces displays
   */
  enum displayid
  {
    ALL  = 0,
    TFLD = 1,
    BFLD = 2,
    RLD  = 3,
    FPSI = 4,
    RPSI = 5
  };

  /**
   * The different languages the Teeces displays can show
   */
  enum language
  {
    LATIN    = 0,
    AURABESH = 1
  };

  /**
   * The different states the PSI display can be in
   */
  enum psistate
  {
    ON          = 0,
    NORMAL      = 1,
    FIRSTCOLOR  = 2,
    SECONDCOLOR = 3,
    OFF         = 4
  };

  /**
   * Test the Teeces display. Turns all LEDs on.
   * @param  ::displayid The display ID.
   */
  static void test(displayid display);

  /**
   * Turn the Teeces display off.
   * @param  ::displayid The display ID.
   */
  static void off(displayid display);

  /**
   * Set display to normal random state.
   * @param  ::displayid The display ID.
   */
  static void random(displayid display);

  /**
   * alarm for 4 seconds (flashes displays on and off)
   */
  static void alarm();

  /**
   * short circuit (10 seconds sequence)
   */
  static void shortCircuit();

  /**
   * scream, same as alarm
   */
  static void scream();

  /**
   * leia, 34 seconds (moving horizontal bar)
   */
  static void leia();

  /**
   * Star Wars. Displays "Star Wars" on RLD, "STARS" on TFLD, "WARS" on BFLD
   */
  static void starWars();

  /**
   * March (alternating halfs of logics, 47 seconds)
   */
  static void march();

  /**
   * spectrum, bargraph displays. Runs forever, reset by calling random()
   * @param  ::displayid The display ID.
   */
  static void bargraph(displayid display);

  /**
   * Text displays. Displays text on the specified display.
   * Only uppercase implemented
   * @param  ::displayid The display ID.
   * @param  text The text to display.
   */
  static void displayText(displayid display, char *text);

  /**
   * Switch between implemented languages
   * @param  ::displayid The display ID.
   * @param  ::language The language to display.
   */
  static void setLanguage(displayid display, language language);

  /**
   * Adjust random pattern for the specified display
   *
   * Styles 0 to 2 are for special effects (I used them in Failure)
   * Style 3 is legacy Teeces ("blocky random", about 50% off, most LED changing at a time)
   * Styles 4 and 5 are recommended, more organic random styles (not all LEDs change at the same time, more LEDs on)
   * Style 6 is most LEDs on (special effect).
   * 0= almost all off, 1= most off, 2= some off, 3= legacy random, 4= stage 1 organic, 5= stage 2 organic, 6 = stage 3 organic
   * @param  ::displayid The display ID.
   * @param  style The style of random pattern.
   */
  static void setRandomApperance(displayid display, byte style);

  /**
   * Set the PSI display state
   * @param  ::displayid The display ID.
   * @param  ::psistate The state of the PSI display.
   */
  static void setPSIstate(displayid display, psistate state);
};

#endif // __TEECES_H__
