#include<stdio.h>

//Traversal
void printArray(int *arr, int size)
{
    printf("array : ");
    for (int i = 0; i <= size-1; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//Selection Sort
void selectionSort(int *arr, int size)
{
    int temp;

    for (int i = 0; i < size-1; i++)       // No. Of passes n-1
    {
        int min = i;          //In Every Pass the min will be set same of i index

        for (int j = i+1; j <= size-1; j++)
        {
            if (arr[j] < arr[min])      //comparing the elements and min gets moves whenever it gets smaller element
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = arr[i];        //if min changes its index from i to another means it found the minimum element
            arr[i] = arr[min];    //And we swap the minimum element from element present at index i
            arr[min] = temp;
        }
    }
}

int main()
{
    int arr[50], size = 0;

    printf("Enter the size of array : ");
    scanf("%d",&size);

    if(size > 50)
    {
        printf("\nArray is Overflow\n");
    }

    else
    {
        printf("Enter the elements of array : ");
        for (int i = 0; i <= size-1; i++)
        {
            scanf("%d",&arr[i]);
        }
    }

    printf("Before Sorting ");
    printArray(arr, size);

    selectionSort(arr, size);

    printf("After Sorting ");
    printArray(arr, size);
}