#include "machine.h"
#include "shared.h"
#include <hardware/gpio.h>

bool previous = true;

int main() {
  stdio_init_all();

  gpio_init(LED);
  gpio_set_dir(LED, GPIO_OUT);

  gpio_init(19);
  gpio_pull_up(19);
  gpio_set_dir(19, GPIO_IN);

  while (true) {
    bool current = gpio_get(19);

    Event event = EVENT_NONE;

    if (previous && !current) {
      event = EVENT_BUTTON_PRESSED;
    }

    if (!previous && current) {
      event = EVENT_BUTTON_RELEASED;
    }

    previous = current;

    machine(event);
  }
}
