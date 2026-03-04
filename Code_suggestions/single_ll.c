//insertion deletion from ends of a singly lined list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
//global head
struct node* head=NULL;

//inserting at beginning 
void insert_at_beginning(int val)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=head;
    head=newnode;
    printf("Inserted %d at the beginning.\n",val);
}


//inserting at end
void insert_at_end(int val)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    //edge case 1
    if(head==NULL){
        head=newnode;
        printf("Inserted %d at end.\n", val);
        return;
    }

    //travelling to the last node
    //normal
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    printf("Inserted %d at end.\n",val);

}

//deletion from beginning
void delete_from_beg(){
    //edge case
    if(head==NULL)
    {
        printf("Already empty!\n");    
        return;
    }
    struct node*temp=head;
    head=head->next;
    printf("Deleted %d from begging.\n",temp->data);
    free(temp);
}

//delete from end
void deletefromend()
{
    if(head==NULL)
    {
        printf("Already empty.\n");
        return;
    }
    if(head->next==NULL){
        printf("Deleted %d from end.\n",head->data);
        free(head);
        head=NULL;
        return;
    }

    //tervelling to teh 2nd last place 
    struct node*temp=head;
    while(temp->next->next !=NULL)
    {
        temp=temp->next;
    }
    //temp->next null then
    printf("Deleted %d from end.\n",temp->next->data);
    free(temp->next);
    temp->next=NULL;
}

void display()
{
    if(head==NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node* temp=head;
    printf("List: ");
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        if(temp->next!=NULL)
        {
            printf(" -> ");
        }
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, val;

    while(1)
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        switch(choice)
        {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d",&val);
                insert_at_beginning(val);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d",&val);
                insert_at_end(val);
                break;

            case 3:
                delete_from_beg();
                break;

            case 4:
                deletefromend();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please choose 1-6.\n");
        }
    }

    return 0;
}