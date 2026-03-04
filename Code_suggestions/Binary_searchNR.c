#include<stdio.h>
int binary_iterative(int arr[],int n ,int key)
{
    int low=0 ,high=n-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==key) return mid;
        if(arr[mid]<key) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int main()
{
    int key;
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
    
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    
    int arr[n];
    printf("Enter the elements of the array in sorted order: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int result = binary_iterative(arr,n,key);
    
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