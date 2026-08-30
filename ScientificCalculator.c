#include <stdio.h>
#include <math.h>   // Required for scientific functions

int main() {
    int choice;
    double num1, num2, result;

    printf("=== Scientific Calculator ===\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power (x^y)\n");
    printf("6. Square Root\n");
    printf("7. Sine (in radians)\n");
    printf("8. Cosine (in radians)\n");
    printf("9. Tangent (in radians)\n");
    printf("10. Logarithm (base e)\n");
    printf("11. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("Result = %.2lf\n", result);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("Result = %.2lf\n", result);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("Result = %.2lf\n", result);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 != 0)
                    result = num1 / num2;
                else {
                    printf("Error: Division by zero!\n");
                    break;
                }
                printf("Result = %.2lf\n", result);
                break;

            case 5:
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &num1, &num2);
                result = pow(num1, num2);
                printf("Result = %.2lf\n", result);
                break;

            case 6:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if (num1 >= 0)
                    result = sqrt(num1);
                else {
                    printf("Error: Negative input!\n");
                    break;
                }
                printf("Result = %.2lf\n", result);
                break;

            case 7:
                printf("Enter angle in radians: ");
                scanf("%lf", &num1);
                result = sin(num1);
                printf("Result = %.2lf\n", result);
                break;

            case 8:
                printf("Enter angle in radians: ");
                scanf("%lf", &num1);
                result = cos(num1);
                printf("Result = %.2lf\n", result);
                break;

            case 9:
                printf("Enter angle in radians: ");
                scanf("%lf", &num1);
                result = tan(num1);
                printf("Result = %.2lf\n", result);
                break;

            case 10:
                printf("Enter a positive number: ");
                scanf("%lf", &num1);
                if (num1 > 0)
                    result = log(num1);
                else {
                    printf("Error: Non-positive input!\n");
                    break;
                }
                printf("Result = %.2lf\n", result);
                break;

            case 11:
                printf("Exiting calculator...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
