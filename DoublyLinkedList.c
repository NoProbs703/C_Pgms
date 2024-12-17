#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* createList(int arr[], int n) {
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        Node* newNode = createNode(arr[i]);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return head;
}

void insertLeft(Node** head, int target, int data) {
    Node* current = *head;
    while (current && current->data != target) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with value %d not found.\n", target);
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = current;
    newNode->prev = current->prev;

    if (current->prev) {
        current->prev->next = newNode;
    } else {
        *head = newNode;
    }
    current->prev = newNode;
}

void deleteNode(Node** head, int value) {
    Node* current = *head;
    while (current && current->data != value) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }
    if (current->prev) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }
    if (current->next) {
        current->next->prev = current->prev;
    }
    free(current);
    printf("Node with value %d deleted.\n", value);
}

void displayList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    int arr[] = {10, 20, 30, 40, 50};
    head = createList(arr, 5);
    printf("Initial List: ");
    displayList(head);

    printf("Inserting 25 to the left of 30:\n");
    insertLeft(&head, 30, 25);
    displayList(head);

    printf("Deleting the node with value 40:\n");
    deleteNode(&head, 40);
    displayList(head);

    return 0;
}
