#include <stdio.h>
#include <time.h>

int main(){

    //Getting the current time in C
    time_t now = time(NULL); //asks the computer what time is it and store it in now
    struct tm *t = localtime(&now); //converts the raw time into something readable

    //Formatting the time
    char timestamp [20]; //creates a box named timestamp that holds 20 character
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", t); //Format the time into that box

    //Writing to a file
    FILE *f = fopen("log.txt", "a"); //open log.txt in append mode "a", appendnig to a file without erasing
    if (f == NULL){
        printf("Error: Could not open log.txt\n");
        return 1;
    }
    fprintf(f, "%s\n", timestamp); //write into a file
    fclose(f); //close the file when done

    //Printing Confirmation
    printf("Logged: %s\n", timestamp);

    return 0;
}