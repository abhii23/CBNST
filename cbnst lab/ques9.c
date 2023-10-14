// gauss seidel

#include <stdio.h>
#include <math.h>

#define N 3 // Number of equations and variables

int main() {
    int i, j, maxIter;
    double a[N][N + 1], x[N], xNew[N], epsilon;

    printf("Enter the number of iterations: ");
    scanf("%d", &maxIter);

    printf("Enter the error tolerance (epsilon): ");
    scanf("%lf", &epsilon);

    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j <= N; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    // Initialize the solution vector
    for (i = 0; i < N; i++) {
        x[i] = 0.0;
    }

    // Gauss-Seidel Iteration
    int iter;
    for (iter = 0; iter < maxIter; iter++) {
        for (i = 0; i < N; i++) {
            double sum = 0.0;
            for (j = 0; j < N; j++) {
                if (j != i) {
                    sum += a[i][j] * x[j];
                }
            }
            xNew[i] = (a[i][N] - sum) / a[i][i];
        }

        // Check for convergence
        int converged = 1;
        for (i = 0; i < N; i++) {
            if (fabs(xNew[i] - x[i]) > epsilon) {
                converged = 0;
                break;
            }
        }

        // Update the solution vector
        for (i = 0; i < N; i++) {
            x[i] = xNew[i];
        }

        // If convergence is achieved, break
        if (converged) {
            break;
        }
    }

    printf("\nSolution after %d iterations:\n", iter + 1);
    for (i = 0; i < N; i++) {
        printf("x%d = %.6lf\n", i + 1, x[i]);
    }

    return 0;
}
