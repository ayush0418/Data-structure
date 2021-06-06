#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size ;
    int top;
    int * arr;
};

// Check if the stack is EMPTY
int isEmpty(struct stack* ptr){
    if(ptr->top == -1) { return 1; }
    return 0; 
}

// Check if the stack is FULL
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size - 1) { return 1; }
    return 0;
}

int main(){
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));
    printf("Stack has been created successfully\n");

    printf("Stack is Full: %d\n", isFull(s));
    printf("Stack is Empty: %d\n", isEmpty(s));
    return 0;
}