#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left,*right;
};

//creating a new node
struct node* createnode(int value)
{
    struct node* newnode=(struct node*) malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
}

//inserting a node
struct node* insert(struct node* root,int value)
{
    if(root==NULL)
        return createnode(value);
    if(value<root->data) root->left=insert(root->left,value);
    else if(value>root->data) root->right=insert(root->right,value);
    return root;
}

//count total number of nodes
int countnodes(struct node * root){
    if(root==NULL) return 0;
    return 1+countnodes(root->left)+countnodes(root->right);
}

//find minimum
int findmin(struct node* root)
{
    if(root==NULL) return -1;
    while(root->left!=NULL)root=root->left;
    return root->data;
}

//find maximum
int findmax(struct node* root)
{
    if(root==NULL) return -1;
    while(root->right!=NULL) root=root->right;
    return root->data;
}

//Inorder traversal
void Inorder_traversal(struct node * root)
{
    if(root!=NULL){
        Inorder_traversal(root->left);
        printf("%d ", root->data);
        Inorder_traversal(root->right);
    }
}

//Preorder traversal
void Preorder_traversal(struct node * root)
{
    if(root!=NULL){
        printf("%d ", root->data);
        Preorder_traversal(root->left);
        Preorder_traversal(root->right);
    }
}

//Postorder traversal
void Postorder_traversal(struct node * root)
{
    if(root!=NULL){
        Postorder_traversal(root->left);
        Postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}


int main()
{
    struct node* root=NULL;
    int choice, value;
    
    while(1)
    {
        printf("\n=== Binary Search Tree Menu ===");
        printf("\n1. Insert a value");
        printf("\n2. Count total nodes");
        printf("\n3. Find minimum value");
        printf("\n4. Find maximum value");
        printf("\n5. Inorder Traversal");
        printf("\n6. Preorder Traversal");
        printf("\n7. Postorder Traversal");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d",&value);
                root=insert(root,value);
                printf("Value inserted successfully\n");
                break;
                
            case 2:
                printf("Total number of nodes: %d\n",countnodes(root));
                break;
                
            case 3:
            {
                int min=findmin(root);
                if(min==-1)
                    printf("Tree is empty\n");
                else
                    printf("Minimum value: %d\n",min);
                break;
            }
                
            case 4:
            {
                int max=findmax(root);
                if(max==-1)
                    printf("Tree is empty\n");
                else
                    printf("Maximum value: %d\n",max);
                break;
            }
                
            case 5:
                if(root==NULL)
                    printf("Tree is empty\n");
                else
                {
                    printf("Inorder Traversal: ");
                    Inorder_traversal(root);
                    printf("\n");
                }
                break;
                
            case 6:
                if(root==NULL)
                    printf("Tree is empty\n");
                else
                {
                    printf("Preorder Traversal: ");
                    Preorder_traversal(root);
                    printf("\n");
                }
                break;
                
            case 7:
                if(root==NULL)
                    printf("Tree is empty\n");
                else
                {
                    printf("Postorder Traversal: ");
                    Postorder_traversal(root);
                    printf("\n");
                }
                break;
                
            case 8:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}