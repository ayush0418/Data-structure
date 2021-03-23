# Linked List Data Structure
A linked list is defined as the collection of the nodes in which one node is connected to another node, and node consists of two parts, i.e., one is the data part and the second one is the address part of the next node. 

The declaration of an array is very simple as it is of single type. 
But the linked list contains two parts, which are of two different types, i.e., one is a simple variable, and the second one is a pointer variable. 
We can declare the linked list by using the user-defined data type known as structure.

## Advantages of using a Linked list over Array
The following are the advantages of using a linked list over an array:

**1. Dynamic data structure:** The size of the linked list is not fixed as it can vary according to our requirements.  </br>
**2. Insertion and Deletion:** If we want to insert or delete the element in an array, then we need to shift the elements for creating the space. On the other hand, in the linked list, we do not have to shift the elements. In the linked list, we just need to update the address of the pointer in the node.</br>
**3. Memory efficient:** Its memory consumption is efficient as the size of the linked list can grow or shrink according to our requirements.</br>
**4. Implementation:** Both the stacks and queues can be implemented using a linked list.


## Disadvantages of Linked list
The following are the disadvantages of linked list:

**1. Memory usage:** The node in a linked list occupies more memory than array as each node occupies two types of variables, i.e., one is a simple variable, and another is a pointer variable that occupies 4 bytes in the memory.</br>
**2. Traversal:** In a linked list, the traversal is not easy. If we want to access the element in a linked list, we cannot access the element randomly, but in the case of an array, we can randomly access the element by index. For example, if we want to access the 3rd node, then we need to traverse all the nodes before it. So, the time required to access a particular node is large.</br>
**3. Reverse traversing:** In a linked list, backtracking or reverse traversing is difficult. In a doubly linked list, it is easier but requires more memory to store the back pointer.</br>

## Linked List Complexity
**Time Complexity**</br>
 ```        
         Worst case  Average Case 
Search	    O(n)        O(n)    
Insert	    O(1)        O(1)
Deletion    O(1)        O(1) 
```
