#include <stdio.h>

#define N 3 // Number of equations

void displayMatrix(float matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void gaussJordanElimination(float matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        if (matrix[i][i] == 0.0) {
            printf("Mathematical Error!");
            return;
        }
        for (int j = 0; j < N; j++) {
            if (i != j) {
                float ratio = matrix[j][i] / matrix[i][i];
                for (int k = 0; k <= N; k++) {
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }

    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i + 1, matrix[i][N] / matrix[i][i]);
    }
}

int main() {
    float matrix[N][N + 1];

    printf("Enter the coefficients of the linear equations:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("Augmented matrix:\n");
    displayMatrix(matrix);

    gaussJordanElimination(matrix);

    return 0;
}
