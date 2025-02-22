# Padawan360-pio

Padawan360 inspired code to control an Astromech.
Based on [Dan Kraus' padawan360](https://github.com/dankraus/padawan360) implementation but heavily modified:
- Teeces, Holos and sound is controlled by [MarcDuino master and slave boards](https://www.curiousmarc.com/r2-d2/marcduino-system) flashed with the [BetterDuinoV4 firmware](https://github.com/RasmusAaen/BetterDuinoFirmwareV4)
- Implemented abstraction classes for I2C communication with BetterDuino
- Moved to [platform.io](https://platformio.org/) to be able to use VS Code instead of the Arduino IDE

