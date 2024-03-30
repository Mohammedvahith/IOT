int ultratrig=11;
int ultraecho=12;
long duration;
int distance;
void setup() {
  pinMode(11,OUTPUT);
  pinMode(12,INPUT);
  pinMode(8,OUTPUT);
}
void loop() {
  digitalWrite(8,0);
  digitalWrite(ultratrig,0);
  delayMicroseconds(2);
  digitalWrite(ultratrig,1);
  delayMicroseconds(10);
  digitalWrite(ultratrig,0);
  duration=pulseIn(ultraecho,1);
  distance=duration * 0.034 / 2;
  if(distance < 10)
  digitalWrite(8,1);
  else
  digitalWrite(8,0);
}
