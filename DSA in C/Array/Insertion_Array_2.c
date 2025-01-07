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

        printf("Enter the data you want to insert : ");
        scanf("%d",&num);
        
        printf("Enter positon where data should be inserted : ");
        scanf("%d",&pos);

        if(pos <= 0 || pos > size+1)
        {
            printf("Postion is invalid\n");
        }
        
        else
        {
            arr[size] = arr[pos-1];                //This can be best case for insertion in time complexity
            arr[pos-1] = num;                      //Current element on Position enter by user will shifted at last
            size++;                                //and New element can be stored in that Position 
        }

        printf("Elements in array are : ");
        for(i=0; i <= size-1; i++)
        {
            printf("%d ",arr[i]);
        }
    }

}