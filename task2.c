#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void insert_end(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;

    new_node->data = data;
    new_node->next = NULL;

    // If the linked list is empty, make the new node the head
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Traverse to the last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Link the last node to the new node
    last->next = new_node;
}

// Function to insert a new node at the beginning of the linked list
void insert_begin(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head; // Link the new node to the current head
    *head = new_node; // Update the head to the new node
}

// Function to delete a node by value from the linked list
void delete_node(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the list is empty
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == data) {
        *head = temp->next;  // Move the head pointer to the next node
        free(temp);  // Free the memory of the old head node
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the node was not found
    if (temp == NULL) {
        printf("Node with data %d not found.\n", data);
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);  // Free the memory of the deleted node
}

// Function to traverse the linked list and print its elements
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the linked list implementation
int main() {
    struct Node* head = NULL;  // Initially the linked list is empty

    // Insert elements into the linked list
    insert_end(&head, 10);
    insert_end(&head, 20);
    insert_end(&head, 30);
    insert_begin(&head, 5);

    printf("Singly Linked List after insertions:\n");
    traverse(head);

    // Delete an element from the linked list
    delete_node(&head, 20);
    printf("\nSingly Linked List after deleting 20:\n");
    traverse(head);

    // Try deleting a non-existent element
    delete_node(&head, 100);

    // Delete another element
    delete_node(&head, 5);
    printf("\nSingly Linked List after deleting 5:\n");
    traverse(head);

    return 0;
}