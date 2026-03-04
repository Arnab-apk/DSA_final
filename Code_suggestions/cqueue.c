#include<stdio.h>
#include<stdlib.h>

#define max 5

int cqueue[max];
int front,rear=-1;

void enqueue()
{
    int val;
    //now checking is queue is full(rear is just behind front)
    if((rear+1)%max==front){
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter the value to insert: ");
    scanf("%d", &val);

    if (front ==-1) front=0;
    rear=(rear+1)%max; //wrapping around using modulo
    cqueue[rear]=val;
    printf("Inserted %d\n",val);

}

void dequeue()
{
    if(front==-1){
        printf("Queue underflow\n");
        return;
    }
    printf("Deleted %d\n", cqueue[front]);

    //resetting if there was only one element
    if(front==rear){
        front=-1;
        rear=-1;
    } else{
        front=(front+1)%max; //wrap around
    }
}

void display(){
    if(front==-1){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i= front;
    while(1){
        printf("%d ",cqueue[i]);
        if(i==rear) break;
        i=(i+1)%max;
    }
    printf("\n");
}

int main()
{
    int choice;
    front=-1;
    
    while(1)
    {
        printf("\n--- Circular Queue Operations ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}