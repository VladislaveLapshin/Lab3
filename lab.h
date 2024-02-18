// lab3.h
#ifndef LAB3_H
#define LAB3_H

#include <math.h>
#include <stdlib.h>

void fillArray(double Array[], int size);
void printArray(double Array[], int size);
void insertElement(double **Array, int *size, int index, double element);
void deleteElement(double **Array, int *size, int index);
void filterNumbers(double **Array, int *size);


#endif
