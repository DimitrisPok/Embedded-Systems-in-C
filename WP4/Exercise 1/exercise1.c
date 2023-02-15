// C code

#define DATA_RATE 9600 		//Define data rate for Serial

int LED_1 = 3;
int LED_2 = 4;
int LED_3 = 5;
int LED_4 = 6;
int LED_5 = 7;
  
void setup()
{
  setup_timer_1();
  Serial.begin(DATA_RATE);
  
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
  

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
       if (tempC<=-25){ 
         digitalWrite(LED_1, HIGH);
         digitalWrite(LED_2, LOW);
         digitalWrite(LED_3, LOW);
         digitalWrite(LED_4, LOW);
         digitalWrite(LED_5, LOW);
      }
      else if (tempC<=0){
         digitalWrite(LED_1, HIGH);
         digitalWrite(LED_2, HIGH);
         digitalWrite(LED_3, LOW);
         digitalWrite(LED_4, LOW);
         digitalWrite(LED_5, LOW);
      }
      else if (tempC<=25) {
         digitalWrite(LED_1, HIGH);
         digitalWrite(LED_2, HIGH);
         digitalWrite(LED_3, HIGH);
         digitalWrite(LED_4, LOW);
         digitalWrite(LED_5, LOW);
      }
      else if (tempC<=50){
         digitalWrite(LED_1, HIGH);
         digitalWrite(LED_2, HIGH);
         digitalWrite(LED_3, HIGH);
         digitalWrite(LED_4, HIGH);
         digitalWrite(LED_5, LOW);
      }
      else{
         digitalWrite(LED_1, HIGH);
         digitalWrite(LED_2, HIGH);
         digitalWrite(LED_3, HIGH);
         digitalWrite(LED_4, HIGH);
         digitalWrite(LED_5, HIGH);
      }

}