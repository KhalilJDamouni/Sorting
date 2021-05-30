//Functions Declarations
void showArray(int numbers[]);
void bubbleSort(int numbers[]); //Type 1
void quickSort(int numbers[], int low, int high); //Type 2
int partition(int numbers[], int low, int high); //Type 2, Helper
void insertionSort(int numbers[]); //Type 3
void selectionSort(int numbers[]); //Type 4

//Global Variables
int Term_Height; //Number of elements
int Term_Length; //Max Number

//Definitions
#define DEBUG printf("Here\n");
