#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *pre;
};

void printLinkedList(struct Node *head){
    struct Node *p = head;

    printf("Elements in same order \n");
    while(p->next!= NULL ){                    
        printf("Element: %d\n", p->data);
        p = p->next;
    }
    printf("Element: %d\n", p->data);

    printf("Elements in Backward order \n");
    while(p->pre!= NULL ){                    
        printf("Element: %d\n", p->data);
        p = p->pre;
    }
    printf("Element: %d\n", p->data);
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    
    head->data = 4;
    second->data = 11;
    third->data = 15;
    fourth->data = 18;

    head->pre = NULL;
    head->next = second;
    second->pre = head;
    second->next = third;
    third->pre = second;
    third->next = fourth;
    fourth->pre = third;
    fourth->next = NULL;
    
    printLinkedList(head);
}