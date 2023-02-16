#include <avr/io.h>
#include <avr/interrupt.h> //Add all libraries
#include <Servo.h>

Servo servo_9; // initialize motor
volatile byte count; //count variable
byte reload = 0x9C;

ISR(TIMER2_COMPA_vect)
{
count++; // add to counter
OCR2A = reload;
}

void setup()
{
servo_9.attach(9, 500, 2500); // setup servo motor
Serial.begin(115200);		  // setup serial
cli();
TCCR0B = 0;                 
OCR2A = reload;             
TCCR2A = 1<<WGM21;			// Timer2 setup
TCCR2B = (1<<CS22) | (1<<CS21) | (1<<CS20); 
TIMSK2 = (1<<OCIE2A);                
sei(); 
Serial.println("TIMER2 Setup Finished.");
}

void loop()
{
if (count == 100) // count to 1 second. 
{
clock();         // run the analog clock
count = 0;
}
}

void clock() // clock method
{
  // sweep the servo from 0 to 180 degrees in steps of 1 degrees
  /*for (pos = 0; pos <= 180; pos += 1) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    Serial.println(pos);

    }*/
  static int servoPos = 0; // init posotion variable of motor position
  // Set the next servo position
  servoPos += 1;		   // move the motor by 1,
  if (servoPos > 180) {    // until 180 degrees
    servoPos = 0;
  }
  servo_9.write(servoPos);	// send the new position to 
  							// the motor
  Serial.println(servoPos); // print the new position
  }