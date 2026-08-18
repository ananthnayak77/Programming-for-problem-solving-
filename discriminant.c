#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, D, realPart, imagPart, x1, x2;

    printf("Enter coefficients a, b, and c: ");
    scanf("%f %f %f", &a, &b, &c);

    D = b*b - 4*a*c;

    switch (D > 0 ? 1 : (D == 0 ? 0 : -1)) {
        case 1:
            x1 = (-b + sqrt(D)) / (2*a);
            x2 = (-b - sqrt(D)) / (2*a);
            printf("Two distinct real roots: %.2f and %.2f\n", x1, x2);
            break;

        case 0:
            x1 = -b / (2*a);
            printf("Equal real roots: %.2f\n", x1);
            break;

        case -1:
            realPart = -b / (2*a);
            imagPart = sqrt(-D) / (2*a);
            printf("Complex roots: %.2f + %.2fi and %.2f - %.2fi\n",
                   realPart, imagPart, realPart, imagPart);
            break;
    }

    return 0;
}
 