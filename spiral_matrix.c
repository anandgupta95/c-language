#include <stdio.h>
#include<stdlib.h>

void spiralOrder(int** A, int rows, int cols, int* result) {
    int size = rows * cols;
    int cnt = 0;
    int rmin = 0, cmin = 0;
    int rmax = rows - 1, cmax = cols - 1;

    while (cnt < size) {
        // right
        if (cnt < size) {
            for (int i = cmin; i <= cmax; i++) {
                result[cnt++] = A[rmin][i];
            }
        }
        rmin++;

        // down
        if (cnt < size) {
            for (int i = rmin; i <= rmax; i++) {
                result[cnt++] = A[i][cmax];
            }
        }
        cmax--;

        // left
        if (cnt < size) {
            for (int i = cmax; i >= cmin; i--) {
                result[cnt++] = A[rmax][i];
            }
        }
        rmax--;

        // up
        if (cnt < size) {
            for (int i = rmax; i >= rmin; i--) {
                result[cnt++] = A[i][cmin];
            }
        }
        cmin++;
    }
}

int main() {
    // Example usage
    int rows = 3;
    int cols = 4;
    int** A = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        A[i] = (int*)malloc(cols * sizeof(int));
    }

    // Initialize A with values (example values)
    int val = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A[i][j] = val++;
        }
    }

    // Allocate space for the result
    int* result = (int*)malloc(rows * cols * sizeof(int));

    // Call the function
    spiralOrder(A, rows, cols, result);

    // Print the result
    for (int i = 0; i < rows * cols; i++) {
        printf("%d ", result[i]);
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(A[i]);
    }
    free(A);
    free(result);

    return 0;
}
