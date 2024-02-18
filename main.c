// main.c
#include <stdio.h>
#include "lab.h"

int main() {
    char choice;
    double *Array;
    int size;
    int newSize;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    Array = (double *)calloc(size, sizeof(double));

    do {
        printf("menu:\n");
        printf("(a) Initialization of the array.\n");
        printf("(b) Inserting a new element.\n");
        printf("(c) Deleting an element.\n");
        printf("(d) Individual task.\n");
        printf("(e) Output of the array contents.\n");
        printf("(q) Exiting the program.\n");
        printf("Select an operation: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                fillArray(Array, size);
                break;
            case 'b':
                {
                    int index;
                    double newElement;
                    printf("Enter the index to insert the new element: ");
                    scanf("%d", &index);
                    printf("Enter a new element: ");
                    scanf("%lf", &newElement);
                    insertElement(&Array, &size, index, newElement);
                    break;
                }
            case 'c':
                {
                    int indexToDelete;
                    printf("Enter the index to delete the item: ");
                    scanf("%d", &indexToDelete);
                    deleteElement(&Array, &size, indexToDelete);
                    break;
                }
            case 'd':
    filterNumbers(&Array, &size);
    printf("After filtering:\n");
    printArray(Array, size);
    break;            
            case 'e':
                printArray(Array, size);
                break;

            case 'q':
                break;
            default:
                printf("Error: incorrect selection\n");
        }
    } while (choice != 'q');

    free(Array);

    return 0;
}
