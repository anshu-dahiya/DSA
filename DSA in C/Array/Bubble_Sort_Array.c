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

//Bubble Sort
void bubbleSort(int *arr, int size)
{
    int temp;

    for (int i=0; i < size-1; i++)           //No. of passes n-1
    {
        printf("Working on Pass - %d\n",i+1);
        for (int j=0; j < size-1-i; j++)    //After every pass i no. of elements get sorted
        {
            if(arr[j] > arr[j+1])           //comparing adjecent element
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }   
    }   
}

//Adaptive Bubble Sort
void bubbleSortAdaptive(int *arr, int size)
{
    int temp;
    int isSorted = 0;                      //Flag helps us when array get sorted in less no. of passes

    for (int i=0; i < size-1; i++)         //No. of passes n-1
    {
        printf("Working on Pass - %d\n",i+1);
        isSorted = 1;                      //Flag is True

        for (int j=0; j < size-1-i; j++)   //After every pass i no. of elements get sorted
        {
            if(arr[j] > arr[j+1])         //comparing adjecent element
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                isSorted = 0;    //Flag will only get False if any swapping will occur
            }                    //If no swapping occur means no more sorting is required and Flag remain true
        }
        
        if(isSorted == 1)   //If Flag is True means array is sorted now 
        {                  //So it will break the loop of passes 
            return;
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

    bubbleSortAdaptive(arr, size);

    printf("After Sorting ");
    printArray(arr, size);
}