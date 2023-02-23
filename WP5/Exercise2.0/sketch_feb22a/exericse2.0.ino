//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 3
//Submission code: 8777169671

#include <dht11.h> 

//variable declaration
int lightAnalog = 0; //for analog reading
int temperatureAnalog = 1; //for analog reading
int redPin = 4; //for the red led
int greenPin = 5; //for the green led
int bluePin = 6; //for the blue led

void setup()
{
  Serial.begin(9600);
  pinMode (redPin, OUTPUT); //send the pin output for the red led
  pinMode (greenPin, OUTPUT); //send the pin output for the green led
  pinMode (bluePin, OUTPUT); //send the pin output for the blue led
}


void loop()
{
  delay(500);
//save analog reading from the temperature sensor to a variable
 int readTemp = analogRead(temperatureAnalog);
 //convert read to celsius
 int temperatureC = map(((readTemp - 20) * 3.04), 0, 1023, -40, 125);
 
 //serial print temperature
 Serial.print(temperatureC); Serial.println(" degrees C");
  
 int readLight = analogRead(lightAnalog); //Read the analog value of the photoresistor
 int lightIntensity = map(readLight,6,679,0,100); //convert the value to be in the range of 0-100
 //serial print light intensity
 Serial.print(lightIntensity); Serial.println("%");
  
  
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