#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size ;
    int top;
    int * arr;
};

int isEmpty(struct stack* ptr){
    if(ptr->top == -1) { return 1; }
    return 0; 
}

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1) { return 1; }
    return 0;
}

int push(struct stack *ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
        return val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main(){
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));
    printf("Stack has been created successfully\n");

    printf("Before pushing stack is Full: %d\n", isFull(s));
    printf("Before pushing stack is Empty: %d\n", isEmpty(s));

    printf("pushed %d \n", push(s,64));     // Insertion
    printf("pushed %d \n", push(s,57)); 
    printf("pushed %d \n", push(s,46)); 
    printf("pushed %d \n", push(s,89)); 
    printf("pushed %d \n", push(s,6));       // ---> Pushed last value 
    printf("\n", push(s,46));                // ---> Stack Overflow since the size of the stack is 5

    printf("After pushing stack is Full: %d\n", isFull(s));
    printf("After pushing stack is Empty: %d\n", isEmpty(s));

    printf("Popped %d \n", pop(s));     // Deletion
    printf("Popped %d \n", pop(s)); 
    printf("Popped %d \n", pop(s)); 
    printf("Popped %d \n", pop(s)); 
    printf("Popped %d \n", pop(s));     // ---> Poped last value
    printf("\n", pop(s));               // ---> Stack Underflow since the stack is empty

    printf("After poping stack is Full: %d\n", isFull(s));
    printf("After poping stack is Empty: %d\n", isEmpty(s));

    return 0;
}