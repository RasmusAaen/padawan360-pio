#ifndef __I2C_H__
#define __I2C_H__

#include <Arduino.h>

class i2c {
  public:
    /**
     * Send a message over I2C to a device.
     * @param  address The I2C address of the device.
     * @param  command The message to send.
     */
    static void sendMessage(byte address, char *message);
};

#endif // __I2C_H__
