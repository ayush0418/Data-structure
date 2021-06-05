#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *pre;
};

struct Node *deleteAtFirst(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;

    q->pre = NULL;
    head = head->next;
    free(p);
    return head;
}

struct Node *deleteAtLast(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}

struct Node *deleteAtIndex(int index, struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;
    struct Node *r = head->next->next;

    for(int i = 0; i < index-1; i++){
        p = p->next;
        q = q->next;
        r = r->next;
    }
    p->next = r;
    r->pre = p;
    free(q);
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
    struct Node *fourth;
    struct Node *fifth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    
    head->data = 4;
    second->data = 7;
    third->data = 11;
    fourth->data = 15;
    fifth->data = 18;

    head->pre = NULL;
    head->next = second;
    second->pre = head;
    second->next = third;
    third->pre = second;
    third->next = fourth;
    fourth->pre = third;
    fourth->next = fifth;
    fifth->pre  = fourth;
    fifth->next = NULL;
    
    printf("Linked List before deletion: \n");
    printLinkedList(head);

    head = deleteAtFirst(head);
    printf("Linked List after deleting First Node: \n");
    printLinkedList(head);

    head = deleteAtLast(head);
    printf("Linked List after deleting Last Node: \n");
    printLinkedList(head);  

    head = deleteAtIndex(1,head);
    printf("Linked List after deleting index 1: \n");
    printLinkedList(head);  
}