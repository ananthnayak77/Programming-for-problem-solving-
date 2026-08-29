#include <stdio.h>
int main() {
    int seconds, hours, minutes;
    printf("Enter time in seconds: ");
    scanf("%d", &seconds);

    hours = seconds / 3600;
    minutes = (seconds % 3600) / 60;
    seconds = (seconds % 3600) % 60;

    printf("%d Hours, %d Minutes, %d Seconds\n", hours, minutes, seconds);
    return 0;
}
