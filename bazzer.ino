    int ultratrig=7;
int ultraecho=6;
int sound=3;
int led=11;
long duration;
int distance;
void setup() {
  pinMode(11,OUTPUT);  //RED LIGHT
  pinMode(7,OUTPUT);   // TRIGGER
  pinMode(6,INPUT);    //ECHO
  pinMode(3,OUTPUT);   //SOUND
}

void loop() {
  digitalWrite(11,0);
  digitalWrite(ultratrig,0);
  delayMicroseconds(2);
  digitalWrite(ultratrig,1);
  delayMicroseconds(10);
  digitalWrite(ultratrig,0);
  duration=pulseIn(ultraecho,1);
  distance=duration * 0.034 / 2;
  if(distance >= 25 && distance <=30)
  { 
    digitalWrite(11,1);
    digitalWrite(3,0);
  }
  else if(distance<15)
  { 
    digitalWrite(11,1);
    digitalWrite(3,1);
  }
  else
  {
    digitalWrite(11,0);
    digitalWrite(3,0);
  }
}
