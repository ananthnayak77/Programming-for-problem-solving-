#include <stdio.h>

int main() {
    int n, m, i, j, total;
    float percent;
    int marks[50][10];

    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter number of subjects: ");
    scanf("%d", &m);

    for(i = 0; i < n; i++) {
        total = 0;
        printf("Enter marks for student %d:\n", i+1);
        for(j = 0; j < m; j++) {
            scanf("%d", &marks[i][j]);
            total += marks[i][j];
        }
        percent = (float)total / m;

        printf("Student %d: Percentage = %.2f\n", i+1, percent);

        if(percent >= 85) printf("Grade: A (Pass)\n");
        else if(percent >= 70) printf("Grade: B (Pass)\n");
        else if(percent >= 50) printf("Grade: C (Pass)\n");
        else printf("Grade: D (Fail)\n");
    }

    return 0;
}
