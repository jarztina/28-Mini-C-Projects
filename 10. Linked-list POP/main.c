#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ //create a struct of Node
    int value; //stores value
    struct Node *next; //pointer of next (used to point to next address)
}Node;

Node *push(Node *head, int value){
    Node *newNode = malloc(sizeof(Node)); //make a new Node
    newNode -> next = head; //make newNode point to whatever head is pointing to
    newNode -> value = value;
    return newNode;
}
// head = NULL
// head -> next = NULL

Node *pop(Node *head){
    if(head == NULL || head -> next == NULL){ //edge case (preventive measures)
        return NULL;
    }

    Node *current = head;
    while(current -> next -> next != NULL){ //points to the second last node
        current = current -> next;
    }
    current -> next = NULL;
    return head;

}

void printList(Node *head){
    Node *current = head;
    while(current != NULL){
        printf("%d -> ", current -> value);
        current = current -> next; //jump to the address stored in next
    }
    printf("NULL\n");
}

int main(){
    Node *head = NULL;
    int number = 0;
    int value = 0;

    printf("Enter the number of nodes: ");
    scanf(" %d", &number);

    for(int i =0; i < number; i++){
        printf("Enter the number at Node #%d: ", i + 1);
        scanf(" %d", &value);
        head = push(head, value); //whatever push returns we store in head
    }

    printList(head);
    head = pop(head);
    printList(head);

    return 0;
}