#include<stdio.h>
void tower_of_hanoi(int n,char source,char aux,char dest)
{
    if(n==1){
        printf("Move disk 1 from %c to %c\n",source,dest);
        return;
    }
    //move n-1 disk from source to auxillary
    tower_of_hanoi(n-1,source,dest,aux);
    //move nth disk from source to dest
    printf("Move disk %d from %c to %c\n",n ,source ,dest);
    //move n-1 disk from aux to dest
    tower_of_hanoi(n-1,aux,source,dest);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    
    printf("Tower of Hanoi solution for %d disks:\n",n);
    toh(n,'A','B','C');
    
    return 0;
}