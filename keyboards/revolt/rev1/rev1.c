#include "quantum.h"

void keyboard_pre_init_kb(void) {
  // Call the keyboard pre init code.
  keyboard_pre_init_user();


  // RDY
  gpio_set_pin_input_high(GP14);
  //gpio_set_pin_output_open_drain(GP14);
  //gpio_write_pin_high(GP14);

  // GP15 is NRST
  gpio_set_pin_output(GP15);
  gpio_write_pin_high(GP15);
}
