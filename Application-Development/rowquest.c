#include <stdio.h>

int main() {
    int STUDENTS[100], N, i, roll, found = 0;

    // Input size
    printf("Enter number of students: ");
    scanf("%d", &N);

    // Input roll numbers
    printf("Enter roll numbers:\n");
    for(i = 0; i < N; i++) {
        scanf("%d", &STUDENTS[i]);
    }

    // Display roll numbers
    printf("Roll numbers are:\n");
    for(i = 0; i < N; i++) {
        printf("%d ", STUDENTS[i]);
    }
    printf("\n");

    // Input roll number to search
    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    // Search
    for(i = 0; i < N; i++) {
        if(STUDENTS[i] == roll) {
            printf("Roll number %d found at position %d.\n", roll, i+1);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Roll number %d not found.\n", roll);
    }

    return 0;
}
