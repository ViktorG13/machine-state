#pragma once
#include "../shared.h"

typedef enum {
  EVENT_NONE,
  EVENT_BUTTON_PRESSED,
  EVENT_BUTTON_RELEASED,
} Event;

typedef enum {
  STATE_BLINKING,
  STATE_PRINTING,
} State;

void machine(Event);