#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;

Node *push(Node *head, int value){
    Node *newNode = malloc(sizeof(Node)); //creates a new node
    if(newNode == NULL){ //preventive measure incase malloc fails
        printf("Memory Allocation Error");
        return head; 
    }
    newNode -> next = head; //make newNode point to whatever head is @
    newNode -> value = value; 
    return newNode;
}

Node *pop(Node *head){
    if(head == NULL){
        printf("NULL");
        return NULL;
    }
    Node *current = head; //stores the head in current
    head = head -> next; // move head to the next node
    printf("Removed: %d\n", current -> value); //print the popped value
    free(current); //free up current
    return head;
}

void printList(Node *head){
    Node *current = head; //store head into current
    while(current != NULL){ //not current -> value because value is a int
        printf("%d -> ", current -> value); //when current does not equal to NULL it continues printing
        current = current -> next; // moves the current to the next node
    }
    printf("NULL\n");
}

int main(){
    Node *head = NULL;
    int number;
    int value;

    printf("Enter the number of Nodes: ");
    scanf(" %d", &number);

    for(int i = 0; i < number; i ++){
        printf("Enter the value of Node #%d: ", i + 1);
        scanf(" %d", &value);
        head = push(head, value);
    }

    printList(head);
    head = pop(head);
    printList(head);

    return 0;
}