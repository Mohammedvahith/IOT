int ledPin = 8;      // LED pin

void setup() {
  pinMode(8,OUTPUT); // Initialize the LED pin as an output
  pinMode(2,OUTPUT); // Initialize pin 2 as an output (not used in loop)
}

void loop() {
  digitalWrite(8,1); // Turn the LED on
  delay(200);        // Wait for 200 milliseconds
  
  digitalWrite(8,0); // Turn the LED off
   delay(100);       // Wait for 100 milliseconds
  
}
