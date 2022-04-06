/* Copyright 2022 electroLABBOT. All rights reserved. */
#ifndef PIO_SRC_LIB_ELECTROLABBOT_SRC_ELECTROLABBOT_H_
#define PIO_SRC_LIB_ELECTROLABBOT_SRC_ELECTROLABBOT_H_
#include <Arduino.h>
#include <ESP32Servo.h>
#include <FastLED.h>

#include "electroLABBOT_config.h"

class LED {
private:
  void rgb_init();
  CRGB LEDs[NUM_LEDS];

public:
  LED();
  explicit LED(int16_t pin_led);

  void led(int16_t pin_led, bool state);

  void rgb_blink(uint32_t blink_delay);
  void rgb_set_color(uint8_t led, uint8_t R, uint8_t G, uint8_t B);
  /*
      led = LED_D11, LED_D12, LED_D13, LED_D14 ou LED_all (pour affecter la
     couleur aux 4 leds) R, G, B correspodnent au pourcentage de rouge, vert
     ou bleu dans la led.
  */
};

class UltrasonicSensor {
private:
public:
  UltrasonicSensor();
  void move_ultrasonic_sensor(int16_t);
  double measure_distance_in_cm();
  uint8_t find_clear_path();
  uint8_t check_clearance(uint8_t);
};

class Motors {
private:
  const int16_t PWM_MOTOR1_CHANNEL = 2;
  const int16_t PWM_MOTOR2_CHANNEL = 3;
  const int16_t PWM_MOTORS_FREQ = 3000;
  const int16_t PWM_MOTORS_RES = 8;

  const int16_t PWM_MOTOR_MIN_VALUE_DUTYCYCLE = 60;
  int16_t previous_left_motor_speed = 0;
  int16_t previous_right_motor_speed = 0;
  const int16_t max_val_motors_speed = 200;
  const int16_t start_val_right_motor_speed = 0;
  const int16_t start_val_left_motor_speed = 0;

public:
  Motors();
  void left_motor_speed(int16_t);
  void right_motor_speed(int16_t);
  void motors_speed(int16_t, int16_t);
};

void attach_detach_PWM(uint8_t, uint8_t, uint8_t);

void average_IR(int16_t[]);

class IR_Sensor {
private:
public:
  IR_Sensor();
  uint16_t left_IR_sensor_read_value();
  uint16_t right_IR_sensor_read_value();
};

class ElectroLABBOT : public Motors, public UltrasonicSensor, public LED {
private:
public:
  ElectroLABBOT();
};

#endif // PIO_SRC_LIB_ELECTROLABBOT_SRC_ELECTROLABBOT_H_