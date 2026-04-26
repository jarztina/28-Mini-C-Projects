#include <stdio.h>
#include <stdlib.h>

int *inputGrade(int number)
{
    int *grade = malloc(number * sizeof(int)); // initialising the varaible of grade

    if (grade == NULL)
    {
        printf("Memory Allocation Error!");
    }

    for (int i = 0; i < number; i++)
    {
        printf("Enter the grade of the #%d student: ", i + 1);
        scanf(" %d", &grade[i]);
    }

    printf("Grade: ");

    for (int i = 0; i < number; i++)
    {
        printf("%d ", grade[i]);
    }
    printf("\n");

    return(grade);
}

int calculateTotal(int *grade, int number, int *totalPtr){
    
    for(int i = 0; i < number; i++){
        *totalPtr += grade[i];
    }
    printf("Total: %d\n", *totalPtr);
}

float calculateAverage(int total, int number){
    float average = 0;
    average = (float)total / number;
    printf("Average: %.2f", average);
}

int main()
{
    printf("***INPUT***\n");

    int number;

    printf("Enter the number of students: ");
    scanf(" %d", &number);

    int *myGrade = inputGrade(number);

    printf("\n***OUTPUT**\n");

    int myTotal = 0;
    calculateTotal(myGrade, number, &myTotal);
    float average = calculateAverage(myTotal, number);

    free(myGrade);
    myGrade = NULL;

    return 0;
}