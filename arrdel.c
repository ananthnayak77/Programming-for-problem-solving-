#include <stdio.h>

int main() {
    int arr[10], n, i, pos = -1, num;

    // Input size
    printf("Enter size of array: ");
    scanf("%d", &n);

    // Input elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input number to delete
    printf("Enter number to delete: ");
    scanf("%d", &num);

    // Search for number
    for(i = 0; i < n; i++) {
        if(arr[i] == num) {
            pos = i;
            break;
        }
    }

    // If found, delete
    if(pos != -1) {
        for(i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--; // reduce size

        printf("Array after deletion:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("Number not found in array.\n");
    }

    return 0;
}
