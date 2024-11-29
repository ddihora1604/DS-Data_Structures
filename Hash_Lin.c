#include <stdio.h>

#define TABLE_SIZE 11

typedef struct {
    int *table;
    int size;
} HashTable;

void initializeHashTable(HashTable *hashTable, int size) {
    hashTable->size = size;
    hashTable->table = (int *)malloc(size * sizeof(int));

    // Initialize all elements to -1 (indicating empty)
    for (int i = 0; i < size; i++) {
        hashTable->table[i] = -1;
    }
}

int hashFunction(int key, int size) {
    return key % size;
}

void insert(HashTable *hashTable, int key) {
    int index = hashFunction(key, hashTable->size);

    while (hashTable->table[index] != -1) {
        // Linear probing in case of collision
        index = (index + 1) % hashTable->size;
    }

    hashTable->table[index] = key;
}

void display(const HashTable *hashTable) {
    printf("Hash Table:\n");
    for (int i = 0; i < hashTable->size; i++) {
        printf("Index %d: %d\n", i, hashTable->table[i]);
    }
}

int main() {
    // Data
    int keys[] = {83, 53, 64, 25, 39, 96, 12, 71};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    // Create a hash table
    HashTable hashTable;
    initializeHashTable(&hashTable, TABLE_SIZE);

    // Insert keys into the hash table
    for (int i = 0; i < numKeys; i++) {
        insert(&hashTable, keys[i]);
    }

    // Display the final hash table
    display(&hashTable);

    // Clean up
    free(hashTable.table);

    return 0;
}
