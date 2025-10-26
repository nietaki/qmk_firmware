#include "quantum.h"

void keyboard_pre_init_kb(void) {
  // backlight
  gpio_set_pin_output(GP28);
  gpio_write_pin_high(GP28);

  // Call the keyboard pre init code.
  keyboard_pre_init_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // because of the way the mouse keys are connected, they would show up on multiple rows
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
