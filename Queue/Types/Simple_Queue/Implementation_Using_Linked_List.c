#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;

struct Node{
    int data;
    struct Node *next;
};

void enqueue(int val){
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL){               // isFull condition...
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        printf("Enqued element: %d\n", n->data);                
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}

int dequeue(){
    int val = -1;
    struct Node *ptr = f;
    if(f==NULL){                       //isEmpty condition...
        printf("Queue is Empty\n");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

void linkedListTraversal(struct Node *ptr){
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}



int main(){
    linkedListTraversal(f);
    printf("Dequeuing element %d\n", dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    linkedListTraversal(f);

    return 0;
}