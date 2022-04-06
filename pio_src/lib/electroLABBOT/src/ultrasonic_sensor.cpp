/* Copyright 2022 electroLABBOT. All rights reserved. */
#include "electroLABBOT.h"

Servo servo;
bool attach = false;

UltrasonicSensor::UltrasonicSensor() {
  servo.attach(SERVOMOTOR_PIN);
  // le attach ne se fait pas pourtant le constructeur est réalisé ...
}

void UltrasonicSensor::move_ultrasonic_sensor(int16_t degrees) {
  if (attach == false) {
    servo.attach(SERVOMOTOR_PIN);
    attach = true;
  }
  servo.write(degrees);
}

uint8_t UltrasonicSensor::find_clear_path() {
  if (attach == false) {
    servo.attach(SERVOMOTOR_PIN);
    attach = true;
  }
  double distance_left_side = 0;
  double distance_right_side = 0;

  move_ultrasonic_sensor(180);
  while (servo.read() < 179) {
    continue;
  }
  delay(1000);
  distance_left_side = measure_distance_in_cm();

  move_ultrasonic_sensor(5);
  while (servo.read() > 11) {
    continue;
  }
  delay(1000);
  distance_right_side = measure_distance_in_cm();

  if (distance_left_side < 8 && distance_right_side < 8)
    return NO_FREE;

  else if (distance_left_side > distance_right_side)
    return LEFT_FREE;

  else
    return RIGHT_FREE;
}

double UltrasonicSensor::measure_distance_in_cm() {
  uint32_t start_time = 0, stop_time = 0;
  double distance = 0;
  bool previous_state = 0;

  pinMode(ULTRASONIC_SENSOR_PIN, OUTPUT);
  digitalWrite(ULTRASONIC_SENSOR_PIN, HIGH);
  delayMicroseconds(2);

  vTaskSuspendAll();

  digitalWrite(ULTRASONIC_SENSOR_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(ULTRASONIC_SENSOR_PIN, LOW);

  pinMode(ULTRASONIC_SENSOR_PIN, INPUT);

  start_time = micros();
  previous_state = digitalRead(ULTRASONIC_SENSOR_PIN);
  while (previous_state == digitalRead(ULTRASONIC_SENSOR_PIN) &&
         ((micros() - start_time) < 40000)) {
    continue;
  }

  start_time = micros();

  previous_state = digitalRead(ULTRASONIC_SENSOR_PIN);
  while (previous_state == digitalRead(ULTRASONIC_SENSOR_PIN) &&
         ((micros() - start_time) < 40000)) {
    continue;
  }

  stop_time = micros();

  xTaskResumeAll();

  distance = fabs(((stop_time - 40 - start_time) / 58.31));

  return distance < 500 ? distance : 501;
}

uint8_t UltrasonicSensor::check_clearance(uint8_t stop_distance) {
  return measure_distance_in_cm() > stop_distance ? KEEP_GOING : STOP;
}
