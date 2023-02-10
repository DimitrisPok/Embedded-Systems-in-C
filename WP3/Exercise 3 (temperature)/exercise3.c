//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 3
//Submission code: 8777169671


//variable declaration
int sensorPin = 0; //for analog reading
int redPin = 12; //for the red led
int greenPin = 11; //for the green led
int bluePin = 10; //for the blue led

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
 //getting the voltage reading from the temperature sensor
 int reading = analogRead(sensorPin); 
 
 //getting the voltage and saving it to variable volt
 float volt = reading * 5.0195;
 volt /= 1024.0; 
 float voltage= volt*1000; //turn the voltage to mV unit 

 
 // now print out the temperature
 float temperatureC = (voltage - 500) / 10 ;  //converting the voltage to temperature in Celsius
 Serial.print(temperatureC); Serial.println(" degrees C");
  
  //check if the temperature is less than -12
  if (temperatureC<=-12){
    digitalWrite(bluePin, HIGH); //if so, turn the blue led on
    //make sure the other leds are off in this condition
    digitalWrite(redPin, LOW); 
    digitalWrite(greenPin, LOW);
  }
  //check if the temperature is greater than 21
  else if (temperatureC>=21){
    digitalWrite(redPin, HIGH); //if so, turn the red led on
    //make sure the other leds are off in this condition
    digitalWrite(bluePin, LOW);
    digitalWrite(greenPin, LOW);
  }
  //otherwise the green led should be on
  else{
    digitalWrite(greenPin, HIGH);
    //make sure the other leds are off in this condition
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, LOW);
  }
  

}