#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;

}Node;

Node *enqueue(Node *head, int value){
    Node *newNode = malloc(sizeof(Node));
    Node *temp = head;
    if(head == NULL){ //when the first value is inputed, head is empty
        newNode -> value = value;
        newNode -> next = NULL;
        return newNode;
    }
    else{
        while(temp -> next != NULL){ //go to the second last node
            temp = temp -> next;
        }
        newNode -> value = value; //create a new container, pass in the value
        newNode -> next = NULL; //next to the newNode its a NULL value
        temp -> next = newNode; //places newNode next to current temp
        return head; //head stays the same
    }

}

void printList(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%d -> ", temp -> value);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int inputValue(int value2){
    printf("\nEnter the value you would like to find: ");
    scanf(" %d", &value2);
    printf("Value to find: %d\n", value2);
    return value2;
}

int searchList(Node *head, int value2){
    Node *temp = head;
    int count = 1;
    if(temp == NULL){
        printf("Not Found");
    }
    else{
        while(temp != NULL && temp -> value != value2){
            temp = temp -> next;
            count++;
        }
        if(temp == NULL){ //check if value is found
            printf("\nPosition: Not Found\n");
        }
        else{
            printf("\nPosition: %d\n", count);
        }
    }
    return count;
}

int main(){
    Node *head = NULL;
    int value;
    int value2;
    int number;

    printf("Enter the number of values to be enqueued: ");
    scanf(" %d", &number);

    for(int i =0; i < number; i++){
        printf("Enter the #%d value: ", i + 1);
        scanf(" %d", &value);
        head = enqueue(head, value);
    }

    printList(head);
    value2 = inputValue(value2);
    searchList(head, value2);


    return 0;
}