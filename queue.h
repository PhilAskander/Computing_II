//
//  queue.h
//  Project 2
//
//  Created by Philopater Askander on 4/5/22.
//

#ifndef queue_h
#define queue_h
#include "status.h"
#include <stdio.h>

typedef void* QUEUE;
//init default
QUEUE queue_init_default(void);

//destroy
void queue_destroy(QUEUE* phQ);

//enqueue
Status queue_enqueue(QUEUE hQ, int value);

//service
Status queue_service(QUEUE hQ);

//front
int front_of_queue(QUEUE hQ, Status* pStatus);

//is_empty
Boolean queue_is_empty(QUEUE hQ);
#endif /* queue_h */
