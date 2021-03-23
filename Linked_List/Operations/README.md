# Linked List Operations: Traverse, Insert and Delete

Two important points to remember:

1. head points to the first node of the linked list
2. next pointer of the last node is NULL, so if the next current node is NULL, we have reached the end of the linked list.

## Traverse a Linked List
Displaying the contents of a linked list is very simple. We keep moving the temp node to the next one and display its contents.</br>
When temp is NULL, we know that we have reached the end of the linked list so we get out of the while loop.

## Insert Elements to a Linked List
You can add elements to either the beginning, middle or end of the linked list.

#### 1. Insert at the beginning
1. Allocate memory for new node
2. Store data
3. Change next of new node to point to head
4. Change head to point to recently created node

#### 2. Insert at the End
1. Allocate memory for new node
2. Store data
3. Traverse to last node
4. Change next of last node to recently created node

#### 3. Insert at the Middle
1. Allocate memory and store data for new node
2. Traverse to node just before the required position of new node
3. Change next pointers to include new node in between

## Delete Elements from a Linked List
You can delete either from the beginning, end or from a particular position.

#### 1. Delete from beginning
1. Point head to the second node

#### 2. Delete from end
1. Traverse to second last element
2. Change its next pointer to null

#### 3. Delete from middle
1. Traverse to element before the element to be deleted
2. Change next pointers to exclude the node from the chain
