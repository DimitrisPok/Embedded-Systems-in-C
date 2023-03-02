//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 6
//Submission code: 2599643369

//max distance 200cm
//min distance 25cm
//all 4 leds when distance less than 30cm
//only 1 led when distance less than 200cm
//tone activated when object closer than 200cm & gets louder the close the object gets
//when closer than 25cm, all leds should blink and tone should be super annoying
//through individual functions

//-----------------------------------------------------------------------------------------//

//define pin numbers for ultrasonic sensor
const int TRIG_PIN = 7;
const int ECHO_PIN = 6;
//define pin number for buzzer
const int BUZZER = 12;
//define led pin numbers
const int LED_1 = 11;
const int LED_2 = 10;
const int LED_3 = 9;
const int LED_4 = 8;

//set up function
void setup()
{
  //ultrasonic output and input
  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input
  //buzzer output
  pinMode(BUZZER, OUTPUT);//initialize the buzzer pin as an output
  //Led output
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);

  Serial.begin(9600); // Starts the serial communication
}

//loop function
void loop()
{
  int dist = ultraSonic(); //saving the return value of ultraSonic() to a variable
  if (dist <= 25){ //if distance is less than or equal to 25
    playAnnoyingSound(); //run the play annoying sound method
    blinkAllLEDs(); //and blink all leds
  } 
  else if(dist <= 30){ //if distance is less than or equal to 30 
    buzz1(); 
    turnOnLed(); //turn on all leds
  }
  else if(dist <= 50){ //if distance is less than or equal to 50
    buzz();
    turnOn3Leds(); //and turn on 3 leds
  }
  else if(dist <= 100){ //if distance is less than or equal to 100
    buzz2();
    turnOn2Leds(); //and turn on the 2 leds
  }
  else if(dist <= 200){ //if distance is less than or equal to 200
    buzz3();
    turnOn1Led(); //and turn on the first led
  } 
  else{ //otherwise
    turnOffLed(); //turn off all leds
    noTone(BUZZER); //stop the tone emitted from the buzzer
  }
  delay(500); //added delay to slow down serial print
}

//turn on the first led
void turnOn1Led()
{
  digitalWrite(LED_1, HIGH); //turn on first led
}

//turn on two leds
void turnOn2Leds()
{
  digitalWrite(LED_1, HIGH); //turn on first led
  digitalWrite(LED_2, HIGH); //turn on second led
  digitalWrite(LED_3, LOW); //turn off third led
  digitalWrite(LED_4, LOW); //turn off fourth led  
}

//turn on three leds
void turnOn3Leds()
{
  digitalWrite(LED_1, HIGH); //turn on first led
  digitalWrite(LED_2, HIGH); //turn on second led
  digitalWrite(LED_3, HIGH); //turn on third led
  digitalWrite(LED_4, LOW); //turn off fourth led
}

//turn on all four leds
void turnOnLed()
{
  digitalWrite(LED_1, HIGH); //turn on first led
  digitalWrite(LED_2, HIGH); //turn on second led
  digitalWrite(LED_3, HIGH); //turn on third led
  digitalWrite(LED_4, HIGH); //turn on fourth led
}

//method to turn off all leds
void turnOffLed()
{
    digitalWrite(LED_1, LOW); //turn off first led
    digitalWrite(LED_2, LOW); //turn off second led
    digitalWrite(LED_3, LOW); //turn off third led
    digitalWrite(LED_4, LOW); //turn off fourth led
}

//method to make all leds blink
void blinkAllLEDs() {
    turnOnLed(); //turn on all leds
    delay(100); //delay for 100 ms
    turnOffLed(); //turn off all leds
    delay(100); //delay for 100 ms
}

//method to play annoying buzzing sound
void playAnnoyingSound() {
    digitalWrite(BUZZER, HIGH); //turn on buzzer
    delay(100); //delay for 100 ms
  }

void buzz() {
  tone(BUZZER, 440, 100); //tone buzzer according to specified frequency and duration
}


void buzz1() {
  tone(BUZZER, 140, 200); //tone buzzer according to specified frequency and duration
}

void buzz2() {
  tone(BUZZER, 240, 400); //tone buzzer according to specified frequency and duration
  delay(500);             //delay between tones
}

void buzz3() {
  tone(BUZZER, 340, 600); //tone buzzer according to specified frequency and duration
  delay(1000);            //delay between tones
}

//method to calculate the distance using the ultrasonic sensor
int ultraSonic()
{
  // define variables
  long duration;
  int distance;
  // Clears the trigPin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance; //return distance to use the value in the if-statements 
}