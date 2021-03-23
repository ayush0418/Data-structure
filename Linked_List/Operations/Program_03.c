#include <stdio.h>
#include <stdlib.h>

// Creating a node
struct Node {
  int data;
  struct Node *next;
};

void insertAtEnd(int item, struct Node **ref) {
  // Allocate memory for a new node  
  struct Node *new_node =  malloc(sizeof(struct Node));
  // Store data
  new_node->data = item;
  new_node->next = NULL;
  
  // To check that whether the linked list is empty or not.
  if (*ref == NULL) {
    *ref = new_node;
    return;
  }

  // Traverse to last node
  struct Node *last = *ref;
  while (last->next != NULL){
    last = last->next;
  }
  // Change next of last node to recently created node
  last->next = new_node;
  return;
}

// Print the linked list
void printLinkedList(struct Node *node) {
  while (node != NULL) {
    printf(" %d ", node->data);
    node = node->next;
  }
}

int main() {

  struct Node *head = NULL;

  insertAtEnd(1, &head);
  insertAtEnd(4, &head);

  printf("Linked list: ");
  printLinkedList(head);
}