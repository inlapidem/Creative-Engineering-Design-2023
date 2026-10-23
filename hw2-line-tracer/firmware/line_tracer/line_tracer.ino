#define LCW 7
#define LCCW 6
#define RCW 8
#define RCCW 9

#define LLS 10
#define LS 11
#define RS 12
#define RRS 4
                          
int TrnSpeed = 105;
int RotSpeed = 130;

long t = 0;
bool lcheck = 0;
bool rcheck = 0;

void straight(){
  if ((!digitalRead(RS))&&(!digitalRead(LS))){
    analogWrite(LCW, TrnSpeed);
    analogWrite(LCCW, 0);
    analogWrite(RCW, TrnSpeed);
    analogWrite(RCCW, 0);
  }
  else if (!digitalRead(LS)){
    analogWrite(LCW, RotSpeed);
    analogWrite(LCCW, 0);
    analogWrite(RCW, 0);
    analogWrite(RCCW, 0);
  }
  else if (!digitalRead(RS)){
    analogWrite(LCW, 0);
    analogWrite(LCCW, 0);
    analogWrite(RCW, RotSpeed);
    analogWrite(RCCW, 0);
  }
  else if (digitalRead(RS)&&digitalRead(LS)){
    analogWrite(LCW, TrnSpeed);
    analogWrite(LCCW, 0);
    analogWrite(RCW, TrnSpeed);
    analogWrite(RCCW, 0);
    delay(40);
  }
}

void setup() {
  pinMode(LCW, OUTPUT);
  pinMode(LCCW, OUTPUT);
  pinMode(RCW, OUTPUT);
  pinMode(RCCW, OUTPUT);
  pinMode(LLS, INPUT);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(RRS, INPUT);
}

void loop() {
  if ((!digitalRead(RRS))&&(!digitalRead(LLS))){
    straight();
  }
  else if (digitalRead(RRS)){
    analogWrite(LCW, 0);
    analogWrite(LCCW, 0);
    analogWrite(RCW, 0);
    analogWrite(RCCW, 0);
    delay(1000);
    analogWrite(LCW, TrnSpeed);
    analogWrite(LCCW, 0);
    analogWrite(RCW, TrnSpeed);
    analogWrite(RCCW, 0);
    if (digitalRead(LLS)){
      lcheck = 1;
    }
    delay(300);
    analogWrite(LCW, 0);
    analogWrite(LCCW, 0);
    analogWrite(RCW, 0);
    analogWrite(RCCW, 0);
    delay(1000);
    if (lcheck == 1){
      lcheck = 0;
      while((!digitalRead(RRS))&&(!digitalRead(LLS))){
        straight();
      }
      analogWrite(LCW, 0);
      analogWrite(LCCW, 0);
      analogWrite(RCW, 0);
      analogWrite(RCCW, 0);
      delay(1000);
      if (digitalRead(LLS)||digitalRead(RRS)){
        analogWrite(LCW, TrnSpeed);
        analogWrite(LCCW, 0);
        analogWrite(RCW, TrnSpeed);
        analogWrite(RCCW, 0);
        delay(300);
      }
      analogWrite(LCW, 0);
      analogWrite(LCCW, 0);
      analogWrite(RCW, 0);
      analogWrite(RCCW, 0);
      delay(1000);
    }
    else {
      analogWrite(LCW, TrnSpeed);
      analogWrite(LCCW, 0);
      analogWrite(RCW, TrnSpeed);
      analogWrite(RCCW, 0);
      delay(600);
      while(!digitalRead(LS)){
        
        analogWrite(LCW, RotSpeed);
        analogWrite(LCCW, 0);
        analogWrite(RCW, 0);
        analogWrite(RCCW, RotSpeed);
        delay(80);
        analogWrite(LCW, 0);
        analogWrite(LCCW, 0);
        analogWrite(RCW, 0);
        analogWrite(RCCW, 0);
        delay(80);
      }
      delay(500);
      analogWrite(LCW, 0);
      analogWrite(LCCW, 0);
      analogWrite(RCW, 0);
      analogWrite(RCCW, 0);
      delay(1000);
    }
  }
  else if (digitalRead(LLS)){
    analogWrite(LCW, 0);
    analogWrite(LCCW, 0);
    analogWrite(RCW, 0);
    analogWrite(RCCW, 0);
    delay(1000);
    analogWrite(LCW, TrnSpeed);
    analogWrite(LCCW, 0);
    analogWrite(RCW, TrnSpeed);
    analogWrite(RCCW, 0);
    if (digitalRead(RRS)){
      rcheck = 1;
    }
    delay(300);
    analogWrite(LCW, 0);
    analogWrite(LCCW, 0);
    analogWrite(RCW, 0);
    analogWrite(RCCW, 0);
    delay(1000);
    if (rcheck == 1){
      rcheck = 0;
      while((!digitalRead(RRS))&&(!digitalRead(LLS))){
        straight();
      }
      analogWrite(LCW, 0);
      analogWrite(LCCW, 0);
      analogWrite(RCW, 0);
      analogWrite(RCCW, 0);
      delay(1000);
      if (digitalRead(LLS)||digitalRead(RRS)){
        analogWrite(LCW, TrnSpeed);
        analogWrite(LCCW, 0);
        analogWrite(RCW, TrnSpeed);
        analogWrite(RCCW, 0);
        delay(300);
      }
      analogWrite(LCW, 0);
      analogWrite(LCCW, 0);
      analogWrite(RCW, 0);
      analogWrite(RCCW, 0);
      delay(1000);
    }
    else {
      analogWrite(LCW, TrnSpeed);
      analogWrite(LCCW, 0);
      analogWrite(RCW, TrnSpeed);
      analogWrite(RCCW, 0);
      delay(600);
      while(!digitalRead(RS)){
        
        analogWrite(LCW, 0);
        analogWrite(LCCW, RotSpeed);
        analogWrite(RCW, RotSpeed);
        analogWrite(RCCW, 0);
        delay(80);
        analogWrite(LCW, 0);
        analogWrite(LCCW, 0);
        analogWrite(RCW, 0);
        analogWrite(RCCW, 0);
        delay(80);
      }
      analogWrite(LCW, 0);
      analogWrite(LCCW, 0);
      analogWrite(RCW, 0);
      analogWrite(RCCW, 0);
      delay(1000);

    }
    
  }
  else{
    straight();
  }
}

