#include <stdio.h>
int main() {
    int a, b, result;
    printf("Enter values of a and b: ");
    scanf("%d %d", &a, &b);

    result = (a * a) + (2 * a * b) + (b * b);
    printf("Result = %d\n", result);
    return 0;
}
