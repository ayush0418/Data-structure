#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *top){
    if(top == NULL){
        return 1;
    }
    return 0; 
}

int isFull(struct Node *top){
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL){
        return 1;
    }
    return 0; 
}

struct Node* push(struct Node *top, int x){
    if(isFull(top)){
        printf("\nStack Overflow! Cannot push %d to the stack\n", x);
    }
    else{
        struct Node *n = (struct Node*)malloc(sizeof(struct Node));
        printf("\nItem pushed= %d\n", x);
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

char pop(struct Node** top){
    if(isEmpty(*top)){
        printf("\nStack Underflow! Cannot pop from the stack\n");
    }
    else{
        printf("\nItem popped= %d\n",(*top)->data);
        struct Node *n = *top;
        *top = (*top)->next;
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

int match(char a, char b){
    if((a =='{' && b =='}') || (a =='(' && b ==')') || (a =='[' && b ==']')){ 
        return 1; 
    }
    else { 
        return 0; 
    }  
}

int Multiple_Parenthesis_Match(char * exp){
    struct Node *top = NULL;
    char popped_ch;

    for (int i = 0; exp[i]!='\0'; i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            top = push(top, exp[i]);
            StackLinkedListTraversal(top);
        }
        else if(exp[i]==')'|| exp[i]=='}' || exp[i]==']'){
            if(isEmpty(top)){ return 0; }
            
            popped_ch = top->data;
            pop(&top);
            
            StackLinkedListTraversal(top);
            if(!match(popped_ch, exp[i])){ return 0; }
        }
    }
    if(isEmpty(top)){ return 1; }
    else{ return 0; }
}

int main(){
    char * exp = "[(){{}}]";
    
    if(Multiple_Parenthesis_Match(exp)){
        printf("\nThe parenthesis is balanced");
    }
    else{
        printf("\nThe parenthesis is not balanced");
    }
    return 0;
}