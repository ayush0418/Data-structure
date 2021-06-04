#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

// Insert Elements in between
void insertAfter(int item, struct Node *node) {
  if (node == NULL) {
    printf("\nThe given previous node cannot be Null");
    return;
  }

  // Allocate memory and store data for new node
  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->data = item;
  // Traverse to node just before the required position of new node
  new_node->next = node->next;
  // Change next pointers to include new node in between
  node->next = new_node;
}

// Print the linked list
void printLinkedList(struct Node *node) {
  while (node != NULL) {
    printf(" %d ", node->data);
    node = node->next;
  }
}

int main() {
    struct Node *head;    // This is the first Node
    struct Node *second;  // This is the second Node
    struct Node *third;   // This is the third Node

    head = (struct Node *)malloc(sizeof(struct Node));
    second  = (struct Node *)malloc(sizeof(struct Node));
    third  = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;
    second->data  = 11;
    second->next  = third;
    third->data  = 15;
    third->next  = NULL;

    printf("Linked List before inserting: ");
    printLinkedList(head);

    insertAfter(5, head);  // Insert after head node
    printf("\nLinked list Iteration1: ");
    printLinkedList(head);

    insertAfter(10,second); // Insert after second node
    printf("\nLinked list Iteration2: ");
    printLinkedList(head);

    insertAfter(14,third->next);  // Insert after third->next node that is null.
    printf("\nLinked list Iteration3: ");
    printLinkedList(head); 
}
