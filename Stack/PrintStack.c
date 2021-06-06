#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int count = 0;

// Creating a stack
struct stack {
  int items[MAX];
  int top;
};
typedef struct stack st;

void createEmptyStack(st *s) {
  s->top = -1;
}

// Check if the stack is full
int isFull(st *ptr) {
  if (ptr->top == MAX - 1)
    return 1;
  else
    return 0;
}

// Check if the stack is empty
int isEmpty(st *ptr) {
  if (ptr->top == -1)
    return 1;
  else
    return 0;
}

// Add elements into stack
void push(st *ptr, int newitem) {
  if (isFull(ptr)) {
    printf("STACK FULL \n");
  } 
  else {
    printf("\nItem pushed= %d", newitem);
    ptr->top++;
    ptr->items[ptr->top] = newitem;
    count++;
  }
}

// Remove element from stack
void pop(st *ptr) {
  if (isEmpty(ptr)) {
    printf("\nSTACK EMPTY \n");
  } 
  else {
    printf("\nItem popped= %d", ptr->items[ptr->top]);
    ptr->top--;
    count--;
  }
}

// Print elements of stack
void printStack(st *ptr) {
  printf("Stack: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", ptr->items[i]);
  }
  printf("\n");
}


int main() {
  st *s = (st *)malloc(sizeof(st));

  createEmptyStack(s);

  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);
  push(s, 5);

  printf("\nAfter pushing in\n");
  printStack(s);

  push(s, 6);

  pop(s);
  pop(s);
  pop(s);
  pop(s);
  printf("\nAfter popping out\n");
  printStack(s);

  pop(s);
  pop(s);
}