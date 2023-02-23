//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 5
//Submission code: 3049288291

#include <DHT.h>

//define for serial
#define DATA_RATE 9600 		//Define data rate for Serial

//define for temperatures
#define TEMP_1 0           //Define temp range = 0
#define TEMP_2 25          //Define temp range = 25
#define TEMP_3 50          //Define temp range = 50
#define TEMP_4 75          //Define temp range = 75
#define TEMP_5 100         //Define temp range = 100

//define for digital pins
#define WHITE 2           //Define LED pin = 2
#define BLUE 3            //Define LED pin = 3
#define GREEN 8           //Define LED pin = 8
#define YELLOW 9          //Define LED pin = 9
#define RED 10             //Define LED pin = 10

//object for DHT
DHT dht(A0, DHT11);

void setup()
{
  Serial.begin(DATA_RATE); //Starts serial with defined data rate

  dht.begin(); //DHT begin
  
  pinMode(WHITE, OUTPUT);  //Set white led pinMode as OUTPUT
  pinMode(BLUE, OUTPUT);   //Set blue led pinMode as OUTPUT
  pinMode(GREEN, OUTPUT);  //Set green led pinMode as OUTPUT
  pinMode(YELLOW, OUTPUT); //Set yellow led pinMode as OUTPUT
  pinMode(RED, OUTPUT);    //Set red led pinMode as OUTPUT
  

}


void loop()
{
  float tempC = dht.readTemperature(); // Change it to float type
  delay(1000);
  //serial print temperature
  Serial.print(tempC); Serial.println(" degrees C");
  	  if (tempC < TEMP_1) {          //if temp is less than 0
    	 digitalWrite(WHITE, LOW);    //set white led to LOW 
         digitalWrite(BLUE, LOW);   //set blue led to LOW
         digitalWrite(GREEN, LOW);  //set green led to LOW
         digitalWrite(YELLOW, LOW); //set yellow led to LOW
         digitalWrite(RED, LOW);    //set red led to LOW
  	}
  
  	  else if (tempC >= TEMP_1 && tempC <= TEMP_2){ //if temp is greater than or equal to 0 and less than or equal to 25
         digitalWrite(WHITE, HIGH);                //set white led to HIGH, all other leds to LOW
         digitalWrite(BLUE, LOW);
         digitalWrite(GREEN, LOW);
         digitalWrite(YELLOW, LOW);
         digitalWrite(RED, LOW);
      }
      else if (tempC >= TEMP_2 && tempC <= TEMP_3){ //if temp is greater than or equal to 25 and less than or equal to 50
         digitalWrite(WHITE, HIGH);                 //set white and blue led to HIGH 
         digitalWrite(BLUE, HIGH);
         digitalWrite(GREEN, LOW);
         digitalWrite(YELLOW, LOW);
         digitalWrite(RED, LOW);
      }
      else if (tempC >= TEMP_3 && tempC <= TEMP_4){ //if temp is greater than or equal to 50 and less than or equal to 75
         digitalWrite(WHITE, HIGH);                 //set white, blue, and green led to HIGH
         digitalWrite(BLUE, HIGH);
         digitalWrite(GREEN, HIGH);
         digitalWrite(YELLOW, LOW);
         digitalWrite(RED, LOW);
      }
      else if (tempC >= TEMP_4 && tempC <= TEMP_5){ //if temp is greater than or equal to 75 and less than or equal to 100
         digitalWrite(WHITE, HIGH);                 //set white, blue, green, and yellow to HIGH
         digitalWrite(BLUE, HIGH);
         digitalWrite(GREEN, HIGH);
         digitalWrite(YELLOW, HIGH);
         digitalWrite(RED, LOW);
      }
      else if (tempC >= TEMP_5){                   //if temp is greater than or equal to 100
         digitalWrite(WHITE, HIGH);                //set all 5 leds to HIGH
         digitalWrite(BLUE, HIGH);
         digitalWrite(GREEN, HIGH);
         digitalWrite(YELLOW, HIGH);
         digitalWrite(RED, HIGH);
      }
}
