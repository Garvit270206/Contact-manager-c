#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a contact node
struct Contact {
    char name[50];
    char phone[15];
    struct Contact* next;
};

// Head pointer for the linked list
struct Contact* head = NULL;

// Function to add a new contact
void addContact() {
    struct Contact* newNode = (struct Contact*)malloc(sizeof(struct Contact));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]s", newNode->name);
    printf("Enter Phone Number: ");
    scanf(" %[^\n]s", newNode->phone);
    newNode->next = NULL;

    // If list is empty, make new node the head
    if (head == NULL) {
        head = newNode;
    } else {
        struct Contact* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Contact added successfully!\n\n");
}

// Function to display all contacts
void displayContacts() {
    if (head == NULL) {
        printf("The contact list is empty.\n\n");
        return;
    }

    struct Contact* temp = head;
    printf("\n--- Contact List ---\n");
    int count = 1;
    while (temp != NULL) {
        printf("%d. Name: %s | Phone: %s\n", count++, temp->name, temp->phone);
        temp = temp->next;
    }
    printf("--------------------\n\n");
}

// Function to search for a contact by name
void searchContact() {
    if (head == NULL) {
        printf("The contact list is empty.\n\n");
        return;
    }

    char target[50];
    printf("Enter name to search: ");
    scanf(" %[^\n]s", target);

    struct Contact* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strcasecmp(temp->name, target) == 0) {
            printf("Found! Name: %s | Phone: %s\n\n", temp->name, temp->phone);
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("Contact not found.\n\n");
    }
}

// Function to delete a contact by name
void deleteContact() {
    if (head == NULL) {
        printf("The contact list is empty.\n\n");
        return;
    }

    char target[50];
    printf("Enter name to delete: ");
    scanf(" %[^\n]s", target);

    struct Contact *temp = head, *prev = NULL;

    // If head node itself holds the contact to be deleted
    if (temp != NULL && strcasecmp(temp->name, target) == 0) {
        head = temp->next;
        free(temp);
        printf("Contact deleted successfully!\n\n");
        return;
    }

    // Search for the contact to be deleted
    while (temp != NULL && strcasecmp(temp->name, target) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If contact was not present
    if (temp == NULL) {
        printf("Contact not found.\n\n");
        return;
    }

    // Unlink the node from linked list and free memory
    prev->next = temp->next;
    free(temp);
    printf("Contact deleted successfully!\n\n");
}

// Main function with menu-driven interface
int main() {
    int choice;
    do {
        printf("=== Simple Contact Manager ===\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    } while (choice != 5);

    return 0;
}
