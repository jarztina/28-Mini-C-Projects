#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

// Make a function to enqueue the numbers
Node *enqueue(Node *head, int value)
{
    Node *newNode = malloc(sizeof(Node));
    Node *temp = head;
    if(temp == NULL){
        newNode -> value = value;
        newNode -> next = NULL;
        return newNode;
    }
    else{
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        newNode -> value = value;
        newNode -> next = NULL;
        temp -> next = newNode;
        return head;
    }

}

// Make a function to print the initial list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Make a function to print the peek
void printPeek(Node *head)
{
    Node *temp = head;
    printf("\nPeek: %d\n", temp->value);
}

Node *dequeue(Node *head){ //double pointer is used so u can change what the original points to
    if(head == NULL){
        printf("Queue is empty!");
        return NULL;
    }
    int value = head -> value; //save the value of head
    Node *temp = head; //store head into the temp
    head = head -> next; //move the head to the next node
    free(temp); //kill previous head
    printf("Dequeued: %d\n", value);
    return head; //returns new head
}

int main()
{
    Node *head = NULL;
    int number;
    int value = 0;

    printf("Enter how many numbers to be enqueued: ");
    scanf("%d", &number);
    
    for (int i = 0; i < number; i++)
    {
        printf("Enter the value for #%d: ", i + 1);
        scanf("%d", &value);
        head = enqueue(head, value);
    }

    printList(head); // initial print before deuqueue
    printPeek(head);
    for(int i =0; i < number; i++){
        head = dequeue(head); // head = new head
    }
    printList(head);

    return 0;
}