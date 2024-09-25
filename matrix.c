#include <stdio.h>

#define MAX 10

void multiplyMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int rowFirst, int columnFirst, int rowSecond, int columnSecond) {
    int i, j, k;

    // Initializing elements of matrix result to 0.
    for(i = 0; i < rowFirst; ++i) {
        for(j = 0; j < columnSecond; ++j) {
            result[i][j] = 0;
        }
    }

    // Multiplying firstMatrix and secondMatrix and storing in result.
    for(i = 0; i < rowFirst; ++i) {
        for(j = 0; j < columnSecond; ++j) {
            for(k = 0; k < columnFirst; ++k) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int row, int column) {
    int i, j;
    for(i = 0; i < row; ++i) {
        for(j = 0; j < column; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int first[MAX][MAX], second[MAX][MAX], result[MAX][MAX];
    int rowFirst, columnFirst, rowSecond, columnSecond;
    int i, j;

    // Input dimensions of first matrix
    printf("Enter number of rows for first matrix: ");
    scanf("%d", &rowFirst);
    printf("Enter number of columns for first matrix: ");
    scanf("%d", &columnFirst);

    // Input elements of first matrix
    printf("Enter elements of matrix 1 with position:\n");
    for(i = 0; i < rowFirst; ++i) {
        for(j = 0; j < columnFirst; ++j) {
            printf("a%d%d: ", i + 1, j + 1);
            scanf("%d", &first[i][j]);
        }
    }

    // Input dimensions of second matrix
    printf("Enter number of rows for Second matrix: ");
    scanf("%d", &rowSecond);
    printf("Enter number of columns for Second matrix: ");
    scanf("%d", &columnSecond);
    
    // Input elements of second matrix
    printf("Enter elements of matrix 2 with position:\n");
    for(i = 0; i < rowSecond; ++i) {
        for(j = 0; j < columnSecond; ++j) {
            printf("b%d%d: ", i + 1, j + 1);
            scanf("%d", &second[i][j]);
        }
    }

    // Check if multiplication is possible
    if(columnFirst != rowSecond) {
        printf("Error! Column of first matrix must be equal to row of second matrix.\n");
        return 1;
    }

    // Multiply matrices
    multiplyMatrices(first, second, result, rowFirst, columnFirst, rowSecond, columnSecond);

    // Display result
    printf("Output Matrix: \n");
    printMatrix(result, rowFirst, columnSecond);

    return 0;
}