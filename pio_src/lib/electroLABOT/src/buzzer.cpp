/* Copyright 2022 electroLABOT. All rights reserved. */
#include "electroLABOT.h"

Buzzer::Buzzer() { pinMode(BUZZER_PIN, OUTPUT); }

// void Buzzer::buzz(uint16_t frequency, uint16_t duration, uint16_t delay) {
//   tone(BUZZER_PIN, frequency, duration);
//   delay(delay);
// }

void Buzzer::buzz(uint16_t frequency, uint16_t duration) {
  //tone(BUZZER_PIN, frequency, duration);
}

void Buzzer::buzz() { 
  //tone(BUZZER_PIN, 1000); 
  }

void Buzzer::buzz(uint16_t frequency) { 
  //tone(BUZZER_PIN, frequency); 
  }

void Buzzer::no_buzz() { 
  //noTone(BUZZER_PIN); 
  }

void Buzzer::active_buzzer(bool buzzer_state) {
  digitalWrite(BUZZER_PIN, buzzer_state);
}
