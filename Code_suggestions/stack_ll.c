#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* top=NULL;

void push()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("ENter value to push: ");
    scanf("%d",&newnode->data);

    newnode->next=top;
    top=newnode;
    printf("pushed %d\n",newnode->data);
}

void pop()
{
    if(top==NULL){
        printf("Stack underflow\n");
        return;
    }
    struct node* temp=top;
    printf("Popped %d\n",top->data);
    top=top->next;
    free(temp);
}

void display()
{
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    struct node*temp =top;
    printf("Stack: ");
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice;
    
    while(1){
        printf("\n--- Stack Operations (Linked List) ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
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