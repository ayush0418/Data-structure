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

void enqueueRear(struct queue *ptr, int val){ 
    if(isFull(ptr)){
        printf("Queue is Full\n");
    }
    else{
        ptr->b++;
        ptr->arr[ptr->b] = val;
        printf("Enqued element in Rear: %d\n", val);        
    }
}

void enqueueFront(struct queue *ptr, int val){ 
    if(isFull(ptr)){
        printf("Queue is Full\n");
    }
    else{
        ptr->arr[ptr->f] = val;
        ptr->f--;
        printf("Enqued element in Front: %d\n", val);        
    }
}

int dequeueRear(struct queue *ptr){ 
    int a = -1;
    if(isEmpty(ptr)){
        printf("Queue is Empty\n");
    }
    else{
        a = ptr->arr[ptr->b];
        ptr->b--;
    }
    return a;
}


int dequeueFront(struct queue *ptr){ 
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

    enqueueRear(&q, 10);
    enqueueRear(&q, 20);
    enqueueFront(&q, 30);
    enqueueRear(&q, 40);

    printQueue(&q);
    peek(&q,2);
    printf("Dequeuing element in Front %d\n", dequeueFront(&q));    
    printQueue(&q);
    printf("Dequeuing element in Rear %d\n", dequeueRear(&q));    
    printQueue(&q);
    
    enqueueFront(&q, 50);
    enqueueRear(&q, 60);
    enqueueFront(&q, 70);
    enqueueRear(&q, 80);

    printQueue(&q);
    peek(&q,2);
    printf("Dequeuing element in Front %d\n", dequeueFront(&q));
    printf("Dequeuing element in Rear %d\n", dequeueRear(&q));
    printQueue(&q);
    printf("Dequeuing element in Rear %d\n", dequeueRear(&q));
    printf("Dequeuing element in Front %d\n", dequeueFront(&q));
    printQueue(&q);

    enqueueRear(&q, 90);
    enqueueRear(&q, 100);
    printQueue(&q);
    peek(&q,1);

    enqueueFront(&q, 110);
    enqueueFront(&q, 120);
    printQueue(&q);
    peek(&q,2);
}