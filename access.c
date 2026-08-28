#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int user_input = 0;

    printf("Enter an integer: ");
    if (scanf("%d", &user_input) != 1) {
        fprintf(stderr, "Error: Invalid input.\n");
        return EXIT_FAILURE;
    }

    // Your logic here
    printf("You entered: %d\n", user_input);

    return EXIT_SUCCESS;
}
