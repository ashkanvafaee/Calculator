/*
Name:Vafaee, Ashkan
UT EID : av28837
Section : 16320
EE312 - Assignment 5

*/
#include "assignment-5_stack.h"
#include <stdlib.h>
#include <stdio.h>



stack* stack_init() {

	stack *stk = (stack*)malloc(sizeof(stack));

	if (stk == NULL) {			//****Error****
		return(stk);
	}

	stk->size = 0;				// initialize stack size to 0;

	stk->top = NULL;			// points to NULL (end);

	return(stk);


}

int stack_size(stack* s) {

	return(s->size);
	
}

void push(stack* s, double val) {
	s_node *temp;
	s->size = s->size + 1;				//adding an element to the stack



	temp = malloc(sizeof(s_node));

	temp->val = val;				//setting the value of the newly created node
	temp->next = s->top;				//s->top has NULL for the first node

	s->top = temp;					//top of stack is element that was most recently pushed

	
}

double pop(stack* s) {
	s_node *temp;
	double value;
	s_node *tempNext;


	if (s->size > 0) {					// shouldn't pop if empty;

		s->size = s->size - 1;				//removing an element from the stack

		temp = s->top;					// temp points to top of stack
		value = temp->val;

		s->top = temp->next;				// top of stack now points to next element down

		free(temp);					//Frees memory 


		return(value);



	}
}

double peek(stack* s) {

	return(s->top->val);
	
}

int stack_index_of(stack* s, double val) {
	s_node *temp;

	int index = 0;
	temp = s->top;									//temp points to top element of stack (index 0);

	while (temp != NULL) {
		if (temp->val == val) {
			return(index);
		}
		temp = temp->next;							//temp points to next element down
		index++;

	}
	
	return(-1);									//if no elements found
}

void stack_print(stack* s) {
	s_node *temp;

	temp = s->top;									//temp points to top element 

	while (temp->next != NULL) {
		printf("%lf, ", temp->val);
		temp = temp->next;
	}
	
	printf("%lf", temp->val);
	
	printf("\n");
	
}
