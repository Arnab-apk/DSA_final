#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the array

int arr[MAX];
int n = 0; // Current number of elements in the array

// Function to display the array elements
void display() {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specific position
void insert() {
    int pos, val;
    if (n == MAX) {
        printf("Array Overflow! Cannot insert more elements.\n");
        return;
    }
    printf("Enter position (0 to %d) to insert: ", n);
    scanf("%d", &pos);
    
    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return;
    }
    
    printf("Enter value to insert: ");
    scanf("%d", &val);
    
    // Shift elements to the right to make space
    for (int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = val;
    n++; // Increase array size count
    printf("Element inserted successfully.\n");
}

// Function to delete an element from a specific position
void deleteElem() {
    int pos;
    if (n == 0) {
        printf("Array Underflow! Array is already empty.\n");
        return;
    }
    printf("Enter position (0 to %d) to delete: ", n - 1);
    scanf("%d", &pos);
    
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }
    
    // Shift elements to the left to fill the gap
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--; // Decrease array size count
    printf("Element deleted successfully.\n");
}

// Function to update an element at a specific position
void update() {
    int pos, val;
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Enter position (0 to %d) to update: ", n - 1);
    scanf("%d", &pos);
    
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }
    
    printf("Enter new value: ");
    scanf("%d", &val);
    arr[pos] = val;
    printf("Element updated successfully.\n");
}

// Function to search for an element (Linear Search)
void search() {
    int val, found = 0;
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Enter value to search: ");
    scanf("%d", &val);
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("Element %d found at position %d.\n", val, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element not found in the array.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Update\n4. Search\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: insert(); break;
            case 2: deleteElem(); break;
            case 3: update(); break;
            case 4: search(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}