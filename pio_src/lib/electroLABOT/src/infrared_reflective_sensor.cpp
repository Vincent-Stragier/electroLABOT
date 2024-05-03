/* Copyright 2022 electroLABOT. All rights reserved. */
#include "electroLABOT.h"

IR_Sensor::IR_Sensor() {
  pinMode(LEFT_IR_SENSOR_PIN, INPUT);
  pinMode(RIGHT_IR_SENSOR_PIN, INPUT);
}

uint16_t IR_Sensor::left_IR_sensor_read_value() {
  return analogRead(LEFT_IR_SENSOR_PIN);
}

uint16_t IR_Sensor::right_IR_sensor_read_value() {
  return analogRead(RIGHT_IR_SENSOR_PIN);
}
