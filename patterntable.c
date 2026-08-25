#include <stdio.h>

int main() {
    int n, k;
    printf("Enter the number of rows (n): ");
    scanf("%d", &n);
    printf("Enter the number of terms (k): ");
    scanf("%d", &k);

    // Outer loop for rows (1 to n)
    for (int i = 1; i <= n; i++) {
        // Inner loop for columns (1 to k)
        for (int j = 1; j <= k; j++) {
            printf("%d\t", i * j);  // Print product
        }
        printf("\n");  // New line after each row
    }

    return 0;
}
