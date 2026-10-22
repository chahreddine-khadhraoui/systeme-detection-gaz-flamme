void setup() {
  pinMode(A0, INPUT);      // Capteur de gaz (analogique)
  pinMode(2, INPUT);       // Capteur de flamme (numérique)
  pinMode(3, OUTPUT);      // LED Rouge
  pinMode(4, OUTPUT);      // LED Verte
  pinMode(5, OUTPUT);      // Buzzer
}

void loop() {
  int fireValue = digitalRead(2);
  int val = analogRead(A0);

  // Remarque : ajuster la valeur "400" selon la sensibilité de ton capteur de gaz
  if ((fireValue == 0) || (val > 400)) {
    // Danger détecté (gaz ou flamme)
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  } else {
    // Normal / Sécurité
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }

  delay(200);
}
