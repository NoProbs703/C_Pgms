#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *next;
};

struct node *head = NULL;
struct node *front = NULL, *rear = NULL;

void push(int val)
{
 struct node *newNode = malloc(sizeof(struct node));
 newNode->data = val;
 newNode->next = head;
 head = newNode;
}

void pop()
{
 struct node *temp;
 if(head == NULL)
  printf("Stack is Empty\n");
 else
 {
 printf("Popped element = %d\n", head->data);
 temp = head;
 head = head->next;
 free(temp);
 }
}

void printList1()
{
 struct node *temp = head;
 while(temp != NULL)
 {
 printf("%d->", temp->data);
 temp = temp->next;
 }
 printf("NULL\n");
}

void enqueue(int val)

{
 struct node *newNode = malloc(sizeof(struct node));
 newNode->data = val;
 newNode->next = NULL;
 if(front == NULL && rear == NULL)
  front = rear = newNode;
 else
 {
 rear->next = newNode;
 rear = newNode;
 }
}

void dequeue()
{
 struct node *temp;
 if(front == NULL)
  printf("Queue is Empty. Unable to perform dequeue\n");
 else
 {
  temp = front;
  front = front->next;
  if(front == NULL)
   rear = NULL;
  free(temp);
 }
}

void printList2()
{
 struct node *temp = front;
 while(temp)
 {
  printf("%d->",temp->data);
  temp = temp->next;
 }
 printf("NULL\n");
}
int main()
{
 push(10);
 push(20);
 push(30);
 printf("Linked List\n");
 printList1();
 pop();
 printf("After the pop, the new linked list\n");
 printList1();
 pop();
 printf("After the pop, the new linked list\n");
 printList1();
 enqueue(10);
 enqueue(20);
 enqueue(30);
 printf("Queue :");
 printList();
 dequeue();
 printf("After dequeue the new Queue :");
 printList2();
 dequeue();
 printf("After dequeue the new Queue :");
 printList2();
 return 0;
}
