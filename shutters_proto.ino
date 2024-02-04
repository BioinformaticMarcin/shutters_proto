// this constant won't change:
const int buttonPinUP = 9;  // the pin that the pushbutton is attached to
const int buttonPinDOWN = 10;  // the pin that the pushbutton is attached to
const int ledPinTestUP = 2;    // the pin that the LED is attached to
const int ledPinTestDOWN = 3;    // the pin that the LED is attached to

// Variables will change:
int buttonState = 0;
// int buttonUpState = 0;        // current state of the button
// int buttonDownState = 0;        // current state of the button

int lastButtonUpState = 0;    // previous state of the button
int lastButtonDownState = 0;    // previous state of the button

int ledUpState = 0;
int ledDownState = 0;

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPinUP, INPUT);
  pinMode(buttonPinDOWN, INPUT);
  // initialize the LED as an output:
  pinMode(ledPinTestUP, OUTPUT);
  pinMode(ledPinTestDOWN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  lastButtonUpState = buttonPush(buttonPinUP, lastButtonUpState);
  lastButtonDownState = buttonPush(buttonPinDOWN, lastButtonDownState);


  digitalWrite(ledPinTestUP, lastButtonUpState);
  digitalWrite(ledPinTestDOWN, lastButtonDownState);

}

int buttonPush(int buttonPin, int lastButtonState) {
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      Serial.println("on");
      changeLed(buttonPin)
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  return buttonState;
}

void changeLed(int buttonPin) {
    digitalWrite(convert(buttonPin), lastButtonState);
}

int convert(int buttonPin){
  switch (buttonPin) {
    case buttonPinUP:
      return ledPinTestUP;
    case ledPinTestUP:
      return buttonPinUP;
    case buttonPinDOWN:
      return ledPinTestDOWN;
    case ledPinTestDOWN:
      return buttonPinDOWN;
  }
}


