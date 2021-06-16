#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;   // Entry End(Back)
    int *arr;
    int size;
    int p;     // Exit End(Front)
};

int isFull(struct stack *ptr){
    if(ptr->top == (ptr->size)-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *ptr){
    if(ptr->top == ptr->p){
        return 1;
    }
    return 0;
}

void enqueue(struct stack *ptr, int val){ 
    if(isFull(ptr)){
        printf("Queue is Full\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("Enqued element: %d\n", val);        
    }
}

int dequeue(struct stack *ptr){ 
    int a = -1;
    if(isEmpty(ptr)){
        printf("Queue is Empty\n");
    }
    else{
        ptr->p++;
        a = ptr->arr[ptr->p];
    }
    return a;
}

void printFront(struct stack *ptr){
    int front;
    front = ptr->arr[(ptr->p)+1];
    printf("Front Element: %d\n", front);
}

int main(){
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->p = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    int x;
    printf("\nEnter queries: ");
    scanf("%d",&x);

    while(x--){
        int opr;
        printf("\nEnetr Operation: ");
        scanf("%d",&opr);

        if(opr == 1){
            int val;
            printf("\nOpr 1 (Enetr VAl): ");
            scanf("%d" ,&val);

            enqueue(s,val);
        }
        else if(opr == 2){
            printf("\nOpr 2: ");
            printf("Dequeuing element %d\n", dequeue(s));
        }
        else if(opr == 3){
            printf("\nOpr 3: ");
            printFront(s);
        }

    }

    return 0;
}