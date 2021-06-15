# Queue Data Structure
* A queue is a useful data structure in programming. It is similar to the ticket queue outside a cinema hall, where the first person entering the queue is the first person who gets the ticket.
* Queue follows the First In First Out **(FIFO)** rule - the item that goes in first is the item that comes out first.


### FIFO Principle Of Queue
* In programming terms, putting items in the queue is called **Enqueue**, and removing items from the queue is called **Dequeue**.
* In the given image, since 1 was kept in the queue before 2, it is the first to be removed from the queue as well. It follows the FIFO rule.
<p  align="center"><img src="https://cdn.programiz.com/sites/tutorial2program/files/queue.png" alt="Coder GIF" width="700" height="150">
  
## Basic Operations of Queue
There are some basic operations that allow us to perform different actions on a Queue.

* **Enqueue**: Add an element to the end of the queue
* **Dequeue**: Remove an element from the front of the queue
* **IsEmpty**: Check if the queue is empty
* **IsFull**: Check if the queue is full
* **Peek**: Get the value of the front of the queue without removing it.
  
  
## Limitations of Queue
As you can see in the image below, after a bit of enqueuing and dequeuing, the size of the queue has been reduced.
  <p  align="center"><img src="https://cdn.programiz.com/sites/tutorial2program/files/why-circular-queue_0.png" alt="Coder GIF" width="500" height="200">
  

* The empty spaces at front cannot be used after dequeing from a full queue
* And we can only add indexes 0 and 1 only when the queue is reset (when all the elements have been dequeued).
    
## Applications of Queue Data Structure
* CPU scheduling, Disk Scheduling
* When data is transferred asynchronously between two processes.The queue is used for synchronization. For example: IO Buffers, pipes, file IO, etc
Handling of interrupts in real-time systems.
* Call Center phone systems use Queues to hold people calling them in order.



