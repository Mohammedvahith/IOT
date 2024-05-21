int ultratrig = 11; // Ultrasonic sensor trigger pin
int ultraecho = 12; // Ultrasonic sensor echo pin
int outputPin = 8;  // Output pin for LED or buzzer

long duration;
int distance;

void setup() {
  pinMode(ultratrig, OUTPUT); // Initialize trigger pin as output
  pinMode(ultraecho, INPUT);  // Initialize echo pin as input
  pinMode(outputPin, OUTPUT); // Initialize output pin as output
}

void loop() {
  digitalWrite(outputPin, LOW);     // Turn off the output initially
  digitalWrite(ultratrig, LOW);     // Ensure the trigger pin is low
  delayMicroseconds(2);
  digitalWrite(ultratrig, HIGH);    // Send a trigger pulse
  delayMicroseconds(10);
  digitalWrite(ultratrig, LOW);
  
  duration = pulseIn(ultraecho, HIGH); // Read the echo duration
  distance = duration * 0.034 / 2;     // Calculate the distance

  if (distance < 10) {
    digitalWrite(outputPin, HIGH); // Turn on the output if distance is less than 10 cm
  } 
  else {
    digitalWrite(outputPin, LOW);  // Turn off the output otherwise
  }
}
