/* CS2211a 2021 */
/* Assignment 02 */
/* Raina Ge */
/* 251154934 */
/* rge25 */
/* 10/04/21 */ 

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    printf("Assignment Two\n");

    srand(time(NULL));

    /* Preprocessor definition that determines the number of iterations between 1-5
    int totalIter = (rand() % (5) + 1);
    #define ITERATIONS totalIter
    */

    // Preprocessor definition that sets the number of iterations to 3
    #define ITERATIONS 3

    // Determines the range of values put into the array
    int iterRange = ITERATIONS;

    // Determines the current iteration
    int curr = 1;
    
    // Determines the length of the array (if statement avoids division by 0 when ITERATIONS = 1)
    int arrLength;
    
    if(ITERATIONS == 1)
      arrLength = 50;

    else
      arrLength = (rand()%((50*ITERATIONS) - 50 + 1)) + 50;

    // Creates int array with the determined length
    int numArr[arrLength];

    printf("\tValue of random size of array: %d\n", arrLength);
    printf("\tSize of array: %d bytes\n", arrLength*4);

    // While loop that iterates through a specified number of times
    while(curr <= ITERATIONS){
        // Deterimines the upper range value of the array for the current iteration
        int range = 1;
        for(int i = 0 ; i < iterRange; i++){
          range *= 10;
        }
	
	// Upper range debugger statment
        #define UPPER_RANGE(range) printf("UPPER RANGE VALUE: %d\n", range)

        printf("THIS IS ITERATION NUMBER: %d of %d\n", curr, ITERATIONS);
        // Calls on upper range debugger statement
        UPPER_RANGE(range);

        //Adds random numbers within the calculated range into the array
        for(int i = 0; i < arrLength; i++){
          numArr[i] = rand()%((range)-1) + 1;
        }

        printf("\tThis is the original array populated with values in the range of 1 and %d\n\tNumber of elements in the original array is: %d", range, arrLength);

        // Prints the original array
        for(int i = 0; i < arrLength; i++){
          // Formats the output to have 20 numbers on each line
          if(i % 20 == 0){
            printf("\n");
          }
          printf("%7d",numArr[i]);
        }
        printf("\n");
        
        // Debugger that removes duplicate numbers from the array
        printf("\n");
        #define PRINT_DUPLICATES(i,j) printf("The value of %d at array index [%d] and the value of %d at the array index [%d] are the same.\n", numArr[i],i, numArr[j], j)

        for(int i = 0; i < arrLength; i++){
            for(int j = i+1; j < arrLength;){
                if(numArr[i] != 0 && numArr[i] == numArr[j]){
                    // Calls on print duplicates debugger statement
                    PRINT_DUPLICATES(i,j);                    
		    numArr[j] = 0;
                }
                else
                  j++;
              }
        }
        printf("\n");
        
        // Shifts the elements containing 0 to the end of the array
        // Varaible tracking the position in the array
        int elem = 0;
        // Adds all unique elements to the front of the array
        for(int i = 0; i < arrLength; i++){
          if(numArr[i]!= 0){
            numArr[elem] = numArr[i];
            elem++;
          }
        }
        // Determines the number of unique numbers in the array
        int uniqueNums = elem; 
        
        // Adds all the zeros to the end of the array
        while(elem < arrLength){
          numArr[elem] = 0;
          elem++;
        }

        printf("\tThis is the current state of the array with all duplicate values removed\n\tNumber of unique (non-zero, non-duplicate) elements inthe array is: %d", uniqueNums);
        // Resets tracker back to 0
        elem = 0;
        // Prints all of the unique numbers
        while(elem < uniqueNums){
          // Formats the output to have 20 numbers on each line
          if(elem % 20 == 0){
            printf("\n");
          }
          printf("%7d",numArr[elem]);
          elem++;
        }
        
  
        // Sorts the array in ascending order
        for (int i = 1; i < uniqueNums; i++) {
          int key = numArr[i];
          int j = i - 1;
          while (j >= 0 && numArr[j] > key) {
              numArr[j + 1] = numArr[j];
              j--;
          }
          numArr[j + 1] = key;
        }
        
        printf("\n\n\tThese are the unique, non-zero elements in the array sorted in ascending order:");
        // Resets tracker back to 0
        elem = 0;
        // Prints the array in ascending order
        while(elem < uniqueNums){
          // Formats the output to have 20 numbers on each line
          if(elem % 20 == 0){
            printf("\n");
          }
          printf("%7d",numArr[elem]);
          elem++;
        }

        iterRange--;
        curr++;
        printf("\n\n**************************************************************************\n\n");
      }
      
}



