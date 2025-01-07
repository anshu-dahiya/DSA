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

        printf("Enter the position where you want to delete : ");
        scanf("%d",&pos);

        if (pos <= 0 || pos > size)
        {
            printf("Invalid Position : %d",pos);
        }

        else
        {
            num = arr[pos-1];
            arr[pos-1] = arr[size-1];
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