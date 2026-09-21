// op.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "op.h"
#include "hmi.h"

// function add
void add() {
    printf("\n--- Addition ---\n");
    double k1 = get_double("Insert first value: ");
    double k2 = get_double("Insert second value: ");
    printf("Result: %.4lf\n", k1 + k2);
}

// function subtract
void sub() {
    printf("\n--- Subtraction ---\n");
    double k1 = get_double("Insert first value: ");
    double k2 = get_double("Insert second value: ");
    printf("Result: %.4lf\n", k1 - k2);
}

//function multply
void mult() {
    printf("\n--- Multiplication ---\n");
    double k1 = get_double("Insert first value: ");
    double k2 = get_double("Insert second value: ");
    printf("Result: %.4lf\n", k1 * k2);
}

// function divide
void divide() {
    printf("\n--- Division ---\n");
    double k1 = get_double("Insert first value: ");
    double k2 = get_double("Insert second value: ");
    if (k2 == 0) {
        printf("Error! Division by zero.\n");
    } else {
        printf("Result: %.4lf\n", k1 / k2);
    }
}

// function power, where the user choice the base and de expoent
void pot() {
    printf("\n--- Power ---\n");
    double k1 = get_double("Insert base: ");
    double k2 = get_double("Insert exponent: ");
    printf("Result: %.4lf\n", pow(k1, k2));
}

// math function Determinant
double det_calc(const double *matrix, int n) {
    double *mat = (double *)malloc(n * n * sizeof(double));
    if (mat == NULL) return 0.0;
    
    for (int i = 0; i < n * n; i++) mat[i] = matrix[i];
    double det = 1.0;
    
    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(mat[j * n + i]) > fabs(mat[pivot * n + i])) pivot = j;
        }
        if (pivot != i) {
            for (int j = 0; j < n; j++) {
                double temp = mat[i * n + j];
                mat[i * n + j] = mat[pivot * n + j];
                mat[pivot * n + j] = temp;
            }
            det *= -1.0; 
        }
        if (mat[i * n + i] == 0.0) {
            free(mat);
            return 0.0;
        }
        det *= mat[i * n + i];
        for (int j = i + 1; j < n; j++) {
            double fator = mat[j * n + i] / mat[i * n + i];
            for (int k = i; k < n; k++) mat[j * n + k] -= fator * mat[i * n + k];
        }
    }
    free(mat);
    return det;
}
// function Determinant
void det_hmi() {
    printf("\n--- Determinant ---\n");
    int n = get_dimension();
    int size = n * n;
    
    double *matrix = (double *)malloc(size * sizeof(double));
    if (matrix == NULL) {
        printf("Error allocating memory!\n");
        return;
    }
    
    get_array(matrix, n);
    double result = det_calc(matrix, n);
    
    printf("Result: %.4lf\n", result);
    free(matrix);
}