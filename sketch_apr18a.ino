//Arduino UNO pins
int E = 13;
int D = 12;
int C = 11;
int DP = 10;
int B = 9;
int A = 8;
int F = 7;
int G = 6;
int LED = 5;
int sensor=4;

int waittime = 8;
int waittime2=0;
int val = 0;
bool motionState = false;//we start with no motion detected

void one() {
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void two() {
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(DP, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}
void three() {
  digitalWrite(E, LOW);
  digitalWrite(D,HIGH );
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}
void four() {
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void five() {
  digitalWrite(E, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G,HIGH);
}
void six() {
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void seven() {
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void eight() {
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void nine() {
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void circle() {
  //Part1
  int counter = waittime;
  while (counter>=10) {
    digitalWrite(E, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(DP, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(A, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
    delay(250);
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    delay(250);
    digitalWrite(D, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    delay(250);
    digitalWrite(D, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(E, LOW);
    delay(250);
    counter--;
    waittime--;
  }
}

void setup()
{
  //7 segment Display pins
  pinMode(E, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(DP, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  Serial.begin(9600);
  //Led display
  pinMode(LED,OUTPUT);
  //Sensors pins
  pinMode(sensor,INPUT);
}
void zero(){
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  
}
void period() {
  waittime2 = waittime;
  circle();
  if(waittime==9){
      nine();
      delay(1000);
      waittime--;
  }
  if(waittime==8){
    eight();
    delay(1000);
      waittime--;
  }  
  if(waittime==7){
    seven();
    delay(1000);
    waittime--;
  }
  if(waittime==6){
    six();
    delay(1000);
    waittime--;
  }
  if(waittime==5){
    five();
    delay(1000);
    waittime--;
  }
  if(waittime==4){
    four();
    delay(1000);
    waittime--;
  }
  if(waittime==3){
    three();
    delay(1000);
    waittime--;
  }
  if(waittime==2){
    two();
    delay(1000);
    waittime--;
  }
  if(waittime==1){
    one();
    delay(1000);
    waittime--;
  }
  zero();
}

void loop()
{
  // Read out the pirPin and store as val:
  val = digitalRead(sensor);
  // If motion is detected (pirPin = HIGH), do the following:
  if (val == HIGH) {
    digitalWrite(LED,HIGH);
    period();
    // Change the motion state to true (motion detected):
    if (motionState == false) {
      Serial.println("Motion detected!");
      motionState = true;
    }
    digitalWrite(LED, LOW); // Turn off the on-board LED.
    val=0;
    waittime = waittime2;
  }
  else{
    digitalWrite(LED, LOW); // Turn off the on-board LED.
    // Change the motion state to false (no motion):
    if (motionState == true) {
      Serial.println("Motion ended!");
      motionState = false;
    }
 }
}
