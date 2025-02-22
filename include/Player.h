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
     * Play a random sound from first 4 banks
     */
    static void playRandom();

    /**
     * Play a random sound within a specific range from a specific bank.
     * @param bank The bank number.
     * @param trackMin The minimum track number.
     * @param trackMax The maximum track number.
     */
    static void playRandom(byte bank, byte trackMin, byte trackMax);

    /**
     * Sound off
     */
    static void off();

    /**
     * Play Leia Message (bank 7 track 1)
     */
    static void playLeia();

    /**
     * Play Cantina music (bank 9 track 5)
     */
    static void playCantina();

    /**
     * Play beep version of cantina music (bank 9 track 1)
     */
    static void playCantinaBeep();

    /**
     * Play Scream (bank 6 track 1)
     */
    static void playScream();

    /**
     * Play Short Circuit (bank 6 track 3)
     */
    static void playShortCircuit();

    /**
     * Play Disco music (bank 9 track 6)
     */
    static void playDisco();

    /**
     * Stop the current sound.
     */
    static void stop();

    /**
     * Increase the volume.
     */
    static void volumeUp();

    /**
     * Decrease the volume.
     */
    static void volumeDown();

    /**
     * Set mid volume
     */
    static void volumeMid();

    /**
     * Set max volume
     */
    static void volumeMax();

    /**
     * Set min volume
     */
    static void volumeMin();

    /**
     * Play Star Wars Theme (bank 9 track 2)
     */
    static void playStarWars();

    /**
     * Play beep version of Star Wars Theme (bank 9 track 7)
     */
    static void playStarWarsBeep();

    /**
     * Play Imperial March (bank 9 track 3)
     */
    static void playMarch();

    /**
     * Play beep version of Imperial March (bank 9 track 8)
     */
    static void playMarchBeep();

    /**
     * Play startup sound
     */
    static void playStartup();

};

#endif // __PLAYER_H__
