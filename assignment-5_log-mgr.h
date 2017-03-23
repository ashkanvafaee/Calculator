/*
Name:Vafaee, Ashkan
UT EID : av28837
Section : 16320
EE312 - Assignment 5

*/

#include "assignment-5_queue.h"

typedef struct log_manager {
    int window_duration;
    struct queue *q;
} log_manager;


/*Implement these functions in assignment-5_logMgr.c */
int add_to_log(log_manager*, long);
log_manager* create_log_mgr(int);

