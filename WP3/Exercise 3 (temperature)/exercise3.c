//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 3
//Submission code: 8777169671


//variable declaration
int pin13 = 13;
int sensorPin = 0; //for analog reading
int sensorPin1 = 1;

void setup()
{
  Serial.begin(9600); //serial begin
  pinMode(pin13, OUTPUT); //set the output
}

void loop()
{
  delay(500);
 //getting the voltage reading from the temperature sensor
 int reading = analogRead(sensorPin); 
 int readingProx = analogRead(sensorPin1);
 //printing the sensor proximity
 Serial.print("Proximity: "); 
 Serial.println(readingProx); 
 
 //getting the voltage and saving it to variable volt
 float volt = reading * 5.0195;
 volt /= 1024.0; 
 //print out the voltage
 Serial.print(volt); Serial.println(" volts");
 
 //now print out the temperature
 float temperatureC = (volt - 0.5) * 100 ;  //converting the voltage to temperature in Celsius
 Serial.print(temperatureC); Serial.println(" degrees C");
}