#include <stdio.h>
#include <math.h>

int main() {
    int n, k;
    double x, term, sum = 0.0;

    printf("Enter value of x (in radians): ");
    scanf("%lf", &x);
    printf("Enter number of terms n: ");
    scanf("%d", &n);

    for (k = 0; k < n; k++) {
        term = pow(-1, k) * pow(x, 2*k+1) / tgamma(2*k+2); 
        // tgamma(m) = (m-1)! in math.h
        sum += term;
    }

    printf("sin(%lf) ≈ %lf (using %d terms)\n", x, sum, n);
    return 0;
}
