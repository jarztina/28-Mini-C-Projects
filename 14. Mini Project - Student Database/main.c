#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int ID;
    char name[50];
    struct Node *next;

}Node;

Node *head = NULL;

void addStudent(int ID, char name[50]){
    printf("Enter ID: ");
    scanf(" %d", &ID);
    printf("Enter name: ");
    scanf(" %s", name);

    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    newNode -> ID = ID;
    strcpy(newNode -> name, name);
    newNode -> next = head;
    head = newNode;

}

void deleteStudent(int ID){
    Node *prev = NULL;
    Node *temp = head;
    printf("Enter ID to delete: ");
    scanf(" %d", &ID);
    if(head == NULL){
        printf("The list is empty\n");
        return;
    }
    if(head -> ID == ID){ //for deleting the head node
        head = head -> next;
        printf("Student %d deleted\n", temp -> ID);
        free(temp);
        return;
    }
    while(temp != NULL && temp -> ID != ID){
        prev = temp;
        temp = temp -> next;
    }
    if(temp == NULL){
        printf("Student not Found\n");
        return;
    }
    prev -> next = temp -> next;
    printf("Student %d deleted\n", temp -> ID);
    free(temp);
    
}

void SearchStudent(int ID, char name[50]){
    Node *temp = head;
    printf("Enter ID to search: ");
    scanf(" %d", &ID);
    if(temp == NULL){
        printf("List is Empty");
        return;
    }
    while(temp != NULL && temp -> ID != ID){
        temp = temp -> next;
    }
    if(temp == NULL){
        printf("Student not found");
        return;
    }
    printf("Found: ID = %d, Name = %s\n", temp -> ID, temp -> name);
}

void printAll(int ID, char name[50]){
    Node *temp = head;
    while(temp != NULL){
        printf("ID = %d, Name = %s\n", temp -> ID, temp -> name);
        temp = temp -> next;
    }
}

int main(){
    int choice = 0;
    int ID;
    char name[50];
    while(choice != 5){
        printf("\n== Student Database ==\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Search Student\n");
        printf("4. Print All\n");
        printf("5. Quit\n");
        printf("Choice: ");
        scanf(" %d", &choice);

        switch(choice){
            case 1:
            addStudent(ID, name);
            break;
            case 2:
            deleteStudent(ID);
            break;
            case 3:
            SearchStudent(ID, name);
            break;
            case 4:
            printAll(ID, name);
            break;
            case 5:
            exit(0);
            break;
        }
    }
    

    return 0;
}