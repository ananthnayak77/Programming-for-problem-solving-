#include <stdio.h>
#include <string.h>

int main() {
    char username[30], password[30];
    char sys_username[] = "admin";
    char sys_password[] = "12345";
    printf("just a test for login page so use uid=admin/pwd=12345\n");

    printf("=====================================\n");
    printf("         LOGIN PAGE INTERFACE        \n");
    printf("=====================================\n");

    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    if(strcmp(username, sys_username) == 0 && strcmp(password, sys_password) == 0) {
        printf("\n-------------------------------------\n");
        printf("   ✅ Login Successful! Welcome %s   \n", username);
        printf("-------------------------------------\n");
    } else {
        printf("\n-------------------------------------\n");
        printf("   ❌ Login Failed! Try Again.        \n");
        printf("-------------------------------------\n");
    }

    return 0;
}
