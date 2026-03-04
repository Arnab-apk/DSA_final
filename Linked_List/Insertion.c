#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
void list_traversal(struct Node*ptr){
    while(ptr!=NULL)
    {
        printf("ELEMENT %d\n",ptr->data);
        ptr=ptr->next;
    }
}
//Insertion at beginning
//insert in between
//insert at the end
//insert after a specified node
//Linked list Traversal

struct Node* insertAtFirst(struct Node*head,int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

struct Node*insertAtIndex(struct Node*head,int data,int index)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node*p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

int main()
{
    struct Node*head;
    struct Node*second;
    struct Node*third;
    //allocate memory for nodes for l.l in heap dynamially allocated
    head=(struct Node*)  malloc(sizeof(struct Node));
    second =(struct Node*)  malloc(sizeof(struct Node));
    third=(struct Node*)  malloc(sizeof(struct Node));

    head->data=10;
    head->next=second;

    second->data=11;
    second->next=third;

    third->data=12;
    third->next=NULL;
    
    list_traversal(head);
    printf("\n");
    head=insertAtFirst(head,20);
    list_traversal(head);
    printf("\n");
    int index;
    printf("Enter the position you want to insert teh element:-");
    scanf("%d",&index);
    insertAtIndex(head,69,index-1);
    list_traversal(head);
    return 0;



}