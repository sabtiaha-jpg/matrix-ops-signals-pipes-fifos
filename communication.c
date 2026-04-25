#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include "matrix_operations.h"

#define FIFO_PATH "/tmp/matrix_fifo"


void add_matrices_parallel(Matrix matrices[], int count, ProcessPool* pool) {
    if (count < 2) {
        printf("Need at least 2 matrices!\n");
        return;
    }
    
    int idx1, idx2;
    printf("Enter indices of matrices to add (0-%d): ", count-1);
    scanf("%d %d", &idx1, &idx2);
    
    if (idx1 < 0 || idx1 >= count || idx2 < 0 || idx2 >= count) {
        printf("Invalid indices!\n");
        return;
    }
    
    Matrix* m1 = &matrices[idx1];
    Matrix* m2 = &matrices[idx2];
    
    if (m1->rows != m2->rows || m1->cols != m2->cols) {
        printf("Matrices dimensions don't match!\n");
        return;
    }
    int total_elements = m1->rows * m1->cols;
    
    for (int i = 0; i < total_elements; i++) {
        if (pool->count < pool->capacity) {
            pid_t worker = create_worker_process();
            pool->workers[pool->count++] = worker;
        }
    }
    printf("Matrix addition completed!\n");
}
