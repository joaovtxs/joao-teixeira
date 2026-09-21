// op.h

#ifndef OP_H
#define OP_H

typedef void (*OperationCallback)(void);

typedef struct {
    char name[50];
    OperationCallback execute;
} OperationType;

void add(void);
void sub(void);
void mult(void);
void divide(void);
void pot(void);
double det_calc(const double *matrix, int n);
void det_hmi(void);

#endif