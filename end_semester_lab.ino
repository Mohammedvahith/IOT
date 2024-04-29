const int bazzer = 13;
const int irPin = 8;

void setup(){
  Serial.begin(9600);
  pinMode(bazzer, OUTPUT);
  pinMode(irPin, INPUT); 
}

void loop() {
  int ir = digitalRead(irPin);
  if (ir == LOW) {
    digitalWrite(bazzer, HIGH);
    }
  else {
    digitalWrite(bazzer, LOW);
    }        

}
