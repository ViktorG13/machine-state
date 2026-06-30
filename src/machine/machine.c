#include "machine.h"

State current_state = STATE_BLINKING;

int blinking() {
  gpio_put(LED, true);
  sleep_ms(1000);
  gpio_put(LED, false);
  sleep_ms(1000);
  return 0;
}

int printing() {
  printf("ON");
  sleep_ms(1000);
  printf("OFF");
  sleep_ms(1000);
  return 0;
}

void machine(Event event) {
  switch (current_state) {
  case STATE_BLINKING:
    blinking();
    if (event == EVENT_BUTTON_PRESSED) {
      current_state = STATE_PRINTING;
    }
    break;
  case STATE_PRINTING:
    printing();
    if (event == EVENT_BUTTON_RELEASED) {
      current_state = STATE_BLINKING;
    }
    break;
  }
}