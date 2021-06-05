#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *deleteAtFirst(struct Node *head){
    struct Node *p = head;
    struct Node *q = head;

    while(p->next != head) { p = p->next; }
    p->next = head->next;
    head = head->next;

    free(q);
    return head;
}

struct Node *deleteAtLast(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->next != head){
        p = p->next;
        q = q->next;
    }
    p->next = head;

    free(q);
    return head;
}

struct Node *deleteAtIndex(int index,struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;

    for(int i = 0; i < index-1; i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;

    free(q);
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

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head;
 
    printf("Linked List before deletion: \n");
    printLinkedList(head);

    head = deleteAtFirst(head);

    printf("Linked List after deleting First Node: \n");
    printLinkedList(head);

    head = deleteAtLast(head);

    printf("Linked List after deleting Last Node: \n");
    printLinkedList(head);  

    head = deleteAtIndex(2,head);

    printf("Linked List after deleting index 2: \n");
    printLinkedList(head);  
}