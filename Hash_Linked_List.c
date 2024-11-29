#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Structure for each element in the hash table
typedef struct {
    Node* head;
} HashTableEntry;

// Structure for the hash table
typedef struct {
    HashTableEntry* table;
    int size;
} HashTable;

// Function to initialize the hash table
void initializeHashTable(HashTable* hashTable, int size) {
    hashTable->size = size;
    hashTable->table = (HashTableEntry*)malloc(size * sizeof(HashTableEntry));

    // Initialize each entry in the hash table
    for (int i = 0; i < size; i++) {
        hashTable->table[i].head = NULL;
    }
}

// Function to compute the hash function using modulo division
int hashFunction(int key, int size) {
    return key % size;
}

// Function to insert a key into the hash table using linked list for collision resolution
void insert(HashTable* hashTable, int key) {
    int index = hashFunction(key, hashTable->size);

    // Create a new node for the key
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    // If the entry is empty, insert the new node as the head
    if (hashTable->table[index].head == NULL) {
        hashTable->table[index].head = newNode;
    } else {
        // If the entry is not empty, add the new node to the front of the linked list
        newNode->next = hashTable->table[index].head;
        hashTable->table[index].head = newNode;
    }
}

// Function to display the hash table
void display(const HashTable* hashTable) {
    printf("Hash Table:\n");
    for (int i = 0; i < hashTable->size; i++) {
        printf("Index %d: ", i);
        Node* current = hashTable->table[i].head;
        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Function to free the memory used by the linked list in each hash table entry
void freeHashTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        Node* current = hashTable->table[i].head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashTable->table);
}

int main() {
    // Data
    int keys[] = {83, 53, 64, 25, 39, 96, 12, 71};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    // Create a hash table
    HashTable hashTable;
    initializeHashTable(&hashTable, 11);

    // Insert keys into the hash table
    for (int i = 0; i < numKeys; i++) {
        insert(&hashTable, keys[i]);
    }

    // Display the final hash table
    display(&hashTable);

    // Free the memory used by the hash table
    freeHashTable(&hashTable);

    return 0;
}
