//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 1
//Submission number: 2763534813
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
 
#define MAX 100 // Defines the maximum number of the values in the table 
#define MAXNUMBER 20 // Defines the maximum value of random numbers 
#define MINNUMBER 1  // Defines the minimum value of random numbers
#define X "x" //for displaying number frequency


// ------ Function declarations   ----------  
 
// This function generates a set of random numbers 
// and fills the table *tab with these numbers 
void create_random(int *tab );   
 
// This function takes the *tab of random numbers 
// and creates a table with the frequency counts for these numbers 
void count_frequency(int *tab, int *freq );     
 
// This function takes the frequency count table 
// and draws a histogram of the values in that frequency table 
void draw_histogram(int *freq );  
 
// ------ Function definitions   ---------- 

void create_random(int *tab){
    //loops through each element in the given array
    for (int i = 0; i<MAX; i++){
        //generates a random number from 0-20
       int randNum = (rand() % (MAXNUMBER - MINNUMBER + 1) + MINNUMBER);
        //prints each element and the value it has 
        //this is to check if the function works
        tab[i] = randNum;
        //printf(" %d, ", tab[i]);
    }
}

void count_frequency(int *tab, int *freq ){
    int visited = -1;
    //loops through table
    for (int i = 0; i<MAX; i++){
        int count = 1;
        //loops through table again
        for(int n = i+1; n<MAX; n++){
            //checks if element from the first loop is equal to the element from the second loop
           if(tab[i] == tab[n]){
            //adds 1
           count++;
            //to avoid counting the same element twice
           tab[n] = visited;
           }
        }
        //checks if element was not visited
       if(tab[i] != visited){
            //adds 1 to frequency
           freq[i] = count;
            //prints the frequency of each number from 0-20, excluding numbers with frequency 0
            //this is to check if the function works
           //printf("\n %d", tab[i]);
           //printf("      |     ");
           //printf(" %d \n", freq[i]);
       }
   }
}

void draw_histogram(int *freq ){
    for (int i = 0; i < MAXNUMBER; i++) {
     if (freq[i] != 0){
         //print all numbers used in random number generation
         printf("\n%d: ", (i + 1));

         //for the frequency amount of the current number
         for (int j = 0; j < freq[i]; j++){
            // print a symbol (x)
            printf("%s", X);
         }
      }
    }
}

 
// ------ Main   -------------------------- 
 
// The main entry point for the program 
int main (void){ 
    //table
    int table[MAX], n ;
    //frequency array
    int frequency[MAXNUMBER];

    for (n = 0; n < MAXNUMBER; n++) {
      frequency[n] = 0; // set all integer values to 0
    }
    
    //to generate a different table every time
    srand(time(NULL));

    //parameters of each function defined
    create_random(table);
    count_frequency(table, frequency);
    draw_histogram(frequency);

    return 0;
}