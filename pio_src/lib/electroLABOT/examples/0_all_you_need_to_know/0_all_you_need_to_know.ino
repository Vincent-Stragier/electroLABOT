#include <electroLABOT.h>

ElectroLABOT billy;

void setup() {
  Serial.begin(9600);
  Serial.println(
      "Tout ce dont vous avez besoin de connaitre sur electroLABOT");

  billy.begin();

  /* Pour faire bouger le robot, il existes trois méthodes : */
  // Pour faire tourner le moteur gauche en marche arrière à la vitesse maximale
  // et pour faire tourner le moteur droit en marche avant à la vitesse maximale
  Serial.println("Rotation à droite...");
  billy.motors_speed(-4096, 4096);
  delay(1000);

  // Pour faire tourner le moteur gauche en marche avant à la vitesse maximale
  Serial.println("Tourner à droite...");
  billy.left_motor_speed(4096);
  delay(1000);

  // Pour faire tourner le moteur droit en marche arrière à la vitesse maximale
  Serial.println("Tourner vers l'arrière droite...");
  billy.right_motor_speed(-4096);
  delay(1000);

  // Pour stopper le robot
  Serial.println("Arrêter le robot...");
  billy.motors_speed(0, 0);

  /* Lecture du capteur de distance */
  for (uint8_t angle(0); angle < 180; angle += 10) {
    // La méthode move_ultrasonic_sensor() permet de faire tourner le capteur.
    billy.move_ultrasonic_sensor(angle);
    Serial.print("Lecture du capteur de distance (angle = ");
    Serial.print(angle);
    Serial.print("degrees) : ");
    // La méthode measure_distance_in_cm() permet de lire la distance mesurée.
    Serial.print(billy.measure_distance_in_cm());
    Serial.println(" cm");
  }

  /* Lecture des boutons */
  Serial.print("Lecture du bouton 1 : ");
  Serial.println(billy.read_button_1());
  Serial.print("Lecture du bouton 2 : ");
  Serial.println(billy.read_button_2());

  /* Lecture des capteurs IR */
  Serial.print("Lecture du capteur IR droit : ");
  Serial.println(billy.right_IR_sensor_read_value());
  Serial.print("Lecture du capteur IR gauche : ");
  Serial.println(billy.left_IR_sensor_read_value());

  /* Contrôle de LED_BUILTIN */
  // Pour allumer la LED_BUILTIN,
  // il faut appeler la méthode led() avec la
  // valeur true.
  billy.led(true);
  delay(1000);

  // Pour éteindre la LED_BUILTIN,
  // il faut appeler la méthode led() avec la
  // valeur false.
  billy.led(false);

  /* Contrôle de la buzzer */
  // Pour allumer la buzzer,
  // il faut appeler la méthode active_buzzer() avec la
  // valeur true.
  billy.active_buzzer(true);
  delay(1000);

  // Pour éteindre la buzzer,
  // il faut appeler la méthode active_buzzer() avec la
  // valeur false.
  billy.active_buzzer(false);
}

void loop() {}
