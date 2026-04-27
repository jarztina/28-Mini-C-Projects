#include <stdio.h>
#include <stdlib.h>

int current_usage = 0;

void loop1(int number){
    for(int i = 0; i < number; i++){
        int *grade = calloc(number, sizeof(int));
        current_usage += (number * sizeof(int)); //Track Heap Allocation (5 ints * 4 bytes = 20 bytes) 
        free(grade);
        current_usage -= (number * sizeof(int)); //Mark memory as returned to the system
    }
}

void loop2(int number){
    for(int i = 0; i < number; i++){
        int *grade = calloc(number, sizeof(int));
        current_usage += (number * sizeof(int));
        free(grade);
        current_usage -= (number * sizeof(int));
    }
}

void loop3(int number){
    for(int i = 0; i < number; i++){
        int *grade = calloc(number, sizeof(int));
        current_usage += (number * sizeof(int));
        free(grade);
        current_usage -= (number * sizeof(int));
    }
}

int main(){
    int number = 5;

    loop1(number);
    loop2(number);
    loop3(number);

    printf("Memory Leaked: %d bytes", current_usage);
    
    return 0;
}