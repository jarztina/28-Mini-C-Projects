#include <stdio.h>
#include <string.h>

int main(){
    char sourceFile[50];
    char destinationFile[50];
    int count = 0;

    printf("Enter source file: ");
    fgets(sourceFile, sizeof(sourceFile), stdin);
    sourceFile[strlen(sourceFile) - 1] = '\0';

    printf("Enter destination file: ");
    fgets(destinationFile, sizeof(destinationFile), stdin);
    destinationFile[strlen(destinationFile) - 1] = '\0';

    FILE *sf = fopen(sourceFile, "rb");
    if(sf == NULL){
        printf("Error reading file...");
        return 1;
    }

    FILE *df = fopen(destinationFile, "wb");
    if(df == NULL){
        printf("Error reading file...");
        return 1;
    }

    int byte;
    byte = fgetc(sf);
    while(byte != EOF){
        fputc(byte, df);
        count++;
        byte = fgetc(sf);
    }
    printf("Success! Copied %d bytes", count);

    fclose(sf);
    fclose(df);
    return 0;
}