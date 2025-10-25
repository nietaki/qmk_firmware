# Revolt

- Keyboard Maintainer: [nietaki](https://github.com/nietaki)
- Hardware Supported: RPI 2040
- Hardware Availability: 
  - [purchase from NTK studio](https://ntkstudio.net/products/revolt-keyboard/)
  - [make your own](https://github.com/nietaki/revolt-keyboard) (Kicad, CC-BY-SA-4.0 license)

<!-- make revolt/base:default -->
Make example for this keyboard (after setting up your build environment):

    qmk compile -kb revolt/rev1 -km default

Flash the firmware by putting the kyboard into the bootloader mode and dragging the compiled `.uf2` file onto the RPI-RP2 drive that appears.

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
