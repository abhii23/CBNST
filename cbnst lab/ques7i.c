/*1 1 1 6
2 5 2 17
4 2 3 16*/
#include <stdio.h>

#define N 3

// Function to print the matrix
void printMatrix(float matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to print the diagonal matrix
void printDiagonalMatrix(float matrix[N][N + 1]) {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N+ 1; j++)
        {
            printf("%0.1f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to solve a system of linear equations using Gaussian Elimination
void solveLinearEquations(float matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        // Make the diagonal element 1 (divide row by the diagonal element)
        float diagonalElement = matrix[i][i];
        for (int j = i; j <= N; j++) {
            matrix[i][j] /= diagonalElement;
        }

        // Make other elements in the column zero
        for (int k = 0; k < N; k++) {
            if (k != i) {
                float factor = matrix[k][i];
                for (int j = i; j <= N; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }
}

int main() {
    float matrix[N][N + 1];

    // Input coefficients and constants of linear equations
    printf("Enter coefficients and constants of linear equations:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Solve the linear equations using Gaussian Elimination
    solveLinearEquations(matrix);

    // Print the diagonal matrix
    printDiagonalMatrix(matrix);

    // Print the solutions
    printf("\nSolution:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i + 1, matrix[i][N]);
    }

    return 0;
}
