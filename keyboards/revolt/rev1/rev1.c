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

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed

  if(record->event.key.col >= 14 && record->event.key.row < 4) {
    return false;
  }
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
#ifdef CONSOLE_ENABLE
    // TODO account for the cut off corners
    if(0 != mouse_report.x || 0 != mouse_report.y) {
        uprintf("mouse x: %i, y: %i\n", mouse_report.x, mouse_report.y);
    }
#endif
    return mouse_report;
}
