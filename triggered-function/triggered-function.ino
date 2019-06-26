
/*
This replicates the blink example but tells the led to blink once after a delay of 1sec
 */
const int buttonPin = A0;  // Reading Push Button switch
const int LED_OUTPUT = 13; // LED output
bool blinking = false;
int buttonState = 0;

// the setup function runs once when you press reset or power the board
void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(LED_OUTPUT, OUTPUT);
  Serial.begin(9600);
}

void loop()
{

  buttonState = analogRead(buttonPin); // For some reason my button would not be on or off, it would give values between. So I switched to an analog read and could set the value to on == 1023

  Serial.println(buttonState);
  if (buttonState == 1023 && blinking != true)
  {
    blinking = true;
    // start function
    blink();
  }
}

void blink()
{
  delay(1000);                     // wait for a second
  digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000);                     // wait for a second
  digitalWrite(LED_BUILTIN, LOW);
  blinking = false; // turn the LED off by making the voltage LOW
}
