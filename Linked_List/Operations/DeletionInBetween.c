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

// Case 3: Deleting the element with a given value from the linked list
struct Node * deleteTheValue(struct Node * head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!= NULL){
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}

// Case 4: Deleting the element at a given index from the linked list
struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index-1; i++){
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    int sizeOfList = 4;

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

    printf("Linked List after Deleting value: \n");
    head = deleteTheValue(head, 15);
    printLinkedList(head);  

    printf("Linked List after Deleting index: \n");
    head = deleteAtIndex(head, 2);
    printLinkedList(head);  
}