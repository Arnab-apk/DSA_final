#include<stdio.h>
#include<stdlib.h>
#define max 5

int stack[max];
int top=-1;

//function to add an element to the top of the stack
void push()
{
    int val;
    if (top==max-1){
        printf("Stack Overflow\n");
    }
 else {
    printf("Enter value to push: ");
    scanf("%d",&val);
    top++;
    stack[top]=val;
    printf("%d pushed to stack.\n",val);

}
}

//function to remove the top element
void pop()
{
    if(top==-1){
        printf("Stack underflow\n");
    }else{
        printf("Popped element is :%d\n", stack[top]);
        top--;
    }
}

//function to display stack of elements
void display()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }else{
        printf("Stack elements from top to bottom: \n");
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}

int main()
{
    int choice;
    
    while(1)
    {
        printf("\n--- Stack Operations ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
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