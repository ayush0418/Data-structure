#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *pre;
};

struct Node *insertAtFirst(int item , struct Node *head){
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = item;
    new_node->pre = NULL;
    
    head->pre = new_node;
    new_node->next = head;
    head = new_node;

    return head;
}

struct Node *insertAtLast(int item , struct Node *head){
    struct Node *new_node = malloc(sizeof(struct Node));
    struct Node *p = head;
    new_node->data = item;
    new_node->next = NULL;
    
    while(p->next != NULL) { p = p->next; }

    p->next = new_node;
    new_node->pre = p;

    return head;
}

struct Node *insertAtIndex(int item, int index, struct Node *head){
    struct Node *new_node = malloc(sizeof(struct Node));
    struct Node *p = head;
    struct Node *q = head->next;

    new_node->data = item;

    for(int i = 0; i < index-1; i++){
        p = p->next;
        q = q->next;
    }

    p->next = new_node;
    new_node->pre = p;
    new_node->next = q;
    q->pre = new_node;

    return head;
}


void printLinkedList(struct Node *head){
    struct Node *p = head;
    while(p->next!= NULL ){                    
        printf("Element: %d\n", p->data);
        p = p->next;
    }
    printf("Element: %d\n", p->data);
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    
    head->data = 4;
    second->data = 11;
    third->data = 15;

    head->pre = NULL;
    head->next = second;
    second->pre = head;
    second->next = third;
    third->pre = second;
    third->next = NULL;
    
    printf("Doubly Linked List Before Insertion \n");
    printLinkedList(head);

    head = insertAtFirst(1,head);
    printf("Doubly Linked List After Insertion At First \n");
    printLinkedList(head);

    head = insertAtLast(18,head);
    printf("Doubly Linked List After Insertion At Last \n");
    printLinkedList(head);

    head = insertAtIndex(14,2,head);
    printf("Doubly Linked List After Insertion At Index 2 \n");
    printLinkedList(head);
}