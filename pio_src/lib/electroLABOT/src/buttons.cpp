/* Copyright 2022 electroLABOT. All rights reserved. */
#include "electroLABOT.h"

Buttons::Buttons() {
  pinMode(BUTTON_1_PIN, INPUT);
  pinMode(BUTTON_2_PIN, INPUT);
}

bool Buttons::read_button_1() { return digitalRead(BUTTON_1_PIN); }

bool Buttons::read_button_2() { return digitalRead(BUTTON_2_PIN); }
