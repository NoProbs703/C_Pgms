#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1 

int h[TABLE_SIZE]; 

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert() {
    int key, index, i, hkey;
    printf("Enter a value to insert into the hash table: ");
    scanf("%d", &key);

    hkey = hashFunction(key); 

    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i) % TABLE_SIZE; 
        if (h[index] == EMPTY) { 
            h[index] = key;
            printf("Inserted key %d at index %d\n", key, index);
            return;
        }
    }
    printf("Hash table is full. Cannot insert key %d.\n", key);
}

void search() {
    int key, index, i, hkey;
    printf("Enter search element: ");
    scanf("%d", &key);

    hkey = hashFunction(key);  

    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i) % TABLE_SIZE; 
        if (h[index] == key) {  
            printf("Value %d is found at index %d\n", key, index);
            return;
        }
        if (h[index] == EMPTY) { 
            break;
        }
    }
    printf("Value %d is not found in the hash table.\n", key);
}

void display() {
    printf("Elements in the hash table are:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (h[i] == EMPTY) {
            printf("Index %d: EMPTY\n", i);
        } else {
            printf("Index %d: %d\n", i, h[i]);
        }
    }
}

int main() {
    int opt;

    for (int i = 0; i < TABLE_SIZE; i++) {
        h[i] = EMPTY;
    }

    while (1) {
        printf("\n1. Insert\n2. Display\n3. Search\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
