#include<stdio.h>
#include<stdlib.h>

// Creating a Node
struct Node{
    int data;
    struct Node *next;
};
struct Node* top = NULL;

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
int pop(struct Node* tp){
    if(isEmpty(tp)){
        printf("\nStack Underflow! Cannot pop from the stack\n");
    }
    else{
        printf("\nItem popped= %d",tp->data);
        struct Node *n = tp;
        top = tp->next;
        free(n);
    }
}

// Printing stack elements
void StackLinkedListTraversal(struct Node *ptr) {
    printf("Stack: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 5);
    
    printf("\nAfter pushing in\n");
    StackLinkedListTraversal(top);

    
    pop(top);
    pop(top);
    pop(top);

    printf("\nAfter popping out\n");
    StackLinkedListTraversal(top);

    return 0;
}