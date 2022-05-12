#define S1 D0 // right most sensor
#define S2 D1
#define S3 D2
#define S4 D3 // left most sensor
#define LM2 D5 //left motor +
#define LM1 D6 //left motor -
#define RM1 D7 //right motor +
#define RM2 D4 //right motor -
// 1 -- black  , 0 -- white
void setup() {
  pinMode(S1,INPUT);
  pinMode(S2,INPUT);
  pinMode(S3,INPUT);
  pinMode(S4,INPUT);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("S1 : ");
  Serial.println(digitalRead(S1));
  Serial.print("S2 : ");
  Serial.println(digitalRead(S2));
  Serial.print("S3 : ");
  Serial.println(digitalRead(S3));
  Serial.print("S4 : ");
  Serial.println(digitalRead(S4));
  delay(500);

if(digitalRead(S1) == 0 && digitalRead(S4) == 0  && (digitalRead(S2) == 1 || digitalRead(S3) == 1 )){
Serial.println("Forward");
digitalWrite(LM1,HIGH);
  digitalWrite(LM2,LOW);
  digitalWrite(RM1,HIGH);
  digitalWrite(RM2,LOW);
}
else if(digitalRead(S1) == 1 && digitalRead(S4) == 1  && (digitalRead(S2) == 1 || digitalRead(S3) == 1)){
    Serial.println("Stop");
    digitalWrite(LM1,LOW);
  digitalWrite(LM2,LOW);
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,LOW);
  }
else if(digitalRead(S1) == 0 && digitalRead(S4)==1){
    Serial.println("TurnLeft");
    digitalWrite(LM1,LOW);
  digitalWrite(LM2,LOW);
  digitalWrite(RM1,HIGH);
  digitalWrite(RM2,LOW);
  }
  else if(digitalRead(S4) == 0 && digitalRead(S1)==1){
    Serial.println("TurnRight");
  digitalWrite(LM1,HIGH);
  digitalWrite(LM2,LOW);
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,LOW);
  }

}
