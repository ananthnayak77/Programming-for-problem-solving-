#include <stdio.h>

int main() {
    int lower, upper, num, i, isPrime;

    // Input limits
    printf("Enter lower limit: ");
    scanf("%d", &lower);
    printf("Enter upper limit: ");
    scanf("%d", &upper);

    num = lower;

    // Loop through numbers between limits
    while (num <= upper) {
        isPrime = 1;  // Assume prime

        if (num < 2) {
            isPrime = 0;  // Numbers less than 2 are not prime
        } else {
            i = 2;
            while (i <= num / 2) {
                if (num % i == 0) {
                    isPrime = 0;  // Not prime
                    break;
                }
                i++;
            }
        }

        if (isPrime == 1) {
            printf("%d ", num);
        }

        num++;
    }

    return 0;
}
