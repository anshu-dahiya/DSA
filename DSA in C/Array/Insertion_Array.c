#include<stdio.h>

int main()
{
    int arr[50], size, i, num, pos;

    printf("Enter the size of array : ");
    scanf("%d",&size);

    if(size > 50)
    {
        printf("The Array is Overflow");
    }

    else
    {
        printf("Enter the elements in array : ");
        for(i=0; i <= size-1; i++)
        {
            scanf("%d",&arr[i]);
        }

        printf("Elements in array are : ");
        for(i=0; i <= size-1; i++)
        {
            printf("%d ",arr[i]);
        }

        printf("\nEnter the data you want to insert : ");
        scanf("%d",&num);
        
        printf("\nEnter positon where data should be inserted : ");
        scanf("%d",&pos);

        if(pos <= 0 || pos > size+1)
        {
            printf("Postion is invalid\n");
        }
        
        else
        {   //Insertion
            for(i = size-1; i >= pos-1; i--)        
            {
            arr[i+1] = arr[i];
            }
            arr[pos-1] = num;
            size++;
        }

        printf("\nElements in array are : ");
        for(i=0; i <= size-1; i++)
        {
            printf("%d ",arr[i]);
        }
    }
} 