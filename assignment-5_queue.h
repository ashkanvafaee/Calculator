/*
Name:Vafaee, Ashkan
UT EID : av28837
Section : 16320
EE312 - Assignment 5

*/

// Node for Queue
typedef struct q_node {
  long data;
  struct q_node* next;
} q_node;

typedef struct queue {
       int size;
       q_node* head;
       q_node* tail;
} queue;


/**
* Allocates memory for an empty queue object using malloc, initializes it,
* and returns a pointer to the created object.
*/ 
queue* queue_init();

/**
* Returns the size of the queue
*/
int queue_size(queue* q);

/**
* Adds a new entry to the queue. The new node should be dynamically created first
* using malloc.
*/ 
void enqueue(queue* q, long val);

/**
* Removes the first added node from the queue, and returns its value
*/ 
long dequeue(queue* q);

/**
* Inserts an entry at the specified index. The new node should be dynamically
* created using malloc.
*/
void insert(queue* q, long val, int index);

/**
* Returns the position where data was found in the queue (integer within [0 ... size - 1]),
* or -1 if not found.
*/
int queue_index_of(queue* s, long val);

/**
* Prints the queue as a comma-separated list (check PDF for format)
*/
void queue_print(queue* q);
