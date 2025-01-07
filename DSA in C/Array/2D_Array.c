#include<stdio.h>

int main()
{
    int arr[2][3], i, j;
    int *p;

    printf("Enter the elements in array : ");

    for(i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("Elements in array are : ");
    for(j=0; j<3; j++)
    {
        for(i=0; i<2; i++)
        {
            printf("%d ",arr[i][j]);
        }
    }
    p = &arr[1][1];
    printf("\n%p",p);
}