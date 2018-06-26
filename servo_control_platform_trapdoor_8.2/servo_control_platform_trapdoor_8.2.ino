#include <Servo.h>

Servo platform;
Servo trapdoor;

int switchPin2 = 6;
int switchPin1 = 7;
int servoPin = 9;
int powerControl = 8;
int platPin= 9;
int trapPin = 10;

int incomingByte = 0; // for incoming serial data
int postrap = 0; //for trapdoor position
int switchStatus = 0;
int switchStatus2 = 0;
int shutoff = 0;
int spin = 0;
int binNum = 0;
int pos = 0;

#define BIN1TIME  300
#define BIN2TIME  1100
#define BIN3TIME  200
#define BIN4TIME  1000

void setup() {
    //Debug
    Serial.begin(9600);

    // pin 6 to switch
    pinMode(switchPin2, INPUT);

    // pin 7 to switch
    pinMode(switchPin1, INPUT);

    // pin 8 to base of Transistor
    pinMode(powerControl, OUTPUT);
    Serial.println("Transistor base set to pin " + powerControl);

    //pin 9 to Servo signal line
    pinMode(platPin, OUTPUT);
    Serial.println("Servo signal set to pin " + String(servoPin, DEC));

    //pin 10 to trapdoor
    trapdoor.attach(trapPin);
    trapdoor.write(43);

    //pin 13 to light
    pinMode(13, OUTPUT);

    Serial.println("Ready");

}

void loop() {
      if (Serial.available() > 0) {
      binNum = Serial.read();

      Serial.print("I received: ");
      Serial.println(binNum, DEC);   // display received value as decimal
    }
    switch(binNum){
      case 48://
        resetServo();
        break;
      case 49://(binNum == 1)
        bin1();
        break;
      case 50://(binNum == 2)
        bin2();
        break;
      case 51://(binNum == 3)
        bin3();
        break;
      case 52://(binNum == 4)
        bin4();
        break;
      case 53: //5
        trapDoor();
        break;

      case 54://6
        rotateContinous();
        break;

      case 55://7
        rotateStop();
        break;

      case 56://8
        openTrap();
        break;

      case 57://9
        sweep();
        break;

      case 58://10
        resetServo();
      default:
      break;
    }
}

void bin1() {
  //Serial.println("Spinning to bin 1");
  //start spinning servo
  platform.attach(servoPin);
  digitalWrite(powerControl, HIGH);
  platform.write(94);

  //stop when servo reaches first switch
  switchStatus = digitalRead(switchPin1);
  Serial.println(switchStatus); // print switch status

  if(switchStatus == HIGH)
  {
    delay(BIN1TIME);
    digitalWrite(powerControl, LOW);
    platform.detach();
    binNum = 0;
    Serial.println("Positioned");
    Serial.println("Releasing Screw");
    delay(200);
    openTrap();
  }

}

void bin2() {
  //Serial.println("Spinning to bin 2");
  //start spinning servo
  platform.attach(servoPin);
  digitalWrite(powerControl, HIGH);
  platform.write(94);

  //stop when servo reaches first switch
  switchStatus = digitalRead(switchPin1);

  //Serial.println(switchStatus); // print switch status
  if(switchStatus == HIGH)
  {
    delay(BIN2TIME);
    digitalWrite(powerControl, LOW);
    platform.detach();
    binNum = 0;
    Serial.println("Positioned");
    Serial.println("Releasing Screw");
    delay(200);
    openTrap();
    /*for(int i = 0;i<50;i++)
    {
      delay(200);
      resetServo();
    }*/
  }
}

void bin3() {
  //Serial.println("Spinning to bin 3");
  //start spinning servo
  platform.attach(servoPin);
  digitalWrite(powerControl, HIGH);
  platform.write(94);

  //stop when servo reaches first switch
  switchStatus = digitalRead(switchPin2);
  //Serial.println(switchStatus); // print switch status
  if(switchStatus == HIGH)
  {
    //Serial.println(switchStatus);
    delay(BIN3TIME);
    digitalWrite(powerControl, LOW);
    platform.detach();
    binNum = 0;
    Serial.println("Positioned");
    Serial.println("Releasing Screw");
    delay(200);
    openTrap();
    /*for(int i = 0;i<50;i++)
    {
      delay(200);
      resetServo();
    }*/
  }
}

void bin4() {
  //Serial.println("Spinning to bin 4");
  //start spinning servo
  platform.attach(servoPin);
  digitalWrite(powerControl, HIGH);
  platform.write(94);

  //stop when servo reaches first switch
  switchStatus = digitalRead(switchPin2);
  //Serial.println(switchStatus); // print switch status
  if(switchStatus == HIGH)
  {
    delay(BIN4TIME);
    digitalWrite(powerControl, LOW);
    platform.detach();
    binNum = 0;
    Serial.println("Positioned");
    Serial.println("Releasing Screw");
    delay(200);
    openTrap();
    /*for(int i = 0;i<50;i++)
    {
      delay(200);
      resetServo();
    }*/
  }
}

void trapDoor() {
  Serial.println("Nudging Trapdoor");
    trapdoor.write(39);
    delay(50);
    trapdoor.write(47);
    delay(50);
    trapdoor.write(41);
    delay(2000);

  /*  trapdoor.write(40);
    delay(50);
    trapdoor.write(50);
    delay(50);
    trapdoor.write(43);
    delay(2000);

    trapdoor.write(40);
    delay(50);
    trapdoor.write(50);
    delay(50);
    trapdoor.write(43);
    delay(2000);

    trapdoor.write(40);
    delay(50);
    trapdoor.write(50);
    delay(50);
    trapdoor.write(43);
    delay(2000);

    trapdoor.write(40);
    delay(50);
    trapdoor.write(50);
    delay(50);
    trapdoor.write(43);
    delay(2000);
    
    trapdoor.write(46);
    delay(50);
    trapdoor.write(35);
    delay(50);
    trapdoor.write(43);
    delay(2000);

    trapdoor.write(46);
    delay(50);
    trapdoor.write(35);
    delay(50);
    trapdoor.write(43);
    delay(2000);

    trapdoor.write(46);
    delay(50);
    trapdoor.write(35);
    delay(50);
    trapdoor.write(43);
    delay(2000);

    trapdoor.write(46);
    delay(50);
    trapdoor.write(35);
    delay(50);
    trapdoor.write(43);
    delay(2000);

    trapdoor.write(46);
    delay(50);
    trapdoor.write(35);
    delay(50);
    trapdoor.write(43);
    delay(2000);
   
*/   
}

void rotateContinous() {
  Serial.println("Rotating Continuously");
  platform.attach(servoPin);
  digitalWrite(powerControl, HIGH);
  platform.write(180);
}

void rotateStop() {
    Serial.println("Powered down");
    digitalWrite(powerControl, LOW);
    platform.detach();
    binNum = 0;
}

void openTrap() {
  Serial.println("Opening Trapdoor");
  trapdoor.write(0);
  delay(2000);
  trapdoor.write(43);
  binNum = 0;
}

void resetServo() {
  Serial.println("resetting servo");
  //start spinning servo
  platform.attach(servoPin);
  digitalWrite(powerControl, HIGH);
  platform.write(94);

  //stop when servo reaches first switch
  switchStatus = digitalRead(switchPin1);
  //Serial.println(switchStatus); // print switch status
  if(switchStatus == HIGH)
  {
    delay(BIN1TIME);
    digitalWrite(powerControl, LOW);
    platform.detach();
    binNum = 0;
}
}

void sweep() {
  Serial.println("sweeping");
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    trapdoor.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    trapdoor.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  binNum = 0;
}

void stop() {

  if(switchStatus == HIGH)
  {
    delay(BIN4TIME);
    digitalWrite(powerControl, LOW);
    platform.detach();
    binNum = 10;
    Serial.println("Positioned");
    Serial.println("Releasing Screw");
    delay(200);
    openTrap();
  }
}
