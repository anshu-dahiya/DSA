#include<stdio.h>

int main()
{
    int arr[50], size, i, pos, num;

    printf("Enter the size of array : ");
    scanf("%d",&size);

    if(size > 50)
    {
        printf("The array is overflow");
    }

    else
    {
        printf("Enter the elements in array : ");
        for(i=0; i <= size-1; i++)
        {
            scanf("%d",&arr[i]);
        }

        printf("\nElements in array are : ");
        for(i=0; i <= size-1; i++)
        {
            printf("%d ",arr[i]);
        }

        printf("\nEnter the position where you want to delete : ");
        scanf("%d",&pos);

        if (pos <= 0 || pos > size)
        {
            printf("Invalid Position : %d",pos);
        }

        else
        {   //Deletion
            num = arr[pos-1];
            for(i = pos-1; i <= size-1; i++)
            {
                arr[i] = arr[i+1];
            }
            size--;
            
            printf("\nElements in array are : ");
            for(i=0; i <= size-1; i++)
            {
                printf("%d ",arr[i]);
            }

            printf("\nDeleted Element is : %d",num);
        }        
       
    }
}