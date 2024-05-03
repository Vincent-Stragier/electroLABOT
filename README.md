# electroLABOT
Bibliothèque Arduino utilisée pour piloter le robot de l'electroLAB (l'electroLABOT).

## Usage

Code exemple

```c++
#include <electroLABBOT.h>

ElectroLABBOT billy;

void setup() {
  // Initialisation du robot
  billy.begin();

  // Faire tourner les roues du robot (indiquer des valeurs entre -4096 et 4096)
  billy.motors_speed(-4096, 4096);
  delay(1000);

  // Faire tourner le moteur gauche
  billy.left_motor_speed(4096);
  delay(1000);

  // Faire tourner le moteur droit
  billy.right_motor_speed(-4096);
  delay(1000);

  // Pour stopper le robot
  billy.motors_speed(0, 0);

  // Orienter le capteur à ultrason
  billy.move_ultrasonic_sensor(90);
  delay(4000);

  // Lecture de la distance via le capteur à ultrason
  billy.measure_distance_in_cm()

  // Lecture de l'état des boutons
  billy.read_button_1();
  billy.read_button_2();

  // Lecture des capteurs IR
  billy.right_IR_sensor_read_value();
  billy.left_IR_sensor_read_value());

  /* Contrôle de LED_BUILTIN */
  billy.led(true);
  delay(1000);
  billy.led(false);

  /* Contrôle du buzzer */
  billy.active_buzzer(true);
  delay(1000);
  billy.active_buzzer(false);
}

void loop() {}
```

