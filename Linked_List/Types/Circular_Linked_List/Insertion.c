#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *insertAtFirst(int item, struct Node *head){
    struct Node *new_node = malloc(sizeof(struct Node));
    struct Node *p = head;

    new_node->data = item;
    new_node->next = head;

    while(p->next != head) { p = p->next; }

    p->next = new_node;
    new_node->next = head;

    /* head = new_node -->changes head to new element and thus element is inserted in beginning 
    if we want to insert element at the end of list then don't change head position.*/
    head = new_node;            
    return head;
}

struct Node *insertAtIndex(int item, int index, struct Node *head){
    struct Node *new_node = malloc(sizeof(struct Node));
    struct Node *p = head;
    struct Node *q = head->next;

    new_node->data = item;

    for(int i=0;i<index-1;i++){
        p = p->next;
        q = q->next;
    }

    p->next = new_node;
    new_node->next = q;
    return head;
}


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
    second->data = 7;
    third->data = 11;
    fourth->data = 15;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;
    
    printf("Circular Linked List Before Insertion \n");
    printLinkedList(head);

    head = insertAtFirst(18,head);
    
    printf("Circular Linked List After Insertion \n");
    printLinkedList(head);

    head = insertAtIndex(33,2,head);
    printf("Circular Linked List After Insertion At Index 2 \n" );
    printLinkedList(head);
}