#include "uni.h"

void print_int_element(void* element) {
    int* int_ptr = (int*)element;
    printf("%d \n", *int_ptr);
}

void print_double_element(void* element) {
    double* double_ptr = (double*)element;
    printf("%f \n", *double_ptr);
}

void print_worker_element(void* element) {
    worker_t* worker = (worker_t *)element;

    printf(BLUE"-- Show Worker --\n"CLEAR);
    printf("Revision: %lld\n",                      worker->revision);
    printf("Worker ID: %s\n",                       worker->worker_id);
    printf("Worker Name: %s\n",                     worker->worker_name);
    printf("Worker Alias: %s\n",                    worker->worker_alias);
    printf("Worker Status: %s\n",                   worker->worker_status);
    printf("Worker Type: %s\n",                     worker->worker_type);
    printf("Worker Lifecycle Start Time: %ld\n",    worker->worker_lifecycle_starttime);
    printf("Worker Lifecycle End Time: %ld\n",      worker->worker_lifecycle_endtime);
}

