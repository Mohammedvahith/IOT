int ultratrig = 7;  // Ultrasonic sensor trigger pin
ultraecho = 6;  // Ultrasonic sensor echo pin
int sound = 3;      // Buzzer pin
int led = 11;       // LED pin

long duration;
int distance;

void setup() {
  pinMode(led, OUTPUT);       // Red light
  pinMode(ultratrig, OUTPUT); // Trigger
  pinMode(ultraecho, INPUT);  // Echo
  pinMode(sound, OUTPUT);     // Sound
}

void loop() {
  digitalWrite(led, LOW);      // Turn off LED initially
  digitalWrite(ultratrig, LOW);
  delayMicroseconds(2);
  digitalWrite(ultratrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultratrig, LOW);
  
  duration = pulseIn(ultraecho, HIGH);
  distance = duration * 0.034 / 2;

  if (distance >= 25 && distance <= 30) {
    digitalWrite(led, HIGH);  // Turn on LED
    digitalWrite(sound, LOW); // Turn off buzzer
  } else if (distance < 15) {
    digitalWrite(led, HIGH);  // Turn on LED
    digitalWrite(sound, HIGH);// Turn on buzzer
  } else {
    digitalWrite(led, LOW);   // Turn off LED
    digitalWrite(sound, LOW); // Turn off buzzer
  }
}
