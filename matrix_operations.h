#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <unistd.h>
#include <time.h>

typedef struct {
    int rows;
    int cols;
    double** data;
    int id;
} Matrix;

typedef struct {
    pid_t pid;
    int pipe_in[2];    // For writing to process
    int pipe_out[2];   // For reading from process
    int busy;          // 0 = free, 1 = busy
    int age;           // How long the process has been running
    time_t last_used;  // Last time used
} Worker;

typedef struct {
    Worker* workers;
    int count;
    int capacity;
} ProcessPool;

// Basic matrix operations
void enter_matrix(Matrix matrices[], int* count);
void display_matrix(Matrix matrices[], int count);
void delete_matrix(Matrix matrices[], int* count);
void modify_matrix(Matrix matrices[], int count);
void display_all_matrices(Matrix matrices[], int count);

// File operations
void read_matrix_from_file(Matrix matrices[], int* count);
void read_matrices_from_folder(Matrix matrices[], int* count);
void save_matrix_to_file(Matrix matrices[], int count);
void save_all_matrices(Matrix matrices[], int count);

// Parallel operations
void add_matrices_parallel(Matrix matrices[], int count, ProcessPool* pool);
void subtract_matrices_parallel(Matrix matrices[], int count, ProcessPool* pool);
void multiply_matrices_parallel(Matrix matrices[], int count, ProcessPool* pool);
void determinant_parallel(Matrix matrices[], int count, ProcessPool* pool);
void eigenvalues_parallel(Matrix matrices[], int count, ProcessPool* pool);

// Process pool management
void init_process_pool(ProcessPool* pool, int size);
void cleanup_process_pool(ProcessPool* pool);
int create_worker(Worker* worker);
void worker_process(int read_fd, int write_fd);
Worker* get_free_worker(ProcessPool* pool);
void release_worker(Worker* worker);
void cleanup_worker(Worker* worker);

// External variable declarations
extern int matrix_count;

#endif
