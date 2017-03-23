/*
Name:Vafaee, Ashkan
UT EID : av28837
Section : 16320
EE312 - Assignment 5

*/
#include "assignment-5_queue.h"
#include <stdlib.h>
#include <stdio.h>


/* Queue implementations */

queue* queue_init() {

	queue *str = (queue*)malloc(sizeof(queue));
	str->size = 0;
	str->tail = NULL;	
	str->head = NULL;

	return(str);
	
}

int queue_size(queue* q) {
	return(q->size);

}

void enqueue(queue* q, long val) {
	q_node *temp;

	q->size = q->size + 1;

	temp = malloc(sizeof(q_node));
	temp->data = val;

	
	temp->next = NULL;

	if (q->tail == NULL) {					//only occurs first time
		q->head = temp;
		q->tail = temp;
	}
	else {							//skips first time
		q->tail->next = temp;				//asssigns pointer to next node to previous node
		q->tail = temp;
	}
}

long dequeue(queue* q) {
	q_node *temp;

	if (q->size > 0) {
		q->size = q->size - 1;

		long value;
		
		temp = q->head;

		value = temp->data;
		q->head = temp->next;

		free(temp);

		return(value);


	}
	
}

void insert(queue* q, long val, int index) {
	q_node *temp;

	temp = q->head;
	int i = 0;

	if (q->size > index && index>=0) {				//index must be between 0 and size-1 inclusive 
		i = index;

		while (i > 0) {
			temp = temp->next;
			i--;
		}

		temp->data = val;


		return(1);
	}

	else {
		return(0);
	}
	
}

int queue_index_of(queue* q, long val) {
	q_node *temp;

	temp = q->head;
	int i = 0;

	while (temp != NULL) {

		if (temp->data == val) {
			return(i);
		}

		temp = temp->next;
		i++;


	}

	return(-1);								//Not found

}

void queue_print(queue* q) {
	q_node *temp;

	temp = q->head;

	while (temp->next != NULL) {
		printf("%ld, ", temp->data);
		temp = temp->next;
	}
	printf("%ld", temp->data);

	printf("\n");
	
}
