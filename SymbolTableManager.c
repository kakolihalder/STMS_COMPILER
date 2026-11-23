
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50

typedef struct Symbol {
    char name[50];
    char type[20];
    char scope[20];
    int size;
    int line;
    struct Symbol *next;
} Symbol;

Symbol *table[SIZE];

// Hash function
unsigned int hash(char *name) {
    unsigned int h = 0;

    while (*name)
        h = (h * 31 + *name++) % SIZE;

    return h;
}

// Check valid identifier
int validName(char *name) {
    if (!isalpha(name[0]) && name[0] != '_')
        return 0;

    for (int i = 1; name[i]; i++)
        if (!isalnum(name[i]) && name[i] != '_')
            return 0;

    return 1;
}

// Search symbol
Symbol *search(char *name) {
    int index = hash(name);
    Symbol *temp = table[index];

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

// Insert symbol
void insert() {
    char name[50], type[20], scope[20];
    int size, line;

    printf("Enter identifier name: ");
    scanf("%49s", name);

    if (!validName(name)) {
        printf("Invalid identifier name!\n");
        return;
    }

    if (search(name)) {
        printf("Error: Duplicate identifier!\n");
        return;
    }

    printf("Enter data type: ");
    scanf("%19s", type);

    printf("Enter scope (global/local): ");
    scanf("%19s", scope);

    printf("Enter size in bytes: ");
    scanf("%d", &size);

    printf("Enter declaration line: ");
    scanf("%d", &line);

    if (size <= 0 || line <= 0) {
        printf("Size and line must be positive!\n");
        return;
    }

    Symbol *newNode = malloc(sizeof(Symbol));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(newNode->name, name);
    strcpy(newNode->type, type);
    strcpy(newNode->scope, scope);
    newNode->size = size;
    newNode->line = line;

    int index = hash(name);

    newNode->next = table[index];
    table[index] = newNode;

    printf("Symbol inserted successfully!\n");
}

// Display symbol table
void display() {
    printf("\n========== SYMBOL TABLE ==========\n");

    printf("%-15s %-12s %-12s %-8s %-8s\n",
           "Name", "Type", "Scope", "Size", "Line");

    int found = 0;

    for (int i = 0; i < SIZE; i++) {
        Symbol *temp = table[i];

        while (temp != NULL) {
            printf("%-15s %-12s %-12s %-8d %-8d\n",
                   temp->name, temp->type,
                   temp->scope, temp->size,
                   temp->line);

            temp = temp->next;
            found = 1;
        }
    }

    if (!found)
        printf("Symbol table is empty!\n");

    printf("=================================\n");
}

// Search symbol
void searchSymbol() {
    char name[50];

    printf("Enter identifier to search: ");
    scanf("%49s", name);

    Symbol *s = search(name);

    if (s) {
        printf("\nSymbol Found!\n");
        printf("Name  : %s\n", s->name);
        printf("Type  : %s\n", s->type);
        printf("Scope : %s\n", s->scope);
        printf("Size  : %d bytes\n", s->size);
        printf("Line  : %d\n", s->line);
    } else {
        printf("Symbol not found!\n");
    }
}

// Update symbol
void updateSymbol() {
    char name[50];

    printf("Enter identifier to update: ");
    scanf("%49s", name);

    Symbol *s = search(name);

    if (!s) {
        printf("Symbol not found!\n");
        return;
    }

    printf("Enter new data type: ");
    scanf("%19s", s->type);

    printf("Enter new scope: ");
    scanf("%19s", s->scope);

    printf("Enter new size: ");
    scanf("%d", &s->size);

    printf("Enter new declaration line: ");
    scanf("%d", &s->line);

    if (s->size <= 0 || s->line <= 0) {
        printf("Invalid size or line!\n");
        return;
    }

    printf("Symbol updated successfully!\n");
}

// Delete symbol
void deleteSymbol() {
    char name[50];

    printf("Enter identifier to delete: ");
    scanf("%49s", name);

    int index = hash(name);

    Symbol *temp = table[index];
    Symbol *prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL)
                table[index] = temp->next;
            else
                prev->next = temp->next;

            free(temp);

            printf("Symbol deleted successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Symbol not found!\n");
}

// Free allocated memory
void cleanup() {
    for (int i = 0; i < SIZE; i++) {
        Symbol *temp = table[i];

        while (temp != NULL) {
            Symbol *next = temp->next;
            free(temp);
            temp = next;
        }
    }
}

// Main menu
int main() {
    int choice;

    do {
        printf("\n===== SYMBOL TABLE MANAGEMENT =====\n");
        printf("1. Insert Symbol\n");
        printf("2. Search Symbol\n");
        printf("3. Update Symbol\n");
        printf("4. Delete Symbol\n");
        printf("5. Display Symbol Table\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                searchSymbol();
                break;

            case 3:
                updateSymbol();
                break;

            case 4:
                deleteSymbol();
                break;

            case 5:
                display();
                break;

            case 6:
                cleanup();
                printf("Program terminated!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
