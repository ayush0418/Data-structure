#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1) { return 1; }
    return 0;
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1) { return 1; }
    return 0;
}

int main(){
    struct stack *s;
    s->size = 10;
    s->top = -1;
    s->arr = (int*) malloc(s->size*sizeof(int));

    printf("Stack is Full: %d\n", isFull(s));
    printf("Stack is Empty: %d\n", isEmpty(s));

}