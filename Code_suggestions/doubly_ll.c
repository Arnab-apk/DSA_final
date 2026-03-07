#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node for Doubly Linked List
struct Node {
    int data;
    struct Node* next;
    struct Node* prev; // New pointer for the previous node
};

// 2. Global head pointer
struct Node* head = NULL;

// --- Insert at Beginning ---
void insertAtBeginning(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL; // The first node's previous is always NULL

    // If list is empty
    if (head == NULL) {
        newNode->next = NULL;
        head = newNode;
        printf("Inserted %d at beginning.\n", val);
        return;
    }

    // If list is not empty, connect the old head to the new node
    newNode->next = head;
    head->prev = newNode;
    head = newNode; // Update head
    printf("Inserted %d at beginning.\n", val);
}

// --- Insert at End ---
void insertAtEnd(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL; // The last node's next is always NULL

    // If list is empty, it becomes the first node
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        printf("Inserted %d at end.\n", val);
        return;
    }

    // Travel to the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Connect the old last node and the new node
    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at end.\n", val);
}

// --- Delete from Beginning ---
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;

    // If there is only one node
    if (head->next == NULL) {
        printf("Deleted %d from beginning.\n", temp->data);
        free(head);
        head = NULL;
        return;
    }

    // Move head forward and sever the connection to the old head
    head = head->next;
    head->prev = NULL;
    
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

// --- Delete from End ---
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    // If there is only one node
    if (head->next == NULL) {
        printf("Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    // Travel to the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // The node before 'temp' will become the new last node
    temp->prev->next = NULL;
    
    printf("Deleted %d from end.\n", temp->data);
    free(temp);
}

// --- Display List ---
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Doubly Linked List (Forward): NULL <- ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" <-> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

// --- Menu Driven Main Function ---
int main() {
    int choice, val;

    while (1) {
        printf("\n1. Insert Beginning  2. Insert End  3. Delete Beginning  4. Delete End  5. Display  6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: "); scanf("%d", &val);
                insertAtBeginning(val); break;
            case 2:
                printf("Enter value: "); scanf("%d", &val);
                insertAtEnd(val); break;
            case 3: deleteFromBeginning(); break;
            case 4: deleteFromEnd(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}