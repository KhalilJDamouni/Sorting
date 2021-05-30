//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/ioctl.h> //Terminal Size Library

//Headers
#include "main.h"
#include "sortLib.c"


int main(void)
{
    measureTerminal();

    int* numbers;
    numbers = createArray();

    //Get Sort Type
    int sortType;
    printf("1. Bubble\n"
           "2. Quick\n"
           "3. Insertion\n"
           "4. Selection\n"
           "Sort Type: ");
    
    scanf("%i", &sortType);

    showArray(numbers);

    //Sort
    

    if(sortType == 1) //Bubble
    {
        char throw;
        printf("Start? Press any letter and hit enter! ");
        scanf("%c ", &throw);

        bubbleSort(numbers);
    }
        
    else if(sortType == 2) //Quick
    {
        char throw;
        printf("Start? Press any letter and hit enter! ");
        scanf("%c ", &throw);
        
        quickSort(numbers, 0, Term_Height - 1);
    }

    else if(sortType == 3) //Insertion
    {
        char throw;
        printf("Start? Press any letter and hit enter! ");
        scanf("%c ", &throw);
        
        insertionSort(numbers);
    }
    
    else if(sortType == 4) //Selection
    {
        char throw;
        printf("Start? Press any letter and hit enter! ");
        scanf("%c ", &throw);
        
        selectionSort(numbers);
    }
    
    else
        printf("Not Valid Input\n");


    return 0;
}