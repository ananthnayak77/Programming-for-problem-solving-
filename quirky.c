#include <stdio.h>
void countdown(int n) {
    if(n==0) { printf("Blast off!\n"); return; }
    printf("%d...\n", n);
    countdown(n-1);
}
int main() {
    countdown(5);
    return 0;
}
