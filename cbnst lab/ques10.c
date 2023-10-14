// newton forward
#include <stdio.h>
#include <math.h>

int main() {
    float x, u1, u, y;
    int n, fact;

    // Input: Number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Initialize a 2D array to store X and Y values
    float a[n][n + 1];

    // Input: Values of X
    printf("Enter Values of X:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &a[i][0]);

    // Input: Values of Y
    printf("Enter Values of Y:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &a[i][1]);

    // Input: Value of x for which you want y
    printf("Enter the value of x for which you want y: ");
    scanf("%f", &x);

    // Calculate the Difference Table
    for (int j = 2; j <= n ; j++) {
        int k = 0;
        while (k < n - j + 1) {
            a[k][j] = a[k + 1][j - 1] - a[k][j - 1];
            k++;
        }
    }

    // Print the Difference Table
    printf("The Difference Table is as follows:\n");
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j <= n - i) {
            printf("%0.0f ", a[i][j]);
            j++;
        }
        printf("\n");
    }

    // Calculate u
    u = (x - a[0][0]) / (a[1][0] - a[0][0]);

    // Initialize y, u1, and fact
    y = a[0][1];
    u1 = u;
    fact = 1;

    // Perform interpolation
    for (int i = 2; i <= n; i++) {
        y = y + (u1 * a[0][i]) / fact;
        fact = fact * i;
        u1 = u1 * (u - (i - 1));
    }

    // Output: Interpolated value at X=x
    printf("\nValue at X=%g is = %f\n", x, y);

    return 0;
}
