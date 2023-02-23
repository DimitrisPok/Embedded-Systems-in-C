//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 5
//Submission code: 3049288291

#include <DHT.h>

//variable declaration
int lightAnalog = A0; //for analog reading
int temperatureAnalog = A1; //for analog reading
int redPin = 4; //for the red led
int greenPin = 5; //for the green led
int bluePin = 6; //for the blue led

//object for DHT
DHT dht(A1, DHT11);

void setup()
{
  
  Serial.begin(9600); // Initialize serial communication at 9600
  dht.begin(); //DHT begin
  pinMode (redPin, OUTPUT); //send the pin output for the red led
  pinMode (greenPin, OUTPUT); //send the pin output for the green led
  pinMode (bluePin, OUTPUT); //send the pin output for the blue led
    
  pinMode(lightAnalog, INPUT); 
  pinMode(temperatureAnalog, INPUT);
  
}

void loop()
{ 
  float temperatureC = dht.readTemperature(); // Change it to float type
  int lightIntensity = analogRead(lightAnalog);

  (lightAnalog); //Reads the analog value of the light sensor

  lightIntensity = map(lightIntensity, 6, 679, 0, 100); // Changes the light value to percentage value
  
  
  Serial.println(temperatureC); Serial.println(" degrees C");// Prints the temperature in Celsius
  Serial.println(lightIntensity); Serial.println("%");// Print the light
  delay(500);
  
  //if the light intensity is 0
  if(lightIntensity==0){
    //if the temperature is -12 or higher
    if(temperatureC>=-12){
      digitalWrite(redPin, HIGH); //turn the red led on
      //make sure the other leds are off in this condition
      digitalWrite(bluePin, LOW);
      digitalWrite(greenPin, LOW);
      //if the temperature between -12-0
    } else if (temperatureC>=-12 && temperatureC<=0) {
      digitalWrite(greenPin, HIGH); //turn the green led on
      //make sure the other leds are off in this condition
      digitalWrite(redPin, LOW);
      digitalWrite(bluePin, LOW);
    } else{ //blue led on
      digitalWrite(bluePin, HIGH);
      //make sure the other leds are off in this condition
      digitalWrite(redPin, LOW); 
      digitalWrite(greenPin, LOW);
    }
    //if the light intensity is 1-20
  } else if (lightIntensity>=1 && lightIntensity<=20){
    //if the temperature is less than -12
    if(temperatureC<-12){
      digitalWrite(bluePin, HIGH); //turn the blue led on
      //make sure the other leds are off in this condition
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      //if the temperature between -12-0
    } else if (temperatureC>=-12 && temperatureC<=0) {
      digitalWrite(greenPin, HIGH); //turn the green led on
      //make sure the other leds are off in this condition
      digitalWrite(redPin, LOW);
      digitalWrite(bluePin, LOW);
    } else { //red led on 
      digitalWrite(redPin, HIGH);
      //make sure the other leds are off in this condition
      digitalWrite(bluePin, LOW); 
      digitalWrite(greenPin, LOW);
    }
    //if the light intensity is 21-60
  } else if (lightIntensity>=21 && lightIntensity<=60){
    //if the temperature is less than 0
    if(temperatureC<0){
      digitalWrite(bluePin, HIGH); //turn the blue led on
      //make sure the other leds are off in this condition
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      //if the temperature between 0-20
    } else if (temperatureC>=0 && temperatureC<=20) {
      digitalWrite(greenPin, HIGH);
      //make sure the other leds are off in this condition
      digitalWrite(redPin, LOW);
      digitalWrite(bluePin, LOW);
    } else { //red led on
      digitalWrite(redPin, HIGH);
      //make sure the other leds are off in this condition
      digitalWrite(bluePin, LOW); 
      digitalWrite(greenPin, LOW);
    }
    //if the light intensity is 61-100
  } else if (lightIntensity>=61 && lightIntensity<=100){
    //if the temperature is less than 21
    if(temperatureC<21){
      digitalWrite(redPin, HIGH); //turn the red led on
      //make sure the other leds are off in this condition
      digitalWrite(bluePin, LOW);
      digitalWrite(greenPin, LOW);
      //if the temperature is greater than or equal to 21
    } else if (temperatureC>=21) {
      digitalWrite(greenPin, HIGH); //turn the green led on
      //make sure the other leds are off in this condition
      digitalWrite(redPin, LOW);
      digitalWrite(bluePin, LOW);
    }
  }
}