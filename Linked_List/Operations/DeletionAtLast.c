#include<stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void printLinkedList(struct Node *ptr){
    while (ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 2: Deleting the last element
struct Node * deleteLastNode(struct Node * head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next !=NULL){
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
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

    head->data = 7;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 41;
    third->next = fourth;
    fourth->data = 66;
    fourth->next = NULL;

    printf("Linked List before Deletion: \n");
    printLinkedList(head);

    head = deleteLastNode(head);

    printf("Linked List after Deletion: \n");
    printLinkedList(head);  
}