//
//  queue.c
//  Project 2
//
//  Created by Philopater Askander on 4/5/22.
//
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int capcity;
    int index_of_front;
    int* data;
};

typedef struct queue Queue;


QUEUE queue_init_default(void){
    Queue* pQ = (Queue*)malloc(sizeof(Queue));
        if (pQ != NULL){
            pQ->size = 0;
            pQ->index_of_front = 0;
            pQ->capcity = 10;
            pQ->data = (int*)malloc(sizeof(int)*pQ->capcity);
            if (pQ->data == NULL){
                free(pQ);
                return NULL;
        }
    }
    return pQ;
}

Status queue_enqueue(QUEUE hQ, int value){
    Queue* pQ = (Queue*)hQ;
    int* temp;
    int i;
    if (pQ->size >= pQ->capcity){ /*Is there's not enough room, then make room*/
        temp = (int*)malloc(sizeof(int)*pQ->capcity * 2);
        if (temp == NULL){
            return FAILURE;
        }
        for (i=0; i<pQ->size; i++){
            temp[i] = pQ->data[(pQ->index_of_front + i)% pQ->capcity];
        }
        free(pQ->data);
        pQ->data = temp;
        pQ->index_of_front = 0;
        pQ->capcity*=2;

    }
    pQ->data[(pQ->index_of_front+pQ->size) % pQ->capcity] = value;
    pQ->size++;
    return SUCCESS;
}

Boolean queue_is_empty(QUEUE hQ){
    Queue* pQ = (Queue*) hQ; /*we cast the known type so we can see what the structure really is*/
    return (Boolean)(pQ->size<=0);
}

int front_of_queue(QUEUE hQ, Status* pStatus){
    Queue* pQ = (Queue*) hQ;
    if (queue_is_empty(hQ)){
        if (pStatus != NULL){
            *pStatus = FAILURE;
        }
        return -1337;
    }
    if (pStatus != NULL){
        *pStatus = SUCCESS;
    }
    return pQ->data[pQ->index_of_front];
}

Status queue_service(QUEUE hQ){
    Queue* pQ = (Queue*) hQ;

    if (queue_is_empty(hQ)){
        return FAILURE;
    }
    pQ->index_of_front = (pQ->index_of_front+1)%pQ->capcity;
    pQ->size--;
    return SUCCESS;
}


void queue_destroy(QUEUE* phQ){
    Queue* pQ = (Queue*) *phQ;
    free(pQ->data);
    free(pQ);
    *phQ = NULL;
}


