
const int pinLed1 = 12;
const int pinLed2 = 8;
const int pinButton = 2;

void setup()
{

  pinMode(pinLed1, OUTPUT);
  
  pinMode(pinButton, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(pinButton), 
                  isr, 
                  CHANGE);
  pinMode(pinLed2, OUTPUT);
}


void loop()
{
 digitalWrite(pinLed2, HIGH);
 delay(1000);
 digitalWrite(pinLed2, LOW);
 delay(1000);
}


void isr()
{
  int button = digitalRead(pinButton);
  
  if (button)
    digitalWrite(pinLed1, HIGH);
  else
    digitalWrite(pinLed1,LOW);
}