**_WIP: This is still very much a work in progress_**
---

Clarity
=======
Custom digital gauge for monitoring your engines key parameters.

Component Parts:
----------------
These are the components used for this specific project, but the code can be adjusted to suit any combination of microcontroller and lcd display.
* NodeMCU-32
* 1.28" round display (GC9A01 driver)

Main Libraries:
---------------
* Arduino
* [LVGL](https://docs.lvgl.io/master/)

Partitions:
This is specific to an NodeMCU-32S dev board, using a ESP32-WROOM-32 (ESP32-D0WD-V3 chip) with 32Mb(4MB) flash
> - **nvs:** Minimal non-volatile storage for key-value pairs (12 KB).
> - **otadata:** OTA data partition (8 KB).
> - **ota_0:** Application partition for OTA updates (2 MB).
> - **coredump:** Minimal core dump partition (64 KB).
> - **fat:** FAT filesystem partition using the remaining space (1.875 MB).

Credits:
--------
This project took inspiration from a product that [Rotarytronics](https://www.rotarytronics.com/) has already built and can be purchased online.

The code is also based on other projects from:
* [Garage Tinkering](https://github.com/valentineautos)
* [fbiego](https://github.com/fbiego)