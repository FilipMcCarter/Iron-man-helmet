#include <Arduino.h>
#include <Servo.h>

Servo servo1;
Servo servo2;

const int button = 2;

bool state = 0;
bool lastState = HIGH;

int openPos = 90;
int closePos = 0;
int offset = 0;

void setup() {
  pinMode(button, INPUT_PULLUP);
  servo1.attach(9);
  servo2.attach(10);
  servo1.write(closePos + offset);
  servo2.write(180 - (closePos + offset));
  pinMode(17, OUTPUT);
  delay(300);
}

void loop() {
  bool stateR = digitalRead(button);

  if(lastState == HIGH && stateR == LOW){
    state = !state;

    if(state){
      servo1.write(openPos + offset);
      servo2.write(180 - (openPos + offset));
      digitalWrite(17, LOW);  
    }
    else{
      servo1.write(closePos + offset);
      servo2.write(180 - (closePos + offset));
      digitalWrite(17, HIGH);  
    }

    delay(200);

  }
  lastState = stateR;
}
