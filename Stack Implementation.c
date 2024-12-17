#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

int stack[MAX];
int top = -1;   

void push() {
    int value;
    if (top == MAX - 1) {  
        printf("Stack Overflow! Cannot push more elements.\n");
        return;
    }
    printf("Enter the value to push: ");
    scanf("%d", &value);
    top++;
    stack[top] = value; 
    printf("Pushed %d onto the stack.\n", value);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
        return;
    }
    printf("Popped %d from the stack.\n", stack[top]);
    top--; 
}

void peek() {
    if (top == -1) { 
        printf("Stack is empty! No top element.\n");
        return;
    }
    printf("The top element is %d.\n", stack[top]);
}

void display() {
    if (top == -1) {  
        printf("Stack is empty! Nothing to display.\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--) {  
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
