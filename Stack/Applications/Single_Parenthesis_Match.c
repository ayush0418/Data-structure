#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int count = 0;

struct stack{
    int top;
    int size;
    char *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}

void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("\nStack overflow\n");
    }
    else{
        printf("Item pushed= %d\n", val);
        ptr->top++;
        ptr->arr[ptr->top] = val;
        count++;
    }
}

char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("\nStack underflow\n");
    }
    else{
        printf("Item popped= %d\n",ptr->arr[ptr->top]);
        char val = ptr->arr[ptr->top];
        ptr->top--;
        count--;
    }
}

// Print elements of stack
void printStack(struct stack *ptr) {
  printf("Stack: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", ptr->arr[i]);
  }
  printf("\n");
}

int Single_Parenthesis_Match(char *exp){
    struct stack *sp;
    sp->size = strlen(exp);        // size of stack according to the expression size.
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));

    for(int i=0; exp[i]!= '\0'; i++){
        if(exp[i]=='('){
            push(sp,'(');
            printStack(sp);
        }
        else if(exp[i] == ')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
            printStack(sp);
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    return 0; 
}

int main(){
    char *exp = "((8)(*--$$9))";

    if(Single_Parenthesis_Match(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    return 0;
}