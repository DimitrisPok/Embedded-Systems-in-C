//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 2
//Submission number: 0267702620

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// -----typedefs -------
typedef struct { // Here we define the person struct.
    char firstname[20];
    char famname[20];
    char pers_number[13]; // YYYYMMDDNNNN
} PERSON;

//File variable declaration.
FILE *People;
// Function declaration.
PERSON input_record(void){    // Reads a person’s record.

    PERSON person;                                            // Reserve memory for the new person struct.
    printf("Please give a name for this person:  \n");
    scanf("%s",person.firstname);                             //Ask for the first name
    printf("Please give a family name for this person:  \n");
    scanf("%s",person.famname);                               //Ask for the family name
    printf("Please give a personal number for this person:  ");
    scanf("%s",person.pers_number);                           // Ask for the personal number
    return person;
};

void write_new_file(PERSON *inrecord){                        // Creates a file and writes the first record
    People = fopen("People.bin", "w");                        //Open the People.bin file.
    
    inrecord = malloc(sizeof(PERSON));  //Allocating memory.
    strcpy(inrecord->firstname, "George");  // Store the firstname variable.
	strcpy(inrecord->famname, "GameBoy");   // Store the family name variable.
    strcpy(inrecord->pers_number, "200308195619"); // Store the personal number variable.
    fwrite(inrecord, sizeof(PERSON), 1, People);   // Write the above variables in the People.bin file.
    fclose(People);                                   // Close the file.
};

void print_file(void){      // Prints out all persons in the file
    PERSON Person; 
    People = fopen("People.bin", "rb"); // Open the .bin file.
    if (People == NULL){
        printf("\nError while opening the file\n"); // If the file doesnt exist, exit.
        exit (1);
    }
    while (fread(&Person, sizeof(Person), 1, People)){      
        printf("%s %s %s\n", Person.firstname, Person.famname, Person.pers_number); // While there are records in the file, print them.
    }
    fclose(People);         //Close the file after everything has been printed.
};           

void search_by_firstname(char *nameToSearch[20]){    // Prints out the person if in list
    PERSON Person;
    People=fopen("People.bin","rb");    //Open the file

    if (People == NULL){
        printf("\nError while opening the file\n");  //Check if the file exists.
        exit (1);
    }
    printf("Please give the name you want to search: ");
    scanf("%s", nameToSearch);             // Ask for name to look for.

    while(fread(&Person, sizeof(PERSON), 1, People) == 1){
        if(strcmp(Person.firstname, nameToSearch) == 0){ //If the name is found, print this person's details. 
            printf("First name: %s\n", Person.firstname);
            printf("Last name: %s\n", Person.famname);
            printf("Personal number: %s\n", Person.pers_number);
        }
    }
    fclose(People);            //Close the file after the search has been completed.*/

};

void append_file(PERSON *inrecord){ // appends a new person to the file
    People=fopen("People.bin","ab");     //Open the file in append mode so new structs can be added.
    if (People == NULL) {
        printf("\nError while opening the file\n");   //Check if the file exists.
        exit(1);
    }
    fwrite(inrecord, sizeof(PERSON), 1, People);   //Add inrecord to the binary file
    fclose(People);                                          // Close the file after adding the new person.
};

int main(void){
    int num;
    int point = 1;                                          //point variable to check if the while loop should repeat.
    printf("\n1 Create a new and delete the old file. \n" //Print all options.
           "2 Add a new person to the file. \n"
           "3 Search for a person in the file. \n"
           "4 Print out all in the file. \n"
           "5 Exit the program. \n");
    while(point==1) {
        printf(" \n Please type a integer from 1 to 5: \n");
        scanf("%d", &num);                              //Ask for option in terminal.
        if (num <= 5 || num > 0) {
            if(num == 1){  //If option 1
                PERSON *person1;
                write_new_file(person1); //Send the hardcoded to the method that creates the
                                            // file and adds this entry.
                printf("File creation successful.");
            }
            else if (num ==2){  //If option 2
                PERSON newPerson;
                PERSON *newperson;
                newPerson = input_record(); //Ask for input from user to create the new person.
                newperson = &newPerson;
                append_file(newperson);          //Send new person to the append file method
                printf("\n Person added.");      // so that it will be added to the file.
                }
            else if (num ==3) { //If option 3
                char name[20];
                search_by_firstname(name);
            }
            else if (num ==4){print_file();}    //Print the entire file.
            else if (num ==5){
                printf("Program closed.");   //If option 5, close the program.
                return 0;
            }else {
                printf("You did not give a integer from 1 to 5 as input." ); //If wrong input, exit.
                point = 0;
            }
        }
    }
    return(0);
}