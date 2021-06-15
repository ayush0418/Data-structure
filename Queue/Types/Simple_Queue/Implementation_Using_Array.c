#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int b;
    int *arr;
};

int isFull(struct queue *ptr){
    if(ptr->b == (ptr->size)-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *ptr){
    if(ptr->f == ptr->b){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *ptr, int val){ 
    if(isFull(ptr)){
        printf("Queue is Full\n");
    }
    else{
        ptr->b++;
        ptr->arr[ptr->b] = val;
        printf("Enqued element: %d\n", val);        
    }
}

int dequeue(struct queue *ptr){ 
    int a = -1;
    if(isEmpty(ptr)){
        printf("Queue is Empty\n");
    }
    else{
        ptr->f++;
        a = ptr->arr[ptr->f];
    }
    return a;
}

void printQueue(struct queue *ptr){
    printf("Queue: ");
    for(int i=ptr->f+1;i<ptr->b+1;i++){
        printf("%d ",ptr->arr[i]);
    }
    printf("\n");
}

void peek(struct queue *ptr, int pos){
    int a = 0;
    for(int i = 0;i<pos;i++){
        a = a + 1;
    }
    printf("Element at %d: %d\n", pos, ptr->arr[a + ptr->f]);
}

int main(){
    struct queue q;
    q.size = 100;
    q.b = q.f = -1;
    q.arr = (int *)malloc(q.size*sizeof(int));

    dequeue(&q);
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 45);
    printQueue(&q);
    peek(&q,1);
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printQueue(&q);
    peek(&q,2);
    enqueue(&q, 14);
    enqueue(&q, 18);
    printQueue(&q);
    peek(&q,2);
}