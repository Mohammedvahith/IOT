char blueToothVal;
char lastValue;
//left wheel
int inl1=4;
int inl2=5;
int inl3=6;
int inl4=7;
//right wheel
int inr1=8;
int inr2=9;
int inr3=10;
int inr4=11;
//ultra sonic sensor
int trig=12;
int echo=13;
float duration;
int dist;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(inl1,OUTPUT);
  pinMode(inl2,OUTPUT);
  pinMode(inl3,OUTPUT);
  pinMode(inl4,OUTPUT);
  pinMode(inr1,OUTPUT);
  pinMode(inr2,OUTPUT);
  pinMode(inr3,OUTPUT);
  pinMode(inr4,OUTPUT);
}

void loop() {
  if(Serial.available())
  {//if there is data being recieved
    blueToothVal=Serial.read();//read it
  }
  if(blueToothVal=='s')
  {//if value from the blutooth serial in n
   //move forward
    digitalWrite(inl1,LOW);
    digitalWrite(inl2,LOW);
    digitalWrite(inl3,LOW);
    digitalWrite(inl4,LOW);
    digitalWrite(inr1,LOW);
    digitalWrite(inr2,LOW);
    digitalWrite(inr3,LOW);
    digitalWrite(inr4,LOW);
  }
  if(blueToothVal=='f')
  {//if value from the blutooth serial in n
   //move forward
    digitalWrite(inl1,HIGH);
    digitalWrite(inl2,LOW);
    digitalWrite(inl3,HIGH);
    digitalWrite(inl4,LOW);
    digitalWrite(inr1,HIGH);
    digitalWrite(inr2,LOW);
    digitalWrite(inr3,HIGH);
    digitalWrite(inr4,LOW);
  }
  if(blueToothVal=='b')
  {//if value from the blutooth serial in n
   //backward
    Serial.print('backward');
    digitalWrite(inl1,LOW);
    digitalWrite(inl2,HIGH);
    digitalWrite(inl3,LOW);   
    digitalWrite(inl4,HIGH);
    digitalWrite(inr1,LOW);
    digitalWrite(inr2,HIGH);
    digitalWrite(inr3,LOW);
    digitalWrite(inr4,HIGH);
  }
  if(blueToothVal=='r')
  {//if value from the blutooth serial in n
   //right
    digitalWrite(inl1,HIGH);
    digitalWrite(inl2,LOW);
    digitalWrite(inl3,LOW);
    digitalWrite(inl4,HIGH);
    digitalWrite(inr1,LOW);
    digitalWrite(inr2,HIGH);
    digitalWrite(inr3,HIGH);
    digitalWrite(inr4,LOW);
  }
  if(blueToothVal=='l')
  {//if value from the blutooth serial in n
   //left
    digitalWrite(inl1,LOW);
    digitalWrite(inl2,HIGH);
    digitalWrite(inl3,HIGH);   
    digitalWrite(inl4,LOW);
    digitalWrite(inr1,HIGH);
    digitalWrite(inr2,LOW);
    digitalWrite(inr3,LOW);
    digitalWrite(inr4,HIGH);
  }
  if(blueToothVal=='e')
  {//if value from the blutooth serial in n
   //forward-right
    digitalWrite(inl1,HIGH);
    digitalWrite(inl2,LOW);
    digitalWrite(inl3,LOW);
    digitalWrite(inl4,LOW);
    digitalWrite(inr1,LOW);
    digitalWrite(inr2,LOW);
    digitalWrite(inr3,HIGH);
    digitalWrite(inr4,LOW);
  }
  if(blueToothVal=='w')
  {//if value from the blutooth serial in n
   //forward-left
    digitalWrite(inl1,LOW);
    digitalWrite(inl2,LOW);
    digitalWrite(inl3,HIGH);   
    digitalWrite(inl4,LOW);
    digitalWrite(inr1,HIGH);
    digitalWrite(inr2,LOW);
    digitalWrite(inr3,LOW);
    digitalWrite(inr4,LOW);
  }
  if(blueToothVal=='n')
  {//if value from the blutooth serial in n
   //backward-right
    digitalWrite(inl1,LOW);
    digitalWrite(inl2,LOW);
    digitalWrite(inl3,LOW);
    digitalWrite(inl4,HIGH);
    digitalWrite(inr1,LOW);
    digitalWrite(inr2,HIGH);
    digitalWrite(inr3,LOW);
    digitalWrite(inr4,LOW);
  }
  if(blueToothVal=='j')
  {//if value from the blutooth serial in n
   //backward-left
    digitalWrite(inl1,LOW);
    digitalWrite(inl2,HIGH);
    digitalWrite(inl3,LOW);   
    digitalWrite(inl4,LOW);
    digitalWrite(inr1,LOW);
    digitalWrite(inr2,LOW);
    digitalWrite(inr3,LOW);
    digitalWrite(inr4,HIGH);
  }
  if(blueToothVal=='k')
  {//if value from the blutooth serial in n
   //turning - right
    digitalWrite(inl1,HIGH);
    digitalWrite(inl2,LOW);
    digitalWrite(inl3,HIGH);
    digitalWrite(inl4,LOW);
    digitalWrite(inr1,LOW);
    digitalWrite(inr2,HIGH);
    digitalWrite(inr3,LOW);
    digitalWrite(inr4,HIGH);
  }
  if(blueToothVal=='p')
  {//if value from the blutooth serial in n
   //turning - left
    digitalWrite(inl1,LOW);
    digitalWrite(inl2,HIGH);
    digitalWrite(inl3,LOW);
    digitalWrite(inl4,HIGH);
    digitalWrite(inr1,HIGH);
    digitalWrite(inr2,LOW);
    digitalWrite(inr3,HIGH);
    digitalWrite(inr4,LOW);
  }
  if(blueToothVal=='o')
  {//if value from the blutooth serial in n
   //CURVED TRAJECTORY
    digitalWrite(inl1,HIGH);
    digitalWrite(inl2,LOW);
    digitalWrite(inl3,HIGH);
    digitalWrite(inl4,LOW);
    digitalWrite(inr1,LOW);
    digitalWrite(inr2,HIGH);
    digitalWrite(inr3,LOW);
    digitalWrite(inr4,HIGH);
  }
  if(blueToothVal=='a')
  {//if value from the blutooth serial in n
   //LATERAL ARC
    digitalWrite(inl1,LOW);
    digitalWrite(inl2,HIGH);
    digitalWrite(inl3,LOW);
    digitalWrite(inl4,LOW);
    digitalWrite(inr1,HIGH);
    digitalWrite(inr2,LOW);
    digitalWrite(inr3,LOW);
    digitalWrite(inr4,LOW);
  }
}
