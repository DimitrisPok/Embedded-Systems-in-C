//neopixel library import
#include <Adafruit_NeoPixel.h> 

//variable declaration
int sensorAnalog = 0; //for analog reading
int neoPin = 3; //neopixel digital pin
int pixelNum = 24; //number of pixels
int maxled; //maxled variable initialization
int ledPin = 2; 
//neopixel object declaration
Adafruit_NeoPixel neopixel = Adafruit_NeoPixel(pixelNum, neoPin, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600); //serial begin
  pinMode (ledPin, OUTPUT); //ledPin output
  neopixel.begin(); //neopixel start
  neopixel.setBrightness(255); //set neopixel to max brightness
  neopixel.show(); //neopixel show
}

void loop()
{
 
 //save analog reading from the temperature sensor to a variable
 int read = analogRead(sensorAnalog);
 //convert read to celsius
 int temperatureC = map(((read - 20) * 3.04), 0, 1023, -40, 125);
 
 //serial print temperature
 Serial.print(temperatureC); Serial.println(" degrees C");
 
 //allocating the temperature to the led (max pixel number/ max temperature)
 maxled= read*pixelNum/358;
 
 //color variables
 uint32_t red = neopixel.Color(255, 0, 0); //red
 uint32_t green = neopixel.Color(0, 255, 0);//green
 uint32_t blue = neopixel.Color(0, 0, 255); //blue
 uint32_t orange = neopixel.Color(255, 100, 10); //orange
 uint32_t magenta = neopixel.Color(255, 0, 255); //magenta
  
  //for each pixel in the neopixel 
  for (int i=0; i<pixelNum; i++){
    //if i (the pixel we are currently on) is less than maxled..
    if(i<=maxled){
      //..set the pixel color
      //allocate the color to the temperature intervals
      if (temperatureC<=-25){ 
         neopixel.setPixelColor(i, blue);
      }
      else if (temperatureC<=0){
        neopixel.setPixelColor(i, magenta);
      }
      else if (temperatureC<=25) {
        neopixel.setPixelColor(i, green);
      }
      else if (temperatureC<=50){
        neopixel.setPixelColor(i, orange);
      }
      else{
        neopixel.setPixelColor(i, red);
      }
    } else {
      neopixel.setPixelColor(i,0,0,0); //turn off the neopixel
      digitalWrite(ledPin, HIGH); //turn on the red led
   	}
  }
  delay(100); //delay by 100 ms
  neopixel.show(); //neopixel show
}