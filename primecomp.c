#include <stdio.h>

int main() {
    int num, i, isPrime;
    int primeCount = 0, compositeCount = 0;

    printf("Enter numbers (enter -1 to stop):\n");

    do {
        scanf("%d", &num);

        if (num == -1) {
            break;  // Stop when -1 is encountered
        }

        if (num == 1) {
            // 1 is neither prime nor composite
            continue;
        }

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
            primeCount++;
        } else if (num > 1) {
            compositeCount++;
        }

    } while (num != -1);

    printf("\nTotal prime numbers entered: %d\n", primeCount);
    printf("Total composite numbers entered: %d\n", compositeCount);

    return 0;
}
