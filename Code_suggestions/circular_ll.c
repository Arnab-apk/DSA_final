#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node
struct Node {
    int data;
    struct Node* next;
};

// 2. Global head pointer
struct Node* head = NULL;

// --- Insert at Beginning ---
void insertAtBeginning(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    // If list is empty, the new node points to itself
    if (head == NULL) {
        head = newNode;
        newNode->next = head; 
        printf("Inserted %d at beginning.\n", val);
        return;
    }

    // Otherwise, we need to find the last node to update its 'next' pointer
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head; // New node points to current head
    temp->next = newNode; // Last node points to the new node
    head = newNode;       // Update head to be the new node
    printf("Inserted %d at beginning.\n", val);
}

// --- Insert at End ---
void insertAtEnd(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    // If list is empty, it works just like inserting at the beginning
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        printf("Inserted %d at end.\n", val);
        return;
    }

    // Travel to the last node
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode; // Old last node points to new node
    newNode->next = head; // New node points back to the head
    printf("Inserted %d at end.\n", val);
}

// --- Delete from Beginning ---
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    // If there is only one node in the list
    if (head->next == head) {
        printf("Deleted %d from beginning.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    // Find the last node
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    struct Node* nodeToDelete = head;
    
    temp->next = head->next; // Last node skips the current head
    head = head->next;       // Move head to the second node
    
    printf("Deleted %d from beginning.\n", nodeToDelete->data);
    free(nodeToDelete);
}

// --- Delete from End ---
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    // If there is only one node
    if (head->next == head) {
        printf("Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    // Travel to the second-to-last node
    struct Node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }

    struct Node* nodeToDelete = temp->next;
    
    temp->next = head; // Make second-to-last node point to head
    
    printf("Deleted %d from end.\n", nodeToDelete->data);
    free(nodeToDelete);
}

// --- Display List ---
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Circular List: ");
    
    // We use a do-while loop because we want to print the head node first, 
    // and then stop when we loop back around to the head.
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("(back to head)\n");
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