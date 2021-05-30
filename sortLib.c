#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/ioctl.h> //Terminal Size Library

int Term_Height; //Number of elements
int Term_Length; //Max Number

void showArray(int numbers[])
{
    for(int i = 0; i < Term_Height; ++i)
        printf("%i ", numbers[i]);

    printf("\n");

    for(int i = 0; i < Term_Height; ++i)
    {
        for(int d = 0; d < numbers[i] - 1; ++d)
            printf("#");
    
        printf("\n");
    }
}

void selectionSort(int numbers[]) //Type 4
{

    int location;
    for(int i = 0; i < Term_Height; ++i)
    {
        int pivot = Term_Length;
        for(int d = i; d < Term_Height; ++d)
        {
            if(numbers[d] < pivot)
            {
                pivot = numbers[d];
                location = d;
            }
        }
        int t = numbers[i];
        numbers[i] = pivot;
        numbers[location] = t;

        usleep(30000);
        system("Clear");
        showArray(numbers);
    }
}

void insertionSort(int numbers[]) //Type 3
{
    for(int i = 0; i < Term_Height; ++i) //Cycles through all elements
    {
        int temp = i;
        for(int d = i - 1; d >= 0 && numbers[temp] < numbers[d]; --d) //Cycles through all elements less than ^^^
        {
            if(numbers[temp] < numbers[d])
            {
                int t = numbers[temp];
                numbers[temp] = numbers[d];
                numbers[d] = t;
                --temp;
            }
            usleep(30000);
            system("Clear");
            showArray(numbers);
        }
        
    }
}

void quickSort(int numbers[], int low, int high) //Type 2
{

    if(low < high)
    {
        usleep(30000);
        system("Clear");
        showArray(numbers);

        int pivot = partition(numbers, low, high);
        quickSort(numbers, low, pivot - 1);
        quickSort(numbers, pivot + 1, high);   
    }    
    
}

int partition(int numbers[], int low, int high) //Type 2, Helper
{
    int pivot = numbers[high];
    int i = low - 1;

    int j;
    for(j = low; j <= high - 1; ++j)
    {
        if(numbers[j] < pivot)
        {
            ++i;

            //Swap
            int temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
        }    
    }

    //Swap
    int temp = numbers[high];
    numbers[high] = numbers[i + 1];
    numbers[i + 1] = temp;

    return i + 1;
}

void bubbleSort(int numbers[]) //Type 1
{
    bool fixed = false;
    int temp;
    while(true)
    {
        fixed = false;
        for(int i = 0; i < Term_Height; ++i)
        {
            if(numbers[i] > numbers[i + 1])
            {
                temp = numbers[i]; 
                numbers[i] = numbers[i + 1]; 
                numbers[i + 1] = temp;
                
                fixed = true;
            }   
        } 
        usleep(30000);
        system("Clear");
        showArray(numbers);
        if(!fixed)
            return;
    } 
}

void measureTerminal()
{
    //Get Terminal Size
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    Term_Height = -3 + (int) w.ws_row;
    Term_Length = (int) w.ws_col;
}

int* createArray()
{
    //Create Integer Array
    int* numbers = malloc(sizeof(int) * Term_Height);

    for(int i = 0; i < Term_Height; ++i)
        numbers[i] = (rand() % Term_Length) + 1;

    return numbers;
}