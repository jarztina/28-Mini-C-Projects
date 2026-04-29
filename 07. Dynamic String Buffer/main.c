#include <stdio.h>
#include <stdlib.h>

int main(){
    int count = 0;
    int character;
    int reallocate = 0;
    int size = 10; //current sentence size
    int newsize = size + 10; //new sentence size


    char *sentence = malloc(size * sizeof(char));
    if(sentence == NULL){
        printf("Memory Allocation Failed!");
        return 1;
    }
    
    printf("Enter you sentence: ");
    while((character = getchar()) != '\n'){
        sentence[count] = character;
        count++;
        if(count == size){ //when it reaches the size of 10, it will reallocate
            char *temp = realloc(sentence, newsize * sizeof(char)); //change the bytes
            if(temp == NULL){
            printf("Memory Allocation Failed!");
            return 1;
            }

            size = newsize;
            newsize = newsize + 10;
            reallocate++;
            sentence = temp;
        }
    }
    sentence[count] = '\0';
    printf("%s\n", sentence);
    printf("Total character: %d\n", count);
    printf("Reallocations: %d\n", reallocate);

    free(sentence);
    sentence = NULL;

    return 0;
}