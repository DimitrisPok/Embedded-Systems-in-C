// C code

#define DATA_RATE 9600 		//Define data rate for Serial

#define TEMP_1 0
#define TEMP_2 25
#define TEMP_3 50
#define TEMP_4 75
#define TEMP_5 100

#define WHITE 3
#define BLUE 4
#define GREEN 5
#define YELLOW 6
#define RED 7
  
void setup()
{
  setup_timer_1();
  Serial.begin(DATA_RATE);
  
  pinMode(WHITE, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  

}

void setup_timer_1()
{
  cli(); //stops interrupts
  
  //set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
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

ISR(TIMER1_COMPA_vect) 
{
  int read = analogRead(A0);
  int tempC = map(((read - 20) * 3.04), 0, 1023, -40, 125);
 
  //serial print temperature
  Serial.print(tempC); Serial.println(" degrees C");
  	  if (tempC < TEMP_1) {
    	 digitalWrite(WHITE, LOW);
         digitalWrite(BLUE, LOW);
         digitalWrite(GREEN, LOW);
         digitalWrite(YELLOW, LOW);
         digitalWrite(RED, LOW);
  	}
  
  	  else if (tempC >= TEMP_1 && tempC <= TEMP_2){ 
         digitalWrite(WHITE, HIGH);
         digitalWrite(BLUE, LOW);
         digitalWrite(GREEN, LOW);
         digitalWrite(YELLOW, LOW);
         digitalWrite(RED, LOW);
      }
      else if (tempC >= TEMP_2 && tempC <= TEMP_3){
         digitalWrite(WHITE, HIGH);
         digitalWrite(BLUE, HIGH);
         digitalWrite(GREEN, LOW);
         digitalWrite(YELLOW, LOW);
         digitalWrite(RED, LOW);
      }
      else if (tempC >= TEMP_3 && tempC <= TEMP_4) {
         digitalWrite(WHITE, HIGH);
         digitalWrite(BLUE, HIGH);
         digitalWrite(GREEN, HIGH);
         digitalWrite(YELLOW, LOW);
         digitalWrite(RED, LOW);
      }
      else if (tempC >= TEMP_4 && tempC <= TEMP_5){
         digitalWrite(WHITE, HIGH);
         digitalWrite(BLUE, HIGH);
         digitalWrite(GREEN, HIGH);
         digitalWrite(YELLOW, HIGH);
         digitalWrite(RED, LOW);
      }
      else if (tempC >= TEMP_5){
         digitalWrite(WHITE, HIGH);
         digitalWrite(BLUE, HIGH);
         digitalWrite(GREEN, HIGH);
         digitalWrite(YELLOW, HIGH);
         digitalWrite(RED, HIGH);
      }

}