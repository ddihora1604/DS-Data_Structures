#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

struct Node *createNode(int info){
    Node *node = (Node *)malloc(sizeof(Node));
    node ->data = info;
    node ->next = NULL;
    return node;
}

struct Node *node, *start = NULL, *q, *temp;

void insertAtBegin(int info){
    temp = createNode(info);
    if(start == NULL){
        temp->next = temp;
        start = temp;
    }else if(start->next == start){
        temp->next = start;
        start = temp;
        start->next->next = start;
    }else{
        q = start;
        while(q->next != start){
            q = q->next;
        }
        temp->next = start;
        start = temp;
        q->next = start;
    }
}

void insertAtLast(int info){
    temp = createNode(info);
    q = start;
    while(q->next != start){
        q = q->next;
    }
    q->next = temp;
    temp->next = start;
}


void deleteAtFront(){
    if(start == NULL){
        printf("LL is Empty");
    }else if(start->next == start){
        free(start);
        start = NULL;
    }else{
        q = start;
        while(q->next != start){
            q = q->next;
        }
        temp = start;
        start = temp->next;
        q->next = start;
        free(temp);
    }
}

void deleteAtLast(){
    if(start == NULL){
        printf("LL is Empty");
    }else if(start->next == start){
        free(start);
        start = NULL;
    }else{
        q = start;
        while(q->next->next != start){
            q = q->next;
        }
        temp = q->next;
        q->next = start;
        free(temp);
    }
}

void display() {
    if (start == NULL) {
        printf("LL is Empty.");
    } else {
        q = start;
        do {
            printf("%d-> ", q->data);
            q = q->next;
        } while (q != start);
        printf("NULL\n");
    }
}



int main() {
    int n,choice;
    do{
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice){
                case 1:
                printf("Enter data: ");
                scanf("%d", &n);
                insertAtBegin(n);
                display();
                break;
                
                case 2:
                printf("Enter data: ");
                scanf("%d", &n);
                insertAtLast(n);
                display();
                break;

                case 3:
                deleteAtFront();
                display();
                break;

                case 4: 
                deleteAtLast();
                display();
                break;

                case 5:
                exit(0);
                break;

                default:
                printf("\nEnter a valid input");
                break;
        }
    }while(choice!=5);
    return 0;
}