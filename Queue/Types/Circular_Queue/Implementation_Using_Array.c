#include<stdio.h>
#include<stdlib.h>

struct circularQueue{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct circularQueue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int val){
    if(isFull(q)){
        printf("This Queue is full");
    }
    else{
        q->r = (q->r +1)%q->size;
        q->arr[q->r] = val; 
        printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct circularQueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty");
    }
    else{
        q->f = (q->f +1)%q->size;
        a = q->arr[q->f]; 
    }
    return a;
}

void peek(struct circularQueue *ptr, int pos){
    int a = 0;
    for(int i = 0;i<pos;i++){
        a = a + 1;
    }
    printf("Element at %d: %d\n", pos, ptr->arr[a + ptr->f]);
}

void printQueue(struct circularQueue *ptr){
    printf("Circular Queue: ");
    for(int i = ptr->f+1; i < ptr->r+1; i++){
        printf("%d ", ptr->arr[i]);
    }
    printf("\n");
}

int main(){
    struct circularQueue q;
    q.size = 10;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 5);
    printQueue(&q);
    peek(&q,2);
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printQueue(&q);
    peek(&q,1);
    enqueue(&q, 18);
    enqueue(&q, 16);
    enqueue(&q, 4);
    printQueue(&q);
    peek(&q,2);
    return 0;
}