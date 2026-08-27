// Program to check whether a number is strong or not
#include <stdio.h>

int main() {
    int num, originalNum, digit, sum = 0, fact, i;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    originalNum = num; // store original number

    while (num > 0) {
        digit = num % 10;   // extract last digit
        fact = 1;

        // calculate factorial of the digit
        for (i = 1; i <= digit; i++) {
            fact *= i;
        }

        sum += fact;        // add factorial to sum
        num /= 10;          // remove last digit
    }

    if (sum == originalNum)
        printf("%d is a Strong Number.\n", originalNum);
    else
        printf("%d is NOT a Strong Number.\n", originalNum);

    return 0;
}
