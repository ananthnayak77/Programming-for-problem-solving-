#include <stdio.h>

int main() {
    int i = 1;

    // Demonstration with while loop
    printf("While loop demonstration:\n");
    while (i <= 10) {
        if (i == 5) {
            i++;
            continue;   // skip printing 5
        }
        if (i == 8) {
            break;      // stop loop when i = 8
        }
        printf("%d\n", i);
        i++;
    }

    // Demonstration with do-while loop
    printf("\nDo-While loop demonstration:\n");
    i = 1;
    do {
        if (i == 3) {
            i++;
            continue;   // skip printing 3
        }
        if (i == 6) {
            break;      // stop loop when i = 6
        }
        printf("%d\n", i);
        i++;
    } while (i <= 10);

    return 0;
}
