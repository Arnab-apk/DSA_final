#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;  // Pointer to previous node
    struct Node* next;  // Pointer to next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL) {
        return newNode;
    }
    
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    
    printf("Inserted %d at the beginning\n", data);
    return head;
}

// Function to insert at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL) {
        printf("Inserted %d at the end\n", data);
        return newNode;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
    
    printf("Inserted %d at the end\n", data);
    return head;
}

// Function to insert at a specific position
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return head;
    }
    
    if (position == 1) {
        return insertAtBeginning(head, data);
    }
    
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return head;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    
    temp->next = newNode;
    
    printf("Inserted %d at position %d\n", data, position);
    return head;
}

// Function to delete from the beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return NULL;
    }
    
    struct Node* temp = head;
    head = head->next;
    
    if (head != NULL) {
        head->prev = NULL;
    }
    
    printf("Deleted %d from the beginning\n", temp->data);
    free(temp);
    return head;
}

// Function to delete from the end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return NULL;
    }
    
    struct Node* temp = head;
    
    // If only one node
    if (temp->next == NULL) {
        printf("Deleted %d from the end\n", temp->data);
        free(temp);
        return NULL;
    }
    
    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->prev->next = NULL;
    printf("Deleted %d from the end\n", temp->data);
    free(temp);
    
    return head;
}

// Function to delete from a specific position
struct Node* deleteFromPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return NULL;
    }
    
    if (position < 1) {
        printf("Invalid position!\n");
        return head;
    }
    
    if (position == 1) {
        return deleteFromBeginning(head);
    }
    
    struct Node* temp = head;
    
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of range!\n");
        return head;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    printf("Deleted %d from position %d\n", temp->data, position);
    free(temp);
    
    return head;
}

// Function to display list forward
void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    printf("List (Forward): NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to display list backward
void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    
    // Go to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("List (Backward): NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Function to search for a value
void search(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    int position = 1;
    
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    
    printf("Element %d not found in the list\n", key);
}

// Function to reverse the doubly linked list
struct Node* reverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    struct Node* temp = NULL;
    struct Node* current = head;
    
    // Swap next and prev pointers for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    // Update head pointer
    if (temp != NULL) {
        head = temp->prev;
    }
    
    printf("List reversed successfully\n");
    return head;
}

// Function to count nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    return count;
}

// Function to free the entire list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function with menu
int main() {
    struct Node* head = NULL;
    int choice, data, position;
    
    while (1) {
        printf("\n----- Doubly Linked List Operations -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Search Element\n");
        printf("10. Reverse List\n");
        printf("11. Count Nodes\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
                
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
                
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
                
            case 4:
                head = deleteFromBeginning(head);
                break;
                
            case 5:
                head = deleteFromEnd(head);
                break;
                
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                break;
                
            case 7:
                displayForward(head);
                break;
                
            case 8:
                displayBackward(head);
                break;
                
            case 9:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(head, data);
                break;
                
            case 10:
                head = reverse(head);
                break;
                
            case 11:
                printf("Total nodes: %d\n", countNodes(head));
                break;
                
            case 12:
                freeList(head);
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
