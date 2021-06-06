#include<stdio.h>
#include<stdlib.h>

// Creating a stack
struct stack{
  int size ;
  int top;
  int * arr;
};

// Check if the stack is empty
int isEmpty(struct stack* ptr){
  if(ptr->top == -1) { return 1; }
  return 0; 
}

// Check if the stack is full
int isFull(struct stack* ptr){
  if(ptr->top == ptr->size - 1) { return 1; }
  return 0;
}

// Add elements into stack
void push(struct stack *ptr, int val){
  if(isFull(ptr)){
    printf("\nStack Overflow! Cannot push %d to the stack\n", val);
  }
  else{
    printf("\nItem pushed= %d", val);
    ptr->top++;
    ptr->arr[ptr->top] = val;
  }
}

// Remove elements from stack
int pop(struct stack *ptr){
  if(isEmpty(ptr)){
    printf("\nStack Underflow! Cannot pop from the stack\n");
    return -1;
  }
  else{
    printf("\nItem popped= %d", ptr->arr[ptr->top]);
    int val = ptr->arr[ptr->top];
    ptr->top--;
  }
}

int main(){
  struct stack *s = (struct stack *) malloc(sizeof(struct stack));
  s->size = 5;
  s->top = -1;
  s->arr = (int *) malloc(s->size * sizeof(int));
  printf("Stack has been created successfully\n");

  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);
  push(s, 5);
  push(s, 6);

  pop(s);
  pop(s);
  pop(s);
  pop(s);
  pop(s);
  pop(s);
  
  return 0;
}