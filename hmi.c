// hmi.c

#include <stdio.h>
#include <stdlib.h>
#include "hmi.h"
#include "op.h"

// Create the user menu
void display_menu(OperationType* ops, int num_ops) {
    printf("\n========== CALCULATOR ==========\n");
    for (int i = 0; i < num_ops; i++) {
        printf("%d. %s\n", i + 1, ops[i].name);
    }
    printf("%d. Exit\n", num_ops + 1);
    printf("\nWhat is your choice: ");
}

// Get the user input while showing the menu
int get_menu_choice(void) {
    char buffer[50];
    int choice;
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &choice) == 1) {
                return choice;
            }
        }
        printf("Invalid Entry! Try again: ");
    }
}

// Get the numbers during the execution of the code
double get_double(const char* prompt) {
    char buffer[50];
    double value;
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%lf", &value) == 1) { 
                return value;
            }
        }
        printf("Error, insert a valid number.\n");
    }
}

// Get the dimension of a matrix
int get_dimension(void) {
    char buffer[50];
    int dim;
    while (1) {
        printf("Insert dimension size (n x n): ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &dim) == 1 && dim > 0) {
                return dim;
            }
        }
        printf("Error! Dimension must be greater than zero!\n");
    }
}

// Get the array of the matrix
void get_array(double* array, int n) {
    int size = n * n; // Calculate the row and column positions to display during the determinant data entry
    printf("\nInsert %d array values:\n", size);
    for (int i = 0; i < size; i++) {
        char prompt[40];
        int row = (i / n) + 1;
        int col = (i % n) + 1;
        sprintf(prompt, "Value [%d][%d]: ",row, col);
        array[i] = get_double(prompt); 
    }
}