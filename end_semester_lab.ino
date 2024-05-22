const int buzzerPin = 13; // Pin number for the buzzer
const int irPin = 8;      // Pin number for the IR sensor

void setup() {
  Serial.begin(9600);         // Initializes serial communication with a baud rate of 9600 bits per second.
  pinMode(buzzerPin, OUTPUT); // Initialize the buzzer pin as an output
  pinMode(irPin, INPUT);      // Initialize the IR sensor pin as an input
}

void loop() {
  // Read the state of the IR sensor
  int irState = digitalRead(irPin);
  
  // Check if the IR sensor detects an obstacle
  if (irState == LOW) {
    // Turn on the buzzer if obstacle detected
    digitalWrite(buzzerPin, HIGH);
  } else {
    // Turn off the buzzer if no obstacle detected
    digitalWrite(buzzerPin, LOW);
  }        
}
