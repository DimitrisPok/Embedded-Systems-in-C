//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 2
//Submission number: 

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
//#### Constants ##### 
#define MAX 5
 
// ##### typedefs          #### 
typedef struct q{ 
        int number; 
        struct q *next; 
        struct q *prev; 
} REGTYPE; 
 
// ##### Function declarations   ##### 
 
REGTYPE* random_list(int size); 
REGTYPE* add_first(REGTYPE* temp, int data); 
 
 
//###### Main program ####### 
int main(int argc, char *argv[]) 
{ 
    int nr=0; 
    int data = 0;
 
    REGTYPE *act_post , *head=NULL; 

        srand(time(0));  //   Random seed  
        head=random_list(MAX); 
        if (head == NULL){
            return 1;
        }
        act_post=head; 
        while( act_post!=NULL){ 
           printf("\n Post nr %d : %d" , nr++, act_post->number); 
           act_post=act_post->next; 
        }


    //asking the user to give an input
    printf("\n Add a new record: ");
    //scanning the input and assigning it to the data variable
    scanf("%d", &data);
    //tests the add_first function
    head = add_first(head, data);
    act_post=head;
    //sets element value to 0 so that the user's input gets added to the first element
    nr=0;
    //prints the linked list
    while( act_post!=NULL){ 
        printf("\n Post nr %d : %d" , nr++, act_post->number); 
        act_post=act_post->next; 
    }
       
 // --- Free the allocated memory  --- 
 
  while((act_post=head)!=NULL){ 
     head=act_post->next; 
     free(act_post); 
  } 
   
                    
 
  return 0; 
} 
 
// ====     End of main   ====================================== 
 
REGTYPE* random_list(int size){ 
    int nr, i=0; 
    REGTYPE *top = NULL, *old = NULL, *item = NULL;

    //iterating through list
    for(i = 0; i < size; i++){
        item = (REGTYPE *)malloc(20 * sizeof(REGTYPE)); //allocating memory

        //terminate program if memory not allocated
        if(item == NULL){
            printf("Unable to allocate memory.");
            return NULL;
        }

        item->number = rand() % 101; //link number to the rand() which generates a random number from 0-100 
        item->next = NULL; //link next with null

        if(top == NULL){ //if value has no top
            //make top equal the item because this means that the list is empty
            top = item;
            old = item;
        }
        else{ //else update old to be item 
            old->next = item;
            old = item;
        }
    }
    return top; 
} 
 
//==========================================================                 
 
REGTYPE* add_first(REGTYPE* temp, int data){ 
    //new first entry in the list variable definition
    REGTYPE *item =NULL;
    item = (REGTYPE *)malloc(20 * sizeof(REGTYPE)); //allocating memory

    item->number = data; //link number with the input the user gave (ie. data)
    item->next = temp; //link the next value to temp

    //returns a pointer to the new first entry
    return item;
} 