#include <stdio.h>
#include <string.h>

typedef struct{
    char name[50];
    int age;
    char title[50];
    char email[50];
    char phone[50];

}Person;

void printCard(Person people[], int size){
    for(int i = 0; i < size; i++){
        printf("\n============================\n");
        printf("        Business Card       \n");
        printf("============================\n");
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Title: %s\n", people[i].title);
        printf("Email: %s\n", people[i].email);
        printf("Phone Number: %s\n", people[i].phone);
        printf("============================\n");
        printf("\n");
    }
}

int main(){
    Person people[3];

    int size = sizeof(people) / sizeof(people[0]);

    for(int i = 0; i < size; i++){

        printf("Enter Name: ");
        fgets(people[i].name, sizeof(people[i].name), stdin);
        people[i].name[strlen(people[i].name) - 1] = '\0';

        printf("Enter Age: ");
        scanf("%d", &people[i].age);
        getchar();

        printf("Enter Title: ");
        fgets(people[i].title, sizeof(people[i].title), stdin);
        people[i].title[strlen(people[i].title) - 1] = '\0';

        printf("Enter Email: ");
        fgets(people[i].email, sizeof(people[i].email), stdin);
        people[i].email[strlen(people[i].email) - 1] = '\0';

        printf("Enter Phone Number: ");
        fgets(people[i].phone, sizeof(people[i].phone), stdin);
        people[i].phone[strlen(people[i].phone) - 1] = '\0';

        printf("\n");
    }

    printCard(people, size);

    return 0;

}