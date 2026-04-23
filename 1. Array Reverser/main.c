#include <stdio.h>
#include <stdlib.h>

//int *number: Use this only if you need to point to a number stored somewhere else (like in a different function).

int main(){

    int number = 0; 
    
    printf("Enter the number of numbers in the array: "); //User inputs the number of elements in the array
    scanf("%d", &number); 

    int *original = calloc(number, sizeof(int)); 
    // int *original = malloc(number *sizeof(int));

    if(original == NULL){
        printf("Memory Allocation Error!"); //This code helps prevent further operations on a pointer (original) that hasn’t been successfully allocated memory, 
                                            //thereby avoiding undefined behavior or crashes.
        return 1;
    }

    for(int i = 0; i < number; i++){
        printf("Enter the #%d number: ", i + 1);
        scanf("%d", original + i); //original is the 0th house, (original + i) the address of the house that is i steps away from the start
    }

    for(int i = 0; i < number; i++){
        printf("%d ", *(original + i));
    }

    int *start = original; //points to the address of the very first element (index 0)
    int *end = original + (number - 1); //where the data ends eg. 5 numbers will give u position 0,1,2,3,4

    while(start < end){ //comparing the address, not the value
        int temp = *start; //third cup logic
        *start = *end;
        *end = temp;
        start++; //moves the start pointer by 4 bytes to point to the next number
        end--; //moves the end pointer backward by 4 bytes to point at the previous number
    }

    printf("\nReversing...\n");

    for(int i = 0; i < number; i++){
        printf("%d ", *(original + i));
    }

    free(original);
    original = NULL;
    printf("\n");

    return 0;
}