int IRout = 7;      // IR sensor output pin
int IRin = 6;       // IR sensor input pin
int buzzer = 3;     // Buzzer pin

long duration;
int distance;

void setup() {
  pinMode(IRout, OUTPUT);   // Infrared output
  pinMode(IRin, INPUT);     // Infrared input
  pinMode(buzzer, OUTPUT);  // Buzzer
}

void loop() {
  digitalWrite(IRout, LOW);
  delayMicroseconds(2);
  digitalWrite(IRout, HIGH);
  delayMicroseconds(10);
  digitalWrite(IRout, LOW);

  duration = pulseIn(IRin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance >= 25 && distance <= 30) {
    digitalWrite(buzzer, LOW);  // Turn off buzzer
  } else if (distance < 15) {
    digitalWrite(buzzer, HIGH); // Turn on buzzer
  } else {
    digitalWrite(buzzer, LOW);  // Turn off buzzer
  }
}
