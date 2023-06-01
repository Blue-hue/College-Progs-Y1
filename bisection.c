#include <stdio.h>
#include <math.h>

float f(float x) {
    return (x * log10(x)) - 2.2;
}

float derf(float x) {
    return (log10(x) + 1);
}

void newton(float x, float error) {
    int iter = 1;
    float temp;
    do {
        temp = x;
        x = temp - f(temp)/derf(temp);
        printf("Iteration : %d\t | x : %f\n", iter, x);
        iter++;
    } while (fabs(x-temp) >= error);
    printf("Approximate root (Newton-Raphson Method): %f\n", x);
}

void bisection(float x1, float x2, float error) {
    float x, f1, f2, fmid;
    int iter = 1;
    do {
        x = (x1 + x2) / 2;
        f1 = f(x1);
        f2 = f(x2);
        fmid = f(x);
        if (f1 * fmid < 0)
            x2 = x;
        else
            x1 = x;
        printf("Iteration : %d\t | x1 = %f\t | x2 = %f\n", iter, x1, x2);
        iter++;
    } while (fabs(x1 - x2) >= error);
    printf("Approximate root (Bisection Method): %f\n", x);
}

int main() {
    int choice;
    float x1, x2, x, error;

    printf("Enter desired method:\n1. Bisection Method\n2. Newton-Raphson Method\nChoose : ");
    scanf("%d", &choice);
    printf("Enter tolerable error: ");
    scanf("%f", &error);

    if (choice == 1) {
        printf("Enter initial guesses: ");
        scanf("%f %f", &x1, &x2);
        bisection(x1, x2, error);
    } else if (choice == 2) {
        printf("Enter initial guess: ");
        scanf("%f", &x);
        newton(x, error);
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
    }
    return 0;
}