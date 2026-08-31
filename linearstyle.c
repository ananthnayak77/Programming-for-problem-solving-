#include <stdio.h>
int main() {
    int n; 
    printf("Enter a number: "); 
    scanf("%d",&n); 
    printf("%s\n", (n%2) ? "Odd vibes!" : "Even vibes!");
    return 0;
}
