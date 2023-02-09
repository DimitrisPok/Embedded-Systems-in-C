//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 3
//Submission code: 8777169671


//variable declaration
const int pinLed1 = 12;    //pin for led (button)
const int pinLed2 = 8;    // pin for led (periodic)
const int pinButton = 2;  // pin for button button 

void setup()
{
  //the led1 (button) pin is for sending the signals out
  pinMode(pinLed1, OUTPUT);
  
  //and the button pin is for input signals
  pinMode(pinButton, INPUT);
  
  //the led2 (periodic) pin is for sending the signals out
  pinMode(pinLed2, OUTPUT);
  
  //attaching the interrupt to the button pin
  //the first parameter sets which pin should be used
  //the second, which function is executed on the interrupt
  //the third is which "event" we listen to
  attachInterrupt(digitalPinToInterrupt(pinButton), 
                  isr, 
                  CHANGE);

}

//loop for pin led2 (period) 
//allows for the led to periodically turn on and off
void loop()
{
 digitalWrite(pinLed2, HIGH);
 delay(1000);
 digitalWrite(pinLed2, LOW);
 delay(1000);
}


//method to make the button turn on/off the led
void isr()
{
  //save the value of the button to a variable
  //used to know whether the button is pressed or not
  int button = digitalRead(pinButton);
  
  // if the button is pressed, we light the led1 (button)
  if (button)
    digitalWrite(pinLed1, HIGH);
  else
    digitalWrite(pinLed1,LOW);
}