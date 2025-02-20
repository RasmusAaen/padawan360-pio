#ifndef __CONFIG_H__
#define __CONFIG_H__

// Drive speed
// Recommend beginner: 50 to 75, experienced: 100 to 127, I like 100.
// These may vary based on your drive system and power system
#define DRIVESPEED1  50
#define DRIVESPEED2 100
#define DRIVESPEED3 127

// Turn speed
// the higher this number the faster the droid will spin in place, lower - easier to control.
// Recommend beginner: 40 to 50, experienced: 50 $ up, I like 70
// This may vary based on your drive system and power system
#define TURNSPEED 70

#define LEFTSTICKDRIVE true

// If using a speed controller for the dome, sets the top speed. You'll want to vary it potentially
// depending on your motor. My Pittman is really fast so I dial this down a ways from top speed.
// Use a number up to 127 for serial
#define DOMESPEED 110

// Ramping- the lower this number the longer R2 will take to speedup or slow down,
// change this by increments of 1
#define RAMPING 5

// Compensation is for deadband/deadzone checking. There's a little play in the neutral zone
// which gets a reading of a value of something other than 0 when you're not moving the stick.
// It may vary a bit across controllers and how broken in they are, sometimes 360 controllers
// develop a little bit of play in the stick at the center position. You can do this with the
// direct method calls against the Syren/Sabertooth library itself but it's not supported in all
// serial modes so just manage and check it in software here
// use the lowest number with no drift
// DOMEDEADZONERANGE for the left stick, DRIVEDEADZONERANGE for the right stick
#define DOMEDEADZONERANGE  20
#define DRIVEDEADZONERANGE 20

// Set the baudrate for the Sabertooth motor controller (feet)
// 9600 is the default baud rate for Sabertooth packet serial.
// for packetized options are: 2400, 9600, 19200 and 38400. I think you need to pick one that works
// and I think it varies across different firmware versions.
#define SABERTOOTHBAUDRATE 9600

// Set the baudrate for the Syren motor controller (dome)
// for packetized options are: 2400, 9600, 19200 and 38400. I think you need to pick one that works
// and I think it varies across different firmware versions.
#define DOMEBAUDRATE 9600

//I2C device addresses
// 50: Dome Master Betterduino (Teeces + Holos forwarded to dome slave)
// 51: Dome Slave Betterduino
// 52: Body Master Betterduino (MP3 player)
#define I2C_MP3    52
#define I2C_TEECES 50
#define I2C_HOLOS  50


// Effect durations
// Used to coordinate the timing of the effects with the sounds
#define LeiaDuration          35
#define AlarmDuration          4
#define ShortCircuitDuration  10
#define MarchDuration        175
#define CantinaDuration      165

#endif // __CONFIG_H__

