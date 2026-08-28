#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    void (*print_details)(int, const char*);
} Entity;

void display_entity(int id, const char* name) {
    printf("Entity ID: %d | Name: %s\n", id, name);
}

int main(void) {
    Entity item;
    item.id = 101;
    strncpy(item.name, "Default Target", sizeof(item.name) - 1);
    item.print_details = display_entity;

    // Trigger behavior via struct
    item.print_details(item.id, item.name);

    return 0;
}
