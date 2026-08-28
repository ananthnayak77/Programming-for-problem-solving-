#include <stdio.h>
#include <stdbool.h>

void execute_option_one(void) {
    printf("Executing Option 1...\n");
}

int main(void) {
    int choice = 0;
    bool running = true;

    while (running) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Option One\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Clearing buffer.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                execute_option_one();
                break;
            case 2:
                printf("Exiting program.\n");
                running = false;
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
