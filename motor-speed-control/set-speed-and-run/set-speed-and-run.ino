// Variables
int motorSpeed = 50;

int buttonUp = 7;
int buttonDown = 8;
int buttonStart = 9;

#define MOTORS 9 // pwm output for motor control

void setup()
{
  pinMode(buttonUp, INPUT);    // initialize button as an input
  pinMode(buttonDown, INPUT);  // initialize button as an input
  pinMode(buttonStart, INPUT); // initialize button as an input
}

void loop()
{
  // put your main code here, to run repeatedly:
  // buttons to increase and decrease value of "motorSpeed"
  // button to start motorRun()
}

void motorRun()
{
  // when triggered, ramp the motors from 0 to motorSpeed, hold for 3sec, then ramp down to 0
  // serial write "starting"
  int x = 1;
  for (int i = 0; i > -1; i + x) // ramp up
  {
    analogWrite(MOTORS, i);
    // serial write i
    delay(10);
    if (i = motorSpeed) // when the value gets to the set speed...
    {
      delay(3000); // hold there 3 sec
      x = -1;      // switch to subtracting values to ramp down
    }
  }
  // serial write "done"
}
