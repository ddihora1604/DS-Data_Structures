#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a new node at the end of the linked list
void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display all elements from the list in reverse order
void displayReverse(Node* head) {
    if (head == NULL) {
        return;
    }

    displayReverse(head->next);
    printf("%d -> ", head->data);
}

// Function to split the list into two lists (ODD and EVEN numbers)
void splitList(Node* head, Node** oddList, Node** evenList) {
    while (head != NULL) {
        if (head->data % 2 == 0) {
            // Even number, add to evenList
            insert(evenList, head->data);
        } else {
            // Odd number, add to oddList
            insert(oddList, head->data);
        }
        head = head->next;
    }
}

// Function to display elements of a linked list
void displayList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory used by the linked list
void freeList(Node** head) {
    Node* current = *head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int main() {
    // Create a sample linked list
    Node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    // Display the original linked list
    printf("Original List: ");
    displayList(head);

    // 1. Display all elements from the list in reverse order
    printf("\nReversed List: ");
    displayReverse(head);
    printf("NULL\n");

    // 2. Split the list into two lists (ODD and EVEN numbers)
    Node* oddList = NULL;
    Node* evenList = NULL;
    splitList(head, &oddList, &evenList);

    // Display the ODD numbers list
    printf("\nODD Numbers List: ");
    displayList(oddList);

    // Display the EVEN numbers list
    printf("EVEN Numbers List: ");
    displayList(evenList);

    // Free the memory used by the linked lists
    freeList(&head);
    freeList(&oddList);
    freeList(&evenList);

    return 0;
}