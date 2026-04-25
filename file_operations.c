#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "matrix_operations.h"

void read_matrix_from_file(Matrix matrices[], int* count) {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    
    Matrix* matrix = &matrices[*count];
    fscanf(file, "%d %d", &matrix->rows, &matrix->cols);
    
    matrix->data = malloc(matrix->rows * sizeof(double*));
    for (int i = 0; i < matrix->rows; i++) {
        matrix->data[i] = malloc(matrix->cols * sizeof(double));
        for (int j = 0; j < matrix->cols; j++) {
            fscanf(file, "%lf", &matrix->data[i][j]);
        }
    }
    
    matrix->id = *count;
    (*count)++;
    fclose(file);
    printf("Matrix loaded successfully!\n");
}

void save_matrix_to_file(Matrix matrices[], int count) {
    if (count == 0) {
        printf("No matrices to save!\n");
        return;
    }
    
    int index;
    printf("Enter matrix index (0-%d): ", count-1);
    scanf("%d", &index);
    
    if (index < 0 || index >= count) {
        printf("Invalid index!\n");
        return;
    }
    
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error creating file!\n");
        return;
    }
    
    Matrix* matrix = &matrices[index];
    fprintf(file, "%d %d\n", matrix->rows, matrix->cols);
    
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            fprintf(file, "%.2f ", matrix->data[i][j]);
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
    printf("Matrix saved successfully!\n");
}
