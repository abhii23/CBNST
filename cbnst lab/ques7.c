#include <stdio.h>
#include <stdlib.h>

#define N 3

void printMatrix(float matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void gaussElimination(float matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int k = i + 1; k < N; k++) {
            if (matrix[k][i] > matrix[i][i]) {
                for (int j = 0; j <= N; j++) {
                    float temp = matrix[i][j];
                    matrix[i][j] = matrix[k][j];
                    matrix[k][j] = temp;
                }
            }
        }

        float pivot = matrix[i][i];
        for (int j = i; j <= N; j++) {
            matrix[i][j] /= pivot;
        }

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

    printf("Enter coefficients and constants of linear equations:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    gaussElimination(matrix);

    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i + 1, matrix[i][N]);
    }

    return 0;
}
