#include <stdio.h>

typedef enum { 
    ROWS = 3, 
    COLS = 4 
}Matrix;

void fillMatrix(int mat[ROWS][COLS]) {
    printf("Matrix Dimensions: %d Rows x %d Columns\n", ROWS, COLS);
    
    int counter = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            mat[i][j] = counter++; // Fills with sequential numbers
        }
    }
    printf("Matrix filled successfully.\n");
}

int main() {
    // Declare the matrix using enum constants
    int matrix[ROWS][COLS];

    fillMatrix(matrix);

    // Optional: Print the results to verify
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
