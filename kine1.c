#include <stdio.h>
int main() {
    float u, a, t, result;
    printf("Enter values of u, a, t: ");
    scanf("%f %f %f", &u, &a, &t);

    result = (u * t) + (0.5 * a * t * t);
    printf("Result = %.2f\n", result);
    return 0;
}
