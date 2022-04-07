
/**********************************************************************
 Program: Program 2
 Author: Philopater Askander
 Date: March 28th 2022
 Time spent: Too long
 Purpose: The purpose of this project is to apply what we learned about queues in class and apply it to a task
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int test_cases(void);
int ferry_length(void);
int car_count(void);
int test_case_verification(void);
void ferry_work(QUEUE hQ, int ferryLength);

int main(int argc, char* argv[]){
    int test_case = test_cases();
    int i;
    for (i = 0; i < test_case; i++){
        printf("%d\n", test_case_verification());
    }
    
    return 0;
}

int test_cases(void){
    int test_case;
    int user_input;
    user_input = scanf("%d", &test_case);
    return test_case;
}

int ferry_length(void){
    int user_input;
    int ferry;
    int meters;
    
    user_input = scanf("%d", &meters);
    ferry = meters * 100;/*conversion from centimeters to meters*/
    return ferry;
}

int car_count(void){

    int num_cars;
    int user_input;
    user_input = scanf("%d", &num_cars);
    return num_cars;
}

int test_case_verification(void){
    int user_input;
    int i;
    int ferryLength = ferry_length();
    int num_cars = car_count();
    int trip_count = 0;
    
    QUEUE right = queue_init_default();
    QUEUE left = queue_init_default();
    
    for (i = 0;i<num_cars; i++){
        char side[6];
        int carLength;
        user_input = scanf("%d %s", &carLength, side);
        
        if (side[0] == 'r'|| side[0] == 'R'){
            queue_enqueue(right, carLength);
        }
        else{
            queue_enqueue(left, carLength);
        }
    }
    
    
    while (queue_is_empty(left) == FALSE || queue_is_empty(right) == FALSE){
        ferry_work(left, ferryLength);
        trip_count++;
        if (queue_is_empty(left) == TRUE && queue_is_empty(right) == TRUE){
            break;
        }
        ferry_work(right, ferryLength);
        trip_count++;
    }
    
    return trip_count;
}

void ferry_work(QUEUE hQ, int length_of_ferry){
    int total_length = 0;
    int front_queue;
    while (queue_is_empty(hQ) == FALSE){
        front_queue = front_of_queue(hQ, NULL);
        
        if (front_queue+total_length <= length_of_ferry){
            queue_service(hQ);
        }
        else{
            break;
        }
        
        total_length += front_queue;
    }
    
}
