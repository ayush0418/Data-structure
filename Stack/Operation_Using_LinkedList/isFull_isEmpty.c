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

int main(){
    struct Node *top = NULL;
    printf("Stack using Linked List has been created sucessfully\n");

    printf("Stack is Full: %d\n", isFull(top));
    printf("Stack is Empty: %d\n", isEmpty(top));
    return 0;
}