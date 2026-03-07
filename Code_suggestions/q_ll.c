#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure with front and rear pointers
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    if (q == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Function to enqueue (insert at rear)
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);
    
    // If queue is empty
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        printf("Enqueued %d to queue\n", data);
        return;
    }
    
    // Add new node at the end and update rear
    q->rear->next = newNode;
    q->rear = newNode;
    printf("Enqueued %d to queue\n", data);
}

// Function to dequeue (remove from front)
int dequeue(struct Queue* q) {
    // Check if queue is empty
    if (isEmpty(q)) {
        printf("Queue Underflow! Queue is empty.\n");
        return -1;
    }
    
    // Store front node and move front one node ahead
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    
    // If front becomes NULL, then update rear as NULL too
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return data;
}

// Function to get front element
int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

// Function to display the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    
    struct Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the queue memory
void freeQueue(struct Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

// Main function to demonstrate queue operations
int main() {
    struct Queue* q = createQueue();
    int choice, value;
    
    while (1) {
        printf("\n----- Queue Operations Menu -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek (Front element)\n");
        printf("4. Display Queue\n");
        printf("5. Check if Empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
                
            case 2:
                value = dequeue(q);
                if (value != -1) {
                    printf("Dequeued element: %d\n", value);
                }
                break;
                
            case 3:
                value = peek(q);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
                
            case 4:
                display(q);
                break;
                
            case 5:
                if (isEmpty(q)) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
                
            case 6:
                freeQueue(q);
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
