/* Copyright 2022 electroLABBOT. All rights reserved. */
#include "electroLABBOT.h"

bool led_state = false;
uint32_t previous_millis = 0;
uint32_t current_millis;

LED::LED() {
  FastLED.addLeds<WS2812B, DATA_PIN, COLOR_ORDER>(LEDs, NUM_LEDS);
  pinMode(LED_BUILTIN, OUTPUT);
}

LED::LED(int16_t led_pin) { pinMode(led_pin, OUTPUT); }

void LED::led(int16_t led_pin, bool state) { digitalWrite(led_pin, state); }

void LED::rgb_blink(uint32_t blink_delay) {
  current_millis = millis();

  if ((current_millis - previous_millis) >= blink_delay) {
    previous_millis = millis();

    for (uint8_t i = 0; i < 4; i++) {
      LEDs[i] = led_state ? 0x000000 : 0x00FF0000;
    }
    FastLED.show();
    led_state = !led_state;
  }
}

void LED::rgb_set_color(uint8_t led, uint8_t R, uint8_t G, uint8_t B) {
  uint32_t rgb = 0;
  uint32_t temp = 0;

  rgb = R << 16;

  temp = G << 8;
  rgb = rgb | temp;

  temp = B;
  rgb = rgb | temp;

  if (led == LED_all) {
    for (int i = 0; i < 4; i++) {
      LEDs[i] = rgb;
    }
  } else {
    LEDs[led] = rgb;
  }

  FastLED.show();
}
