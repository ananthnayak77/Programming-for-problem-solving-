#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(0));
    for(int i=0;i<5;i++) {
        printf("Random crazy number: %d\n", rand()%100);
    }
    return 0;
}
