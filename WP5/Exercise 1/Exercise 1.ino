//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 5
//Submission code: 3049288291

//variable declaration
const int redPin = 8; //Red LED digital pin
const int bluePin = 7; //Blue LED digital pin

void setup()
{
  pinMode(bluePin, OUTPUT);    // blue LED output
  pinMode(redPin, OUTPUT);    // red LED output

  digitalWrite(bluePin, LOW); // digital write blue LED (off)
  digitalWrite(redPin, LOW); // digital write red LED (off)
}

void loop()
{
  digitalWrite(bluePin, HIGH);    // digital write blue LED (on)
  digitalWrite(redPin, HIGH);    // digital write red LED (on)

  //RED PIN BLINKING
  delay(1000); // delay (1000 ms)
  digitalWrite(redPin, LOW);        // turn off red LED
  delay(1000); //delay (1000 ms)
}