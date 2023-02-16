// C code

#define DATA_RATE 9600 		//Define data rate for Serial

#define TEMP_1 0           //Define temp range = 0
#define TEMP_2 25          //Define temp range = 25
#define TEMP_3 50          //Define temp range = 50
#define TEMP_4 75          //Define temp range = 75
#define TEMP_5 100         //Define temp range = 100

#define WHITE 3           //Define LED pin = 3
#define BLUE 4            //Define LED pin = 4
#define GREEN 5           //Define LED pin = 5
#define YELLOW 6          //Define LED pin = 6
#define RED 7             //Define LED pin = 7
  
void setup()
{
  setup_timer_1();         //Calls function
  Serial.begin(DATA_RATE); //Starts serial with defined data rate
  
  pinMode(WHITE, OUTPUT);  //Set white led pinMode as OUTPUT
  pinMode(BLUE, OUTPUT);   //Set blue led pinMode as OUTPUT
  pinMode(GREEN, OUTPUT);  //Set green led pinMode as OUTPUT
  pinMode(YELLOW, OUTPUT); //Set yellow led pinMode as OUTPUT
  pinMode(RED, OUTPUT);    //Set red led pinMode as OUTPUT
  

}

void setup_timer_1()
{
  cli(); //stops interrupts
  
  //set timer1 interrupt at 1Hz
  TCCR1A = 0;  // set entire TCCR1A register to 0
  TCCR1B = 0;  // same for TCCR1B
  TCNT1  = 0;  //initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;  // = (16*10^6) / (1*1024) - 1 (<65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  
  sei(); //allows interrupts
}

void loop()
{
  //empty
}

ISR(TIMER1_COMPA_vect) //interrupt code below
{
  int read = analogRead(A0); //reads analog data from temp sensor
  int tempC = map(((read - 20) * 3.04), 0, 1023, -40, 125); //converts analog data to celsius
 
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