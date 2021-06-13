#include <stdio.h>
#include <stdlib.h>
#define MAX 7

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
int isFull(st ptr) {
    if (ptr.top == MAX - 1)
        return 1;
    else
        return 0;
}

// Check if the stack is empty
int isEmpty(st ptr) {
    if (ptr.top == -1)
        return 1;
    else
        return 0;
}

// Add elements into stack
void push(int newitem, st *ptr) {
    if (!isFull(*ptr)) {
        ptr->items[ptr->top + 1] = newitem;
        ptr->top++;
    }
}

// Remove element from stack
int pop(st *ptr) {
    int ans;
    if (isEmpty(*ptr)) {
        printf("\nSTACK EMPTY \n");
        ans = 0;
    } 
    else {
        ans = ptr->items[ptr->top];
        ptr->top--;
    }
    return ans;
}

int main() {
    int price[7] = {100,80,60,70,60,75,85};
    int span[7] = { 0 };

    struct stack s,temp;

    createEmptyStack(&s);
    createEmptyStack(&temp);

    span[0] = 1;
    push(price[0],&s);

    for(int i=0;i<7;i++){
        int count =1;
        while(!isEmpty(s) && s.items[s.top] <= price[i]){
            push(pop(&s),&temp);  
            count++;
        }
        while(!isEmpty(temp)){
            push(pop(&temp),&s);
        }
        push(price[i],&s);
        span[i] = count++;
    }

    for(int i=0;i<7;i++){
        printf("%d ",span[i]);
    }
}