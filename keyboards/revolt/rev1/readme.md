# Revolt

<!-- ![Planck](https://i.imgur.com/q2M3uEU.jpg) -->

<!-- A compact 40% (12x4) ortholinear keyboard kit made and sold by OLKB and Massdrop. [More info on qmk.fm](https://qmk.fm/planck/) -->

* Keyboard Maintainer: [nietaki](https://github.com/nietaki)
* Hardware Supported: RPI 2040
* Hardware Availability: open-source (KiCad, CC-BY-SA-4.0 license)

Make example for this keyboard (after setting up your build environment):

    make revolt/base:default

Flashing example for this keyboard:

    make revolt/base:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
