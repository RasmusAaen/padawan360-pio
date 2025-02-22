#ifndef __PANELS_H__
#define __PANELS_H__

#include <Arduino.h>

/**
 * Class to abstract the Pie panel functionality implemented in the BetterDuino firmware.
 * Communicates over I2C with the Dome Master MarcDuino
 *
 * @see https://github.com/RealNobser/BetterDuinoFirmwareV4
 */
class Panels {
  public:
    /**
     * launches sequences
     * @param  sequence The sequence number.
     */
    static void sequence(byte sequence);

    /**
     * open panel.
     *     0 = all panels
     *  1-13 = specific panel
     *    14 = all top panels
     *    15 = all bottom panels
     */
    static void open(byte panel);

    /**
     * close panel.
     *     0 = all panels
     *  1-13 = specific panel
     */
    static void close(byte panel);

    /**
     * Lock panel. Lock current position to avoid problems with DomeLift.
     *     0 = all panels
     *  1-13 = specific panel
     */
    static void lock(byte panel);

    /**
     * Unlock panel.
     *     0 = all panels
     *  1-13 = specific panel
     */
    static void unlock(byte panel);

    /**
     * Activate dome lift.
     * Toggle functionality, if lift is up when command is sent, it will be lowered and vice versa.
     *     0 = all dome lifts
     *  1-13 = specific lift
     */
    static void lift(byte panel);

    /**
     * places panel under RC input control.
     *     0 = all panels
     *  1-13 = specific panel
     */
    static void rc(byte panel);

    /**
     * buzz kill/soft hold: removes panel from RC control AND shuts servo off to eliminate buzz
     *     0 = all panels
     *  1-13 = specific panel
     */
    static void stop(byte panel);

    /**
     * RC hold: removes from RC, but does not turn servo off, keeps at last position
     *     0 = all panels
     *  1-13 = specific panel
     */
    static void hold(byte panel);

    /**
     * move panel to position.
     * @param  panel The panel number.
     * @param  position The position. 0-180 deg. values greater than 0544 are Microseconds
     */
    static void move(byte panel, int position);
};
#endif // __PIES_H__
