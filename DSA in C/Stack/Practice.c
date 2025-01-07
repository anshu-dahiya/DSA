#include<stdio.h>

//Creation
void create(int arr[], int *size)
{
    printf("Enter the size of array : ");
    scanf("%d",size);

    if(*size > 50)
    {
        printf("The Array is Overflow");
    }

    else
    {
        printf("Enter the elements is array : ");
        for (int i = 0; i <= *size-1; i++)
        {
            scanf("%d",&arr[i]);
        }
        
    }
}

//Traversal
void display(int arr[], int size)
{
    int count = 0;

    printf("\nThe elements in array are : ");
    for (int i = 0; i <= size-1; i++)
    {
        printf("%d ",arr[i]);
        count++;
    }
    printf("\nNo. of elements in array are : %d",count);
}

//Insertion
void insert(int arr[], int *size)
{
    int num,pos;

    printf("Enter the element you want to insert : ");
    scanf("%d",&num);

    printf("\nEnter the position where you want to insert the element: ");
    scanf("%d",&pos);

    if(pos <=0  ||  pos > *size+1)
    {
        printf("\nPosition Invalid");
    }

    else
    {
        for (int i = *size-1; i >= pos-1; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[pos-1] = num;
        (*size)++;
    }
}

//Deletion
void delete(int arr[], int *size)
{
    int num,pos;

    printf("\nEnter the position where you want to delete : ");
    scanf("%d",&pos);

    if(pos <=0  ||  pos > *size+1)
    {
        printf("\nPosition Invalid");
    }

    else
    {
        num = arr[pos-1];
        for (int  i = pos-1; i <= *size-1; i++)
        {
            arr[i] = arr[i+1];
        }
        (*size)--;
        
        printf("\nDeleted element is : %d",num);
    }
}

//Index searching
void search(int arr[], int size)
{
    int choice, element, searchIndex;

    printf("\nEnter the Element you want to search : ");
    scanf("%d",&element);

    //Linear Search
    int linearSearch(int arr[], int size, int element)
    {
        for(int i=0; i < size; i++)
        {
            if(arr[i]==element)
            {
                return i;
            }
        }
        return -1;
    }

    //Binary Search
    int binarySearch(int arr[], int size, int element)
    {
        int low, mid, high;
        low = 0 ;
        high = size-1;

        while(low <= high)
        {
            mid = (low + high)/2;
            if(arr[mid] == element)
            {
                return mid;
            }

            if(arr[mid] < element)
            {
                low = mid + 1;
            }
        
            else
            {
                high = mid-1;
            }        
        }
        return -1;
    }

    printf("\nTypes Of Search\n");
    printf("1.Linear Search\n");
    printf("2.Binary Search(Only if Array is Sorted)\n");
    printf("\nChoose the search to find index of element : ");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            searchIndex =  linearSearch(arr, size, element);
            printf("Index of %d is : %d", element,searchIndex);
            break;

        case 2:
            searchIndex = binarySearch(arr, size, element);
            printf("Index of %d is : %d", element,searchIndex);
            break;
      
        default:
            printf("Invalid Choice!\n");
    } 
}

int main()
{
    int arr[50], size = 0, choice;

    while (1)
    {
        printf("\n\n1.Create Array\n");
        printf("2.Display Array\n");
        printf("3.Insert Element\n");
        printf("4.Delete Element\n");
        printf("5.Search Index Of Element\n");
        printf("6.Exit\n");
        printf("Enter your Choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            create(arr, &size);
            break;

        case 2:
            display(arr, size);
            break;
        
        case 3:
            insert(arr, &size);
            break;
        
        case 4:
            delete(arr, &size);
            break;
        
        case 5:
            search(arr, size);
            break;

        case 6:
            return 0;
        
        default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}
