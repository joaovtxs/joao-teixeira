// main.c

#include <stdio.h>
#include <stdlib.h>
#include "hmi.h"
#include "op.h"

int main() {
    OperationType menu[] = {
        {"Add", add},
        {"Subtract", sub},
        {"Multiply", mult},
        {"Divide", divide},
        {"Power", pot},
        {"Determinant", det_hmi}
    };
    
    int num_ops = sizeof(menu) / sizeof(menu[0]);
    int choice = 0;

    while (1) {
        display_menu(menu, num_ops);
        choice = get_menu_choice();
        
        if (choice == num_ops + 1) {
            printf("Exiting...\n");
            printf("by Joao Teixeira\n");
            break;
        } else if (choice >= 1 && choice <= num_ops) {
            // Execute the pointer function
            menu[choice - 1].execute();
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}