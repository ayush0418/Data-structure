#include <stdio.h>
#include <stdlib.h>

// Creating a node
struct Node {
  int data;
  struct Node *next;
};

void insertAtBeginning(int data, struct Node **ref) {
  // Allocate memory for a new node
  struct Node *new_node = malloc(sizeof(struct Node));
  // Store data
  new_node->data = data;
  // Change next of new node to point to head
  new_node->next = *ref;
  // Change head to point to recently created node
  *ref = new_node;
}

// Print the linked list
void printLinkedList(struct Node *node) {
  while (node != NULL) {
    printf(" %d ", node->data);
    node = node->next;
  }
}

int main() {
    struct Node *head;
    struct Node *second;

    head   = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;
    second->data = 11;
    second->next = NULL;

    printf("Linked List before inserting: ");
    printLinkedList(head);
    
    insertAtBeginning(2, &head);
    insertAtBeginning(3, &head);

    printf("\nLinked list: ");
    printLinkedList(head);

}