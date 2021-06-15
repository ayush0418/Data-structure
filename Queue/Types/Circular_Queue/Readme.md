# Circular Queue Data Structure
A circular queue is the extended version of a regular queue where the last element is connected to the first element. Thus forming a circle-like structure.

<p  align="center"><img src="https://cdn.programiz.com/sites/tutorial2program/files/circular-increment.png" alt="Coder GIF" width="300" height="300">

* The circular queue solves the major limitation of the normal queue. In a normal queue, after a bit of insertion and deletion, there will be non-usable empty space.
  
## How Circular Queue Works
Circular Queue works by the process of circular increment i.e. when we try to increment the pointer and we reach the end of the queue, we start from the beginning of the queue.

Here, the circular increment is performed by modulo division with the queue size. That is,
  * if REAR + 1 == 5 (overflow!), REAR = (REAR + 1)%5 = 0 (start of queue)
  
## Circular Queue Operations
The circular queue work as follows:

* Two pointers FRONT and REAR
* FRONT track the first element of the queue
* REAR track the last elements of the queue
* Initially, set value of FRONT and REAR to -1
  
### Enqueue Operation (Insertion)
* Check if the queue is full
* For the first element, set value of FRONT to 0
* Circularly increase the REAR index by 1 (i.e. if the rear reaches the end, next it would be at the start of the queue)
* Add the new element in the position pointed to by REAR
  
### Dequeue Operation(Deletion)
* Check if the queue is empty
* Return the value pointed by FRONT
* Circularly increase the FRONT index by 1
* For the last element, reset the values of FRONT and REAR to -1
  
### isFull(check for full queue)  
* Case 1: FRONT = 0 && REAR == SIZE - 1
* Case 2: FRONT = REAR + 1

The second case happens when REAR starts from 0 due to circular increment and when its value is just 1 less than FRONT, the queue is full.
  
### isEmpty(check for Empty queue)
* If FRONT == REAR
