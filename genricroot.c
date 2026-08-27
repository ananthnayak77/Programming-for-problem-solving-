#include <stdio.h>

int main() {
    int n, sum;
    printf("Enter a number: ");
    scanf("%d", &n);

    while (n > 9) {
        sum = 0;
        while (n > 0) {
            sum += n % 10;  // add last digit
            n /= 10;        // remove last digit
        }
        n = sum;  // replace number with sum of digits
    }

    printf("Generic root = %d\n", n);
    return 0;
}
