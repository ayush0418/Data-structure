#include<stdio.h>
#include<stdlib.h>

// Creating a Node
struct Node{
    int data;
    struct Node *next;
};

// Check if the stack is empty
int isEmpty(struct Node *top){
    if(top == NULL){
        return 1;
    }
    return 0; 
}

// Check if the stack is full
int isFull(struct Node *top){
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL){
        return 1;
    }
    return 0; 
}

// Add elements into stack
struct Node* push(struct Node *top, int x){
    if(isFull(top)){
        printf("\nStack Overflow! Cannot push %d to the stack\n", x);
    }
    else{
        struct Node *n = (struct Node*)malloc(sizeof(struct Node));
        printf("\nItem pushed= %d", x);
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

// Remove elements from stack
int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("\nStack Underflow! Cannot pop from the stack\n");
    }
    else{
        printf("\nItem popped= %d",(*top)->data);
        struct Node *n = *top;
        *top = (*top)->next;
        free(n);
    }
}

int main(){
    struct Node *top = NULL;
    printf("Stack using Linked List has been created sucessfully");

    top = push(top,1);
    top = push(top,2);
    top = push(top,3);

    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);
    return 0;
}