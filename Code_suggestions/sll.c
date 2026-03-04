#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head =NULL;


void insertfront()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    printf("Inserted at front\n");
}

void insertend(){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
}

int main()
{

}