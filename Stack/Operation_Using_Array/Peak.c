#include <stdio.h>
#include <stdlib.h>
#define MAX 5

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
    printf("Item pushed= %d\n", newitem);
    ptr->top++;
    ptr->items[ptr->top] = newitem;
  }
}

// Printing element at position
int peak(st *ptr, int i){
    if(ptr->top-i+1 < 0){
        printf("Element Not Found");
        return -1;
    }
    else{
        return ptr->items[ptr->top-i+1];
    }
}

int main() {
  st *s = (st *)malloc(sizeof(st));

  createEmptyStack(s);

  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);
  push(s, 5);

  for(int j=1; j<= s->top+1;j++){
    printf("The value at position %d is %d\n",j, peak(s,j));
  } 
}