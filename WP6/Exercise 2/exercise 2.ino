
// define pin numbers for buzzer
const int trigPin = 7;
const int echoPin = 6;
const int buzzer = 12;
//define led pin numbers
const int led1 = 11;
const int led2 = 10;
const int led3 = 9;
const int led4 = 8;

//set up function
void setup()
{
  //ultrasonic output and input
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  //buzzer output
  pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output
  //Led output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  Serial.begin(9600); // Starts the serial communication
}

//loop function
void loop()
{
  int dist = ultraSonic(); //saving the return value of ultraSonic() to a variable
  if (dist <= 25){ //if distance is less than or equal to 25
    playAnnoyingSound(); //run the play annoying sound method
    blinkAllLEDs(); //and blink all leds

  } else if(dist <= 30){ //if distance is less than or equal to 30
    turnOnLed(); //turn on all leds
  }
  else if(dist <= 200){ //if distance is less than or equal to 200
    int volume = map(dist, 30, 200, 0, 255); //map the distance to the volume level
    buzz(volume); //run the buzzer method
    turnOn1Led(); //and turn on the first led
  } else{ //otherwise 
    turnOffLed(); //turn off all leds
  }
  delay(500); //added delay to slow down serial print
}

//method to turn on the first led
void turnOn1Led()
{
  digitalWrite(led1, HIGH); //turn on first led
}

//method to turn on all leds
void turnOnLed()
{
  digitalWrite(led1, HIGH); //turn on first led
  digitalWrite(led2, HIGH); //turn on second led
  digitalWrite(led3, HIGH); //turn on third led
  digitalWrite(led4, HIGH); //turn on fourth led
}

//method to turn of all leds
void turnOffLed()
{
    digitalWrite(led1, LOW); //turn off first led
    digitalWrite(led2, LOW); //turn off second led
    digitalWrite(led3, LOW); //turn off third led
    digitalWrite(led4, LOW); //turn off fourth led
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
    digitalWrite(buzzer, HIGH); //turn on buzzer
    delay(100); //delay for 100 ms
    digitalWrite(buzzer, LOW); // turn off buzzer
    delay(100); //delay for 100 ms
  }

//method to tone the buzzer (takes in a volume)
void buzz(int vol) {
  tone(buzzer, 440, vol); //tone buzzer according to volume which is decided by maping the distance
}

//method to calculate the distance using the ultrasonic sensor
int ultraSonic()
{
  // define variables
  long duration;
  int distance;
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance; //return distance to use the value in the if-statements 
}