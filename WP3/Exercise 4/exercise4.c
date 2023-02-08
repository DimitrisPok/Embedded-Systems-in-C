#include <Keypad.h>

//variable declaration for how many rows and columns there are
const byte ROWS = 4; 
const byte COLS = 4; 

//specifying the keys
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//specifying the pins for each of the rows and columns
byte row[ROWS] = {11, 10, 9, 8}; 
byte column[COLS] = {7, 6, 5, 4}; 

//our custom keypad with the keys
Keypad keypad = Keypad(makeKeymap(keys), 
                             row, 
                             column, 
                             ROWS, 
                             COLS); 
void setup()
{

  Serial.begin(9600);        // serial begin
}

//loop that gets the key that the user presses
void loop()
{
  {
    //customKey gets the character that is pressed
  char customKey = keypad.getKey();

  //if customKey is not equal 0 print the character that is pressed
  if (customKey != 0){
    Serial.println(customKey);
  }
  }
}