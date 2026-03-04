#include<stdio.h>
//--Linear Search--//
int linear_search(int arr[],int n,int key)
{
    for(int i=0; i<n ;i++)
    {
        if(arr[i]==key)
        return i;
    }
    return -1;
}

int main()
{   int key;
    printf("Enter the element to be searched ");
    scanf("%d",&key);
    int n;
    printf("Enter the number of elements ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int result = linear_search(arr,n,key);
    
    if(result == -1)
    {
        printf("Element not found in the array\n");
    }
    else
    {
        printf("Element found at index %d\n",result);
    }
    
    return 0;
}