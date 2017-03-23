
/*
Name:Vafaee, Ashkan
UT EID : av28837
Section : 16320
EE312 - Assignment 5

*/

/* Use the following stucts for your stack and node. Feel free to add any additional members. */
typedef struct s_node {
  double val;
  struct s_node* next;
} s_node;

typedef struct stack {
  int size;
  s_node* top;
} stack;


/*These functions should be implemented in assignment-5_stack.c */

/**
* Allocates memory for an empty stack object using malloc, initializes it,
* and returns a pointer to the created object.
*/ 
stack* stack_init();

/**
* Returns the size of the stack
*/
int stack_size(stack* s);

/**
* Adds a new node to the stack. The new node should be dynamically created first
* using malloc.
*/ 
void push(stack* s, double val);

/**
* Removes the last added node from the stack, and returns its value
*/ 
double pop(stack* s);

/**
* Returns the value of the element at the top of the stack.
*/
double peek(stack* s);

/**
* Returns the position where data was found in the stack (integer within [0 ... size - 1]), 
* or -1 if not found.
*/
int stack_index_of(stack* s, double val);

/**
* Prints the stack as a comma-separated list (check PDF for format)
*/
void stack_print(stack* s);
