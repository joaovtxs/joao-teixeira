// hmi.h

#ifndef HMI_H
#define HMI_H

#include "op.h" 

void display_menu(OperationType* ops, int num_ops);
int get_menu_choice(void);
double get_double(const char* prompt);
int get_dimension(void);
void get_array(double* array, int n);

#endif
