#include<stdio.h>

int main()
{
    int arr[50], size, i;
    
    printf("Enter the size of Array : ");
    scanf("%d",&size);
    
    if(size > 50)
    {
        printf("The array is overflow");
    }

    else
    {
        printf("Enter the elments in Array : ");
        for(i=0; i<=(size-1); i++)
        {
            scanf("%d",&arr[i]);
        }

        printf("Elements in array are : ");        //Traversing
        for(i=0; i<=(size-1); i++)
        {
            printf("%d ",arr[i]);
        }
    }
}
        
    
