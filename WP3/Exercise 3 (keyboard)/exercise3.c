// Connecting the pins to the correct rows and columns
const int row1 = 11; // digital pin for steering row 1
const int row2 = 10; // digital pin for row 2
const int row3 = 9;	 // digital pin for row 3
const int row4 = 8;	 // digital pin for row 4

const int col1 = 7;	 // digital pin for column 1
const int col2 = 6;  // digital pin for column 2
const int col3 = 5;  // digital pin for column 3
const int col4 = 4;  // digital pin for column 4


void setup()
{
 
  pinMode(row1, OUTPUT);	// we send signals through rows
  pinMode(row2, OUTPUT);	// as above
  pinMode(row3, OUTPUT);	// as above
  pinMode(row4, OUTPUT);	// as above
  
  pinMode(col1, INPUT); 	// and we receive them by columns
  pinMode(col2, INPUT); 	// as above
  pinMode(col3, INPUT); 	// as above
  pinMode(col4, INPUT); 	// as above
  
  Serial.begin(9600);		// instead of printf, we use serial output
}

/*
* In the main loop we periodically check if a button is pressed 
* with a delay of 1 second after every press.
*/
void loop()
{
  digitalWrite(row1, LOW);			// send a signal through row 1
  int r1c1 = digitalRead(col1); 	// read the column
  int r1c2 = digitalRead(col2); 	// read the column
  int r1c3 = digitalRead(col3); 	// read the column
  int r1c4 = digitalRead(col4); 	// read the column
  digitalWrite(row1, HIGH);			// reset row 1
  
  digitalWrite(row2, LOW);			// set row 2
  int r2c1 = digitalRead(col1); 	// check column 1
  int r2c2 = digitalRead(col2); 	// check column 2
  int r2c3 = digitalRead(col3); 	// read the column
  int r2c4 = digitalRead(col4); 	// read the column
  digitalWrite(row2, HIGH);			// reset row 2
  
    digitalWrite(row3, LOW);		// set row 2
  int r3c1 = digitalRead(col1); 	// check column 1
  int r3c2 = digitalRead(col2); 	// check column 2
  int r3c3 = digitalRead(col3); 	// read the column
  int r3c4 = digitalRead(col4); 	// read the column
  digitalWrite(row3, HIGH);			// reset row 2
  
    digitalWrite(row4, LOW);		// set row 2
  int r4c1 = digitalRead(col1); 	// check column 1
  int r4c2 = digitalRead(col2); 	// check column 2
  int r4c3 = digitalRead(col3); 	// read the column
  int r4c4 = digitalRead(col4); 	// read the column
  digitalWrite(row4, HIGH);			// reset row 2
  
  // we check if 1 was pressed
  if (r1c1 == 0)
  {
    Serial.println('1');	// print 1 to the serial port
  	delay(1000);		    // Wait for 1000 millisecond(s)
  }  
  
  // check if 2 was pressed
  if (r1c2 == 0)
  {
    Serial.println('2');		// print 2 to serial port
  	delay(1000); 				// Wait for 1000 millisecond(s)
  }  
  
  // check if 3 was pressed
  if (r1c3 == 0)
  {
    Serial.println('3');		// write 3 to serial port
  	delay(1000); 				// Wait for 1000 millisecond(s)
  }  
  
  // check if 4 was pressed
  if (r2c1 == 0)
  {
    Serial.println('4');		// print 4 to the serial port
  	delay(1000); 				// Wait for 1000 millisecond(s)
  } 
    
  // check if 5 was pressed
  if (r2c2 == 0)
  {
    Serial.println('5');		// print 5 to the serial port
  	delay(1000); 				// Wait for 1000 millisecond(s)
  } 
    // check if 6 was pressed
  if (r2c3 == 0)
  {
    Serial.println('6');		// print 6 to the serial port
  	delay(1000); 				// Wait for 1000 millisecond(s)
  } 
  
    // check if 7 was pressed
  if (r3c1 == 0)
  {
    Serial.println('7');		// print 7 to the serial port
  	delay(1000); 				// Wait for 1000 millisecond(s)
  } 
  
    // check if 8 was pressed
  if (r3c2 == 0)
  {
    Serial.println('8');		// print 8 to the serial port
  	delay(1000); 				// Wait for 1000 millisecond(s)
  } 
  
    // check if 9 was pressed
  if (r3c3 == 0)
  {
    Serial.println('9');		// print 9 to the serial port
  	delay(1000); 				// Wait for 1000 millisecond(s)
  } 
  
    // check if * was pressed
  if (r4c1 == 0)
  {
    Serial.println('*');		// print * to the serial port
  	delay(1000); 				// Wait for 1000 millisecond(s)
  } 
  
    // check if 0 was pressed
  if (r4c2 == 0)
  {
    Serial.println('0');		// print 0 to the serial port
  	delay(1000); 				// Wait for 1000 millisecond(s)
  } 
  
    // check if # was pressed
  if (r4c3 == 0)
  {
    Serial.println('#');		// print # to the serial port
  	delay(1000); 				// Wait for 1000 millisecond(s)
  } 
  
  // check if A was pressed
  if (r1c4 == 0)
  {
    Serial.println('A');		// write A to serial port
  	delay(1000); 				// Wait for 1000 millisecond(s)
  }  
  // check if B was pressed
  if (r2c4 == 0)
  {
    Serial.println('B');		// print B to the serial port
  	delay(1000); 				// Wait for 1000 millisecond(s)
  } 
  // check if C was pressed
  if (r3c4 == 0)
  {
    Serial.println('C');		// write C to serial port
  	delay(1000); 				// Wait for 1000 millisecond(s)
  }  
  // check if D was pressed
  if (r4c4 == 0)
  {
    Serial.println('D');		// print D to the serial port
  	delay(1000); 				// Wait for 1000 millisecond(s)
  }
  
}