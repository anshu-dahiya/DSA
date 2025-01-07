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

//Insertion Sort
void insertionSort(int *arr, int size)
{
    int temp, j;

    for(int i=1; i <= size-1; i++)      //i will start from index 1 bcoz index 0 assumed as Sorted List
    {
        temp = arr[i];
        j = i-1;

        while (j >= 0   &&   arr[j] > temp) 
        {
            arr[j+1] = arr[j];              
            j--;                    //after shifting j value to next index the index of j reduced by j--
        }
        arr[j+1] = temp;      //now index j+1 is empty and will allocated to temp when j is not greater then temp 
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

    insertionSort(arr, size);

    printf("After Sorting ");
    printArray(arr, size);
}