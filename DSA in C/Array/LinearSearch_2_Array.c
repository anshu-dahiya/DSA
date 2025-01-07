#include<stdio.h>

int linearSearch(int arr[], int size, int element)
{
    for(int i=0; i < size; i++)
    {
        if(arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[50], size, i, num, pos, element;

    printf("Enter the size of array : ");
    scanf("%d",&size);

    if(size > 50)
    {
        printf("Array is overflow");
    }
    else
    {
        printf("Enter the elements in array : ");
        for(i=0; i < size; i++)
        {
            scanf("%d",&arr[i]);
        }

        printf("Enter the data you wants to insert : ");
        scanf("%d",&num);

        printf("Enter the position where data should be inserted : ");
        scanf("%d",&pos);

        if(pos <= 0 || pos > size+1)
        {
            printf("Invalid Position %d",pos);
        }

        else
        {
            for(i = size-1; i >= pos-1; i--)
            {
                arr[i+1] = arr[i];
            }
            arr[pos-1] = num;
            size++;
        }


        printf("\nThe Elements in array are : ");
        for(i = 0; i < size; i++)
        {
            printf("%d ",arr[i]);
        }


        printf("\nEnter the position where you wants to delete : ");
        scanf("%d",&pos);

        if(pos <= 0 || pos > size)
        {
            printf("Invalid Position %d",pos);
        }

        else
        {
            num = arr[pos-1];
            for(i = pos-1; i <= size-1; i++)
            {
                arr[i] = arr[i+1];
            }
            size--;
            printf("\nDeleted elements is : %d",num);
        }    

        printf("\nThe Elements in array are : ");
        for(i = 0; i < size; i++)
        {
            printf("%d ",arr[i]);
        }

        printf("\nEnter the element you want to search : ");
        scanf("%d",&element);

        int searchIndex = linearSearch(arr, size, element);
        printf("The element %d found on index %d", element, searchIndex);

    }
    
}