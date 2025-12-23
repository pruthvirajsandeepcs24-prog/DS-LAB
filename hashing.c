#include<stdio.h>

#define SIZE 10

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key) {
    int index = key % SIZE;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Address %d : %d\n", i, hashTable[i]);
        else
            printf("Address %d : Empty\n", i);
    }
}

int main() {
    int n, key;

    init();

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter 4-digit key: ");
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}


