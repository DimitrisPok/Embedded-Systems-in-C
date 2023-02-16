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

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort (int number, int tab []) {
    int i, j;
    for (i = 0; i < number - 1; i++)
        for (j = 0; j < number - i - 1; j++)
            if (tab[j] > tab[j + 1])
                swap(&tab[j], &tab[j + 1]);
}

void printArray(int tab[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", tab[i]);
    printf("\n");
}

int main(int argc, char *argv[]){
    int toSearch;
    int test[] = {1,2,34,5,67,3,23,12,13,10}; 
    int number = sizeof(test) / sizeof(test[0]);
    printf("Enter an element to search: ");
    scanf("%d", &toSearch);
    search_number(toSearch, test, sizeof(test));
    printf("\n");

    sort(number, test);
    printf("Sorted array: \n");
    printArray(test, number);
    return 0;
}