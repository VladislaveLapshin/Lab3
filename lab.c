// lab3.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fillArray(double Array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("Enter the element %d: ", i + 1);
        scanf("%lf", &Array[i]);
    }
}

void printArray(double Array[], int size) {
    printf("The contents of the array:\n");
    for (int i = 0; i < size; ++i) {
        printf("%lf ", Array[i]);
    }
    printf("\n");
}

void insertElement(double **Array, int *size, int index, double element) {
    if (index < 0 || index > *size) {
        printf("Error: Invalid index for inserting an element.\n");
        return;
    }

    (*size)++;
    *Array = realloc(*Array, (*size) * sizeof(double));

    if (*Array == NULL && *size > 0) {
        printf("Error: Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = *size - 1; i > index; --i) {
        (*Array)[i] = (*Array)[i - 1];
    }

    (*Array)[index] = element;
}

void deleteElement(double **Array, int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Error: Invalid index for deleting an element.\n");
        return;
    }

    for (int i = index; i < *size - 1; ++i) {
        (*Array)[i] = (*Array)[i + 1];
    }

    (*size)--;
    *Array = realloc(*Array, (*size) * sizeof(double));

    if (*Array == NULL && size > 0) {
        printf("Error: Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
}
void filterNumbers(double **Array, int *size) {
    int i = 0;
    while (i < *size) {
        double originalNumber = (*Array)[i];
        int intPart = (int)originalNumber;
        double fractionalPart = originalNumber - intPart;
        int decimalRepresentation = 0;

        // ��������� ������� ����� � ����� �����
        while (fractionalPart != 0.0 && fractionalPart != 1.0) {
            fractionalPart *= 10;
            int decimalDigit = (int)fractionalPart;
            fractionalPart -= decimalDigit;
            decimalRepresentation = decimalRepresentation * 10 + decimalDigit;
           
        }
           
        // ��������� ������� � ������� ������� ��� �������������
        if (decimalRepresentation > intPart) {
            deleteElement(Array, size, i);
        } else {
            i++;
        }
    }
}
