#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <Arduino.h>

/**
 * Class to abstract the MP3 player functionality implemented in the BetterDuino firmware.
 * Communicates over I2C with the MarcDuino board that controls the MP3 player.
 *
 * Sounds are organized in banks according to the MarcDuino system.
 *
 * Files named 001-xxx to 025-xxx: Generic Sounds (i.e. triggered by the "Gen" buttons on the R2-Touch app).
 * 026-xxx to 050-xxx: Chatty Sounds
 * 051-xxx to 075-xxx: Happy Sounds
 * 076-xxx to 100-xxx: Sad Sounds
 * 101-xxx to 125-xxx: Whistle Sounds
 * 126-xxx to 150-xxx: Scream Sounds
 * 151-xxx to 175-xxx: Leia Sounds
 * 176-xxx to 200-xxx: Music Sounds
 * 255-xxx: Startup Sound
 *
 * @see https://www.curiousmarc.com/r2-d2/mp3-trigger-sound-system
 */
class Player {
  public:
    /**
     * Play a specific sound.
     * @param bank The bank number.
     * @param track The track number.
     */
    static void play(byte bank, byte track);

    /**
     * Play a random sound from a bank.
     * @param bank The bank number.
     * @param trackMin The minimum track number.
     * @param trackMax The maximum track number.
     */
    static void playRandom(byte bank, byte trackMin, byte trackMax);

    /**
     * Increase the volume.
     */
    static void volumeUp();

    /**
     * Decrease the volume.
     */
    static void volumeDown();
};

#endif // __PLAYER_H__
