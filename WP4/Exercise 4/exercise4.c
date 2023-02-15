#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int search_number(int number, int tab[], int size){
    int found;
    int i=0;
    for(i=0; i<size; i++){
        if(tab[i] == number){
            found = 1;
            break;
        }
    }
    if(found == 1){
        printf("%d is found at position %d", number, i);
        return 0;
    }else{
        printf("%d was not found in the array", number);
        return -1;
    }
}

int main(int argc, char *argv[]){
    int toSearch;
    int test[] = {1,2,34,5,67,3,23,12,13,10}; 
    printf("Enter an element to search: ");
    scanf("%d", &toSearch);
    search_number(toSearch, test, sizeof(test));
    return 0;
}