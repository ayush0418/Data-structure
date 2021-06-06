#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size ;
    int top;
    int * arr;
};

int main(){
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));
    printf("Stack has been created successfully\n");

    return 0;
}