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
        printf("Stack Overflow\n");
    }
    else{
        struct Node *n = (struct Node*)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

// Printing element at position
int peek(struct Node *top, int x){
    struct Node* n = top;
    for (int i=0; (i < x-1 && top!=NULL); i++){
        top = top->next;
    }
    if(top!=NULL){ return top->data; }
    else{ return -1; }
}

int main(){
    struct Node *top = NULL;
    printf("Stack using Linked List has been created sucessfully\n");


    top = push(top,1);
    top = push(top,2);
    top = push(top,3);
    top = push(top,4);
    top = push(top,5);

    for(int j=1; j<= 5;j++){
    printf("The value at position %d is %d\n",j, peek(top,j));
  } 
}