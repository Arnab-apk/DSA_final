#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
//Linked list Traversal
void list_traversal(struct Node*ptr){
    while(ptr!=NULL)
    {
        printf("ELEMENT %d\n",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    struct Node*head;
    struct Node*second;
    struct Node*third;
    //allocate memory for nodes for ll in heap dynamially allocated
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
    return 0;
}









