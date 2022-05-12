#define S1 D0 // right most sensor
#define S2 D1
#define S3 D2
#define S4 D3 // left most sensor
#define LM2 D5 //left motor +
#define LM1 D6 //left motor -
#define RM1 D7 //right motor +
#define RM2 D8 //right motor -
#define dw digitalWrite
#define dr digitalRead
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
void forward(){
   dw(LM1,HIGH);
  dw(LM2,LOW);
  dw(RM1,HIGH);
  dw(RM2,LOW);
}
void turn_left(){
  dw(LM1,LOW);
  dw(LM2,LOW);
  dw(RM1,HIGH);
  dw(RM2,LOW);
}
void turn_right(){
  dw(LM1,HIGH);
  dw(LM2,LOW);
  dw(RM1,LOW);
  dw(RM2,LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("S1 : ");
  Serial.println(dr(S1));
  Serial.print("S2 : ");
  Serial.println(dr(S2));
  Serial.print("S3 : ");
  Serial.println(dr(S3));
  Serial.print("S4 : ");
  Serial.println(dr(S4));
//  delay(500);

if(dr(S1) == 0 && dr(S4) == 0 ){
Serial.println("Forward");
forward();
}
else if(dr(S1) == 1 && dr(S2) == 1&& dr(S3)==1 && dr(S4) == 1){
  Serial.println("Stop");
  digitalWrite(LM1,LOW);
  digitalWrite(LM2,LOW);
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,LOW);
  }
else if(dr(S4)==0 && dr(S1) == 1){
    Serial.println("TurnRight");
    turn_right();
    
  }
  else if(dr(S4)==1 && dr(S1) == 0){
    Serial.println("TurnLeft");
    turn_left();
  }

}
