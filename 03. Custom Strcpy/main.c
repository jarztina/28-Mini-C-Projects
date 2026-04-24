#include <stdio.h>
#include <string.h>

typedef struct{
    char name [50];
}Source;

typedef struct{
    char name [50];
}Destination;

int main(){
    Source source = {"Justin"};
    Source destination = {""};

    Source *pSource = &source;
    Source *pDestination = &destination;

    printf("--- String Copy Debugger ---\n");
    printf("Source: %s\n", source.name);
    if(destination.name[0] == '\0'){    //checks if the first character is a null terminator (EMPTY)
        printf("Destination (Old): [EMPTY]\n");
    }
    else{
        printf("Destination (Old): %s\n", destination.name);
    }
 
    printf("Copying...\n");

    char *srcPtr = pSource -> name; //making copies of the address
    char *destPtr = pDestination -> name;

    while(*srcPtr != '\0'){
        *destPtr = *srcPtr;
        srcPtr++; //reading the original names
        destPtr++; //writing the original names in the new memory slot
    }

    *destPtr = '\0';

    if(destination.name[0] == '\0'){  //checks if the first character is a null terminator (EMPTY)
        printf("Destination (NEW): [EMPTY]\n");
    }
    else{
        printf("Destination (NEW): %s\n", destination.name);
    }

    return 0;
}

