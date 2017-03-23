/*
Name:Vafaee, Ashkan
UT EID : av28837
Section : 16320
EE312 - Assignment 5

*/
#include "assignment-5_log-mgr.h"
#include <stdlib.h>

/* Your log manager implementations here */
int add_to_log(log_manager* mgr, long timestamp) {
	queue *temp;

	enqueue(mgr->q, timestamp);

	temp = mgr->q->head;


	while (timestamp - (mgr->q->head->data) > mgr->window_duration) {
		dequeue(mgr->q);

	}

	return(mgr->q->size);
}

log_manager* create_log_mgr(int delta) {
	log_manager * str = (log_manager*)malloc(sizeof(log_manager));
	if (str == NULL) {
		return(str);					//****Error****
	}
	str->window_duration = delta;
	str->q = queue_init();
	return(str);
	
}
