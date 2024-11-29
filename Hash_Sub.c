#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int key;
    struct Node* next;
} Node;
typedef struct {
    Node* head;
} HashTableEntry;
typedef struct {
    HashTableEntry* table;
    int size;
} HashTable;
void initializeHashTable(HashTable* hashTable, int size) {
    hashTable->size = size;
    hashTable->table = (HashTableEntry*)malloc(size * sizeof(HashTableEntry));

    // Initialize each entry in the hash table
    for (int i = 0; i < size; i++) {
        hashTable->table[i].head = NULL;
    }
}
int subtractionHash(int key, int base) {
    return key - base;
}
int digitExtractionHash(int key, int digitPosition) {
    int divisor = 1;
    for (int i = 0; i < digitPosition; i++) {
        divisor *= 10;
    }
    return (key / divisor) % 10;
}
void insert(HashTable* hashTable, int key, int hashFunctionType, int base) {
    int index;

    if (hashFunctionType == 1) {
        index = subtractionHash(key, base);
    } else if (hashFunctionType == 2) {
        index = digitExtractionHash(key, base);
    } else {
        printf("Invalid hash function type.\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    if (hashTable->table[index].head == NULL) {
        hashTable->table[index].head = newNode;
    } else {
        // If the entry is not empty, add the new node to the front of the linked list
        newNode->next = hashTable->table[index].head;
        hashTable->table[index].head = newNode;
    }
}
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
    
    int keysStart = 100111;
    int keysEnd = 100130;
    int numKeys = keysEnd - keysStart + 1;
    int hashTableSize = 10; 
    HashTable hashTableSubtraction;
    initializeHashTable(&hashTableSubtraction, hashTableSize);
    for (int key = keysStart; key <= keysEnd; key++) {
        insert(&hashTableSubtraction, key, 1, keysStart);
    }
    printf("Hash Table using Subtraction Hash Function:\n");
    display(&hashTableSubtraction);
    freeHashTable(&hashTableSubtraction);
    HashTable hashTableDigitExtraction;
    initializeHashTable(&hashTableDigitExtraction, hashTableSize);
    for (int key = keysStart; key <= keysEnd; key++) {
        insert(&hashTableDigitExtraction, key, 2, 0);
    }
    printf("\nHash Table using Digit Extraction Hash Function:\n");
    display(&hashTableDigitExtraction);
    freeHashTable(&hashTableDigitExtraction);
    return 0;
}
