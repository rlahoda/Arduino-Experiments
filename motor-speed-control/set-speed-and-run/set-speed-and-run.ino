/*
 * This is set up for 3 buttons to set a motor speed and trigger a sequence
 * 
 * The buttons should be wired to pins 7-9 with the input connected to 5v and the output to ground 
 * while the connection to the pin is inline with the 5v. When the button is pressed, 
 * the circuit is connected to ground, voltage drops, and the press is registered
 */

// Variables
int motorSpeed = 5;

int buttonUp = 7;
int buttonDown = 8;
int buttonStart = 9;
int buttonUpState;
int buttonDownState = 0;
int buttonStartState = 0;

bool motorsRunning = false;

#define MOTORS 9 // pwm output for motor control

void setup()
{
  pinMode(buttonUp, INPUT);    // initialize button as an input
  pinMode(buttonDown, INPUT);  // initialize button as an input
  pinMode(buttonStart, INPUT); // initialize button as an input
  Serial.begin(9600);
  digitalWrite(buttonStart, HIGH);
}

void loop()
{

  buttonUpState = digitalRead(buttonUp);
  if (buttonUpState == LOW) {
    delay(300);
    if (motorSpeed + 1 >= 99) {
      motorSpeed = 99;
    } else {
      motorSpeed = motorSpeed + 1;
    }
  }
  buttonDownState = digitalRead(buttonDown);
  if (buttonDownState == LOW) {
    delay(300);
    if (motorSpeed - 1 <= 0) {
      motorSpeed = 0;
    } else {
      motorSpeed = motorSpeed - 1;
    }
  }

  buttonStartState = digitalRead(buttonStart);
  if (buttonStartState == LOW && motorsRunning != true) {
    motorsRunning = true;
    motorRun();
  }


  //  Serial.println(buttonUpState);
  //  Serial.println(motorSpeed);
  // buttons to increase and decrease value of "motorSpeed"
  // button to start motorRun()
  // Serial.println(motorsRunning);
}

void motorRun()
{
  // when triggered, ramp the motors from 0 to motorSpeed, hold for 3sec, then ramp down to 0
  Serial.println("starting");
  int x = 1;
  for (int i = 0; i > -1; i = i + x) {
    analogWrite(MOTORS, i);
    //    Serial.println(i);
    if (i == motorSpeed) {
      delay(3000); // hold there 3 sec
      x = -1;  // switch direction at peak
    }
    delay(10);
  }
  motorsRunning = false;
  Serial.println("done");
}
