#include <stdio.h>

int main() {
    int i;
    for (i = 1; i <= 10; i++) {
        if (i == 5) {
            continue;  // skip printing 5
        }
        if (i == 8) {
            break;     // stop loop when i = 8
        }
        printf("%d\n", i);
    }
    return 0;
}
