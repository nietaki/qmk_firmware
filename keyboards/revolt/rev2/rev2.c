// Copyright 2025 Jacek Królikowski (@nietaki)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

void keyboard_pre_init_kb(void) {
  // Call the keyboard pre init code.
  keyboard_pre_init_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // The "keyboard" switches are connected using a regular row/col matrix with diodes,
  // while the "mouse" switches are connected directly between mcu pins and GND.
  //
  // Instead of reimplementing the matrix scanning code, let's discard the "mouse" key events
  // from all but one row.
  if(record->event.key.col >= 14 && record->event.key.row < 4) {
    return false;
  }
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
#ifdef CONSOLE_ENABLE
    uprintf("highest_layer: %u\n", get_highest_layer(state));
#endif
    return state;
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
