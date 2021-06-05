#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void printLinkedList(struct Node *head){
    struct Node *p = head;
    while(p->next!= head ){                    
        printf("Element: %d\n", p->data);
        p = p->next;
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

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;
    
    printLinkedList(head);
}