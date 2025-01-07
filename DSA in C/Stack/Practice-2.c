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

// Counting Sort
void countingSort(int *arr, int size)
{
    int output[size];
    int max = arr[0];
    int min = arr[0];

    // Find the maximum and minimum elements in the array
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    int range = max - min + 1;
    int count[range];
    
    // Initialize the count array with zeros
    for (int i = 0; i < range; i++)
    {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < size; i++)
    {
        count[arr[i] - min]++;
    }

    // Change count[i] so that count[i] now contains the actual position of the element in output array
    for (int i = 1; i < range; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    // Copy the sorted elements into the original array
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
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