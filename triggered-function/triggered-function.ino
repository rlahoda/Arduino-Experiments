
/*
  This replicates the blink example but tells the led to blink once after a delay of 1sec
*/
const int buttonPin = A0;  // Reading Push Button switch
const int LEDOut = 13; // LED output
bool blinking = false;
int buttonState = 0;

// the setup function runs once when you press reset or power the board
void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(LEDOut, OUTPUT);
  digitalWrite(buttonStart, HIGH);
  Serial.begin(9600);
}

void loop()
{

  buttonState = digitalRead(buttonPin);
  // After some research I found that I can configure my circuit differently and get a more reliable result
  // So the button has 5v in passing through to the pin and the output is to ground
  // When the button is pushed, the circuit is opened to ground, causing the voltage to drop to LOW

  Serial.println(buttonState);
  if (buttonState == LOW && blinking != true)
  {
    blinking = true;
    // start function
    blink();
  }
}

void blink()
{
  delay(1000);                     // wait for a second
  digitalWrite(LEDOut, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000);                     // wait for a second
  digitalWrite(LEDOut, LOW);
  blinking = false; // turn the LED off by making the voltage LOW
}
