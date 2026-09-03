#include <stdio.h>

int main() {
    int MARKS[100], N, i, j, temp;

    // Input size
    printf("Enter number of students: ");
    scanf("%d", &N);

    // Input marks
    printf("Enter marks of %d students:\n", N);
    for(i = 0; i < N; i++) {
        scanf("%d", &MARKS[i]);
    }

    // Sort in descending order (Bubble Sort)
    for(i = 0; i < N-1; i++) {
        for(j = 0; j < N-i-1; j++) {
            if(MARKS[j] < MARKS[j+1]) {
                temp = MARKS[j];
                MARKS[j] = MARKS[j+1];
                MARKS[j+1] = temp;
            }
        }
    }

    // Display sorted marks
    printf("Marks in descending order:\n");
    for(i = 0; i < N; i++) {
        printf("%d ", MARKS[i]);
    }

    return 0;
}
