/*
  The circuit:
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
   LCD R/W pin to ground
   LCD VSS pin to ground
   LCD VCC pin to 5V
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int motorSpeed = 50;

const int buttonUp = 7; // Button to increase the value of the motor speed
const int buttonDown = 8; // Button to decrease the value of the motor speed
const int buttonStart = 9; // Button to start the motor sequence
int buttonUpState = 0;
int buttonDownState = 0;
int buttonStartState = 0;
char off[4] = "Off";
char on[4] = "On "; // The extra space is there so the last "f" from "off" won't stay visible

// These following lines are custom characters generated here: https://maxpromer.github.io/LCD-Character-Creator/
// They create up and down arrows as well as inverted up and down arrows
byte arrowUp[] = {
  B00100,
  B01110,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};

byte arrowUpInverted[] = {
  B11011,
  B10001,
  B00000,
  B11011,
  B11011,
  B11011,
  B11011,
  B11011
};

byte arrowDown[] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B11111,
  B01110,
  B00100
};

byte arrowDownInverted[] = {
  B11011,
  B11011,
  B11011,
  B11011,
  B11011,
  B00000,
  B10001,
  B11011
};

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(buttonUp, INPUT);    // initialize button as an input
  pinMode(buttonDown, INPUT);  // initialize button as an input
  pinMode(buttonStart, INPUT); // initialize button as an input
  lcd.createChar(0, arrowUp);
  lcd.createChar(1, arrowUpInverted);
  lcd.createChar(2, arrowDown);
  lcd.createChar(3, arrowDownInverted);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  lcd.print("Speed: ");
  lcd.print(motorSpeed);

  lcd.setCursor(0, 1);
  lcd.write(byte(0));// this displays the up arrow

  lcd.setCursor(5, 1);
  lcd.write(byte(2)); // this displays the down arrow

  lcd.setCursor(10, 1);
  lcd.print("!");

  buttonUpState = digitalRead(buttonUp);
  if (buttonUpState == LOW) {
    lcd.setCursor(5, 1);
    lcd.write(byte(3)); // this switches the arrow to inverted when the button is pressed
    lcd.print(on);
    delay(300);
    if (motorSpeed + 1 >= 99) {
      motorSpeed = 99;
    } else {
      motorSpeed = motorSpeed + 1;
    }
  } else {
    lcd.setCursor(6, 1);
    lcd.print(off);
  }

  buttonDownState = digitalRead(buttonDown);
  if (buttonDownState == LOW) {
    lcd.setCursor(0, 1);
    lcd.write(byte(1)); // this switches the arrow to inverted when the button is pressed
    lcd.print(on);
    delay(300);
    if (motorSpeed - 1 <= 0) {
      motorSpeed = 0;
    } else {
      motorSpeed = motorSpeed - 1;
    }
  } else {
    lcd.setCursor(1, 1);
    lcd.print(off);
  }

  buttonStartState = digitalRead(buttonStart);
  if (buttonStartState == LOW ) {

    lcd.setCursor(11, 1);
    lcd.print(on);

  } else {
    lcd.setCursor(11, 1);
    lcd.print(off);
  }



}
