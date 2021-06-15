# Simple Queue Data Structure
Queue follows the First In First Out (FIFO) rule - the item that goes in first is the item that comes out first.

## Working of Queue

1. Two pointers FRONT and REAR
2. FRONT track the first element of the queue
3. REAR track the last element of the queue
4. Initially, set value of FRONT and REAR to -1

## Enqueue Operation
1. Check if the queue is full
2. For the first element, set the value of FRONT to 0
3. Increase the REAR index by 1
4. Add the new element in the position pointed to by REAR

## Dequeue Operation
1. Check if the queue is empty
2. Return the value pointed by FRONT
3. Increase the FRONT index by 1
4. For the last element, reset the values of FRONT and REAR to -1

## Complexity Analysis
The complexity of enqueue and dequeue operations in a queue using an array is **O(1)**
