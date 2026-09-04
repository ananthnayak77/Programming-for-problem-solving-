#include <stdio.h>

int main() {
    int N, i, j, temp;
    float avg, sum = 0;
    int marks[100];

    printf("Enter number of students: ");
    scanf("%d", &N);

    printf("Enter marks of %d students:\n", N);
    for(i = 0; i < N; i++) {
        scanf("%d", &marks[i]);
        sum += marks[i];
    }

    avg = sum / N;

    // Sort marks for ranking (descending)
    for(i = 0; i < N-1; i++) {
        for(j = i+1; j < N; j++) {
            if(marks[i] < marks[j]) {
                temp = marks[i];
                marks[i] = marks[j];
                marks[j] = temp;
            }
        }
    }

    printf("Total = %.2f, Average = %.2f\n", sum, avg);
    printf("Ranks based on marks:\n");
    for(i = 0; i < N; i++) {
        printf("Rank %d: %d\n", i+1, marks[i]);
    }

    return 0;
}
