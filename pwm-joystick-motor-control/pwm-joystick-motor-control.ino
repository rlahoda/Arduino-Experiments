/*
Controlling a motor or motors using an analog joystick
on the x-axis to control speed
*/

#define MOTORS 9  // pwm output for motor control
int potpin = A0;  // analog pin used to connect the x-axis of the joystick
int val;          // variable to read the value from the analog pin

void setup() {
  pinMode(MOTORS, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(potpin);          // read the value from the joystick 
  val = map(val, 512, 1023, 0, 255); // map the value from the halfway point (approximately center of the joystick) to zero
                                     // and full to 255 on the pwm
  if (val <= 0 ){                    // check to see if the value coming from the joystick is mapped to less than zero
    val = 0;                         // if it is, set it to zero
  }
  analogWrite(MOTORS, val);          // write the pwm value to the pin controlling the motors
  Serial.println(val);
}
