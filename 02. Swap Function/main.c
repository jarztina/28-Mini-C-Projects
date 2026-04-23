#include <stdio.h>

typedef struct{
    char name[50];

} Passport;

void swapPassport(Passport **pp1, Passport **pp2);

int main(){
    Passport passport1 = {"Justin"};
    Passport passport2 = {"SIT_student"};

    Passport *ptr1 = &passport1; //Declares a pointer 'ptr1' and stores the memory address of the 'passport1' struct
    Passport *ptr2 = &passport2; //Declares a pointer 'ptr2' and stores the memory address of the 'passport2' struct

    printf("--- BEFORE SWAP ---\n");
    printf("Passport 1 Address: %p\n", ptr1);
    printf("Passport 1 Name: %s\n", passport1.name);
    printf("Passport 2 Address: %p\n", ptr2);
    printf("Passport 2 Name: %s\n", passport2.name);

    printf("\n--- SWAPPING POSITIONS ---\n");

    swapPassport(&ptr1, &ptr2); //sender EG. Passport **pp1 = &ptr1

    printf("\n--- AFTER SWAP ---\n");
    printf("Passport 1 Address: %p\n", ptr1);
    printf("Passport 1 Name: %s\n", ptr1 -> name);
    printf("Passport 2 Address: %p\n", ptr2);
    printf("Passport 2 Name: %s\n", ptr2 -> name);

    //dont need to free(ptr1) as its only used for calloc/malloc

    return 0;
}

void swapPassport(Passport **pp1, Passport **pp2){ //receiver

    Passport *temp = *pp1; //save the first key THIRD cup logic
    *pp1 = *pp2;
    *pp2 = temp;

}

