#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "matrix_operations.h"
#include "process_pool.h"
#include "file_operations.h"

#define MAX_MATRICES 100
#define CONFIG_FILE "config/config.txt"

Matrix matrices[MAX_MATRICES];
int matrix_count = 0;
ProcessPool pool;

void load_config(const char* filename) {
    
    printf("Loading configuration from %s\n", filename);
}

void display_menu() {
    printf("\n=== Matrix Operations Menu ===\n");
    printf("1. Enter a matrix\n");
    printf("2. Display a matrix\n");
    printf("3. Delete a matrix\n");
    printf("4. Modify a matrix\n");
    printf("5. Read a matrix from a file\n");
    printf("6. Read matrices from a folder\n");
    printf("7. Save a matrix to a file\n");
    printf("8. Save all matrices to a folder\n");
    printf("9. Display all matrices\n");
    printf("10. Add 2 matrices\n");
    printf("11. Subtract 2 matrices\n");
    printf("12. Multiply 2 matrices\n");
    printf("13. Find determinant of a matrix\n");
    printf("14. Find eigenvalues & eigenvectors\n");
    printf("15. Exit\n");
    printf("Choose an operation: ");
}

void handle_signal(int sig) {
    printf("\nReceived signal %d. Cleaning up...\n", sig);
    cleanup_process_pool(&pool);
    exit(0);
}

int main(int argc, char* argv[]) {
    char* config_file = CONFIG_FILE;
    
    if (argc > 1) {
        config_file = argv[1];
    }
    
    load_config(config_file);
    init_process_pool(&pool);
    signal(SIGINT, handle_signal);
    
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                enter_matrix(matrices, &matrix_count);
                break;
            case 2:
                display_matrix(matrices, matrix_count);
                break;
            case 3:
                delete_matrix(matrices, &matrix_count);
                break;
            case 4:
                modify_matrix(matrices, matrix_count);
                break;
            case 5:
                read_matrix_from_file(matrices, &matrix_count);
                break;
            case 6:
                read_matrices_from_folder(matrices, &matrix_count);
                break;
            case 7:
                save_matrix_to_file(matrices, matrix_count);
                break;
            case 8:
                save_all_matrices(matrices, matrix_count);
                break;
            case 9:
                display_all_matrices(matrices, matrix_count);
                break;
            case 10:
                add_matrices_parallel(matrices, matrix_count, &pool);
                break;
            case 11:
                subtract_matrices_parallel(matrices, matrix_count, &pool);
                break;
            case 12:
                multiply_matrices_parallel(matrices, matrix_count, &pool);
                break;
            case 13:
                determinant_parallel(matrices, matrix_count, &pool);
                break;
            case 14:
                eigenvalues_parallel(matrices, matrix_count, &pool);
                break;
            case 15:
                cleanup_process_pool(&pool);
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
