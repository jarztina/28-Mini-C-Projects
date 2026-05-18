#include <stdio.h>
#include <string.h>

int main()
{
    char fileName[50];
    char line[256];
    char *word;
    int count = 0;

    // Ask for user input
    printf("Enter the file name to read: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strlen(fileName) - 1] = '\0';

    // Open the file name inputed by user
    FILE *f = fopen(fileName, "r");

    // Safety precauction: In case not file is inputed
    if (f == NULL)
    {
        printf("Error reading file...");
        return 1;
    }

    // Print the words in the text file
    while (fgets(line, sizeof(line), f) != NULL)
    { // f reads from the file
        printf("%s\n", line);

        //chops up the line and ignores spaces, tabs and newline
        word = strtok(line, " \t\n");
        //continue the loop if word is found
        while (word != NULL)
        {  
            count++;
            word = strtok(NULL, " \t\n");
        }
    }

    printf("Words Counted: %d \n", count);

    fclose(f);
    return 0;
}
