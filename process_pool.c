#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>
#include "process_pool.h"

#define MAX_WORKERS 100
#define WORKER_AGE_LIMIT 300 

void init_process_pool(ProcessPool* pool) {
    pool->workers = malloc(MAX_WORKERS * sizeof(pid_t));
    pool->count = 0;
    pool->capacity = MAX_WORKERS;
}

void cleanup_worker(ProcessPool* pool, int index) {
    kill(pool->workers[index], SIGTERM);
    waitpid(pool->workers[index], NULL, 0);
    
    for (int i = index; i < pool->count - 1; i++) {
        pool->workers[i] = pool->workers[i + 1];
    }
    pool->count--;
}

void cleanup_process_pool(ProcessPool* pool) {
    for (int i = 0; i < pool->count; i++) {
        kill(pool->workers[i], SIGTERM);
        waitpid(pool->workers[i], NULL, 0);
    }
    free(pool->workers);
    pool->count = 0;
}

pid_t create_worker_process() {
    pid_t pid = fork();
    if (pid == 0) {
        worker_process();
        exit(0);
    }
    return pid;
}

void worker_process() {
    
    while (1) {
        sleep(1); 
    }

