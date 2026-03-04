#include<stdio.h>
int binary_recursive(int arr[],int low, int high,int key)
{
    if(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==key) return mid;
        if(arr[mid]<key) 
        return binary_recursive(arr,mid+1,high,key);

        return binary_recursive(arr,low,mid-1,key);
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
    
    int result = binary_recursive(arr,0,n-1,key);
    
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
