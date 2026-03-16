1. 
PUSH(S,4)   = 4
PUSH(S,1)   = 4, 1
PUSH(S,3)   = 4, 1, 3
POP(S)       = 4, 1
PUSH(S,8)   = 4, 1, 8
POP(S)       = 4, 1

2. 
ENQUEUE(Q,4) = 4
ENQUEUE(Q,1) = 4, 1
ENQUEUE(Q,3) = 4, 1, 3
DEQUEUE(Q)   = 1, 3
ENQUEUE(Q,8) = 1, 3, 8
DEQUEUE(Q)   = 3, 8

3. 
ENQUEUE:
The first line should check if Queue.length() is equal to the size of the queue, and if it is, it will return the original array without adding any elements, so it will not overflow

DEQUEUE:
The first line should check if Queue.head() and Queue.tail() is equal. If it is, then it will return an empty array so it will not underflow.

4. 
PUSH: inserts an element at the back of the deque.
first, check if DQ.top == to DQ.length(). if it is, return an overflow error.
second, make DQ.top = DQ.top + 1
last, make DQ[DQ.top] = x.

ENQUEUE: inserts an element at the front of the deque.
first, check if DQ.head == DQ.tail + 1 or DQ.head == 1 and DQ.tail == DQ.length. if it is, return an overflow error.
second, make DQ[DQ.tail] = x
third, check if DQ.tail == DQ.length, if it is, assign DQ.tail as 1.
else, return DQ.tail = DQ.tail + 1.


POP: removes the element at the back of the deque.
first, check if DQ.tail == 0, then return an underflow error.
second, make DQ.top = DQ.top - 1
last, return DQ[DQ.top+1]

DEQUEUE: removes an element at the front of the deque.
first, check if DQ.head == to DQ.tail and DQ.length == 0. if it is, return an underflow error.
second, make DQ.front = DQ.front + 1.
last, return DQ[DQ.front-1].



