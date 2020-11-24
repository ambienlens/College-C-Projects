//Debayan Majumder
//Write a program to sort a list of elements using selection sort algorithm.

#include <stdio.h>
#define MAX 10

void inputArray(int array[], int n)
{
    printf("Enter the array: \n");
    for(int i=0; i<n; i++)
        scanf("%d", &array[i]);
}

void displayArray(int array[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d\n", array[i]);
}

void selectionSort(int a[], int n)
{
    int i,j,l, pivot, t;
    for(i=0;i<n-1;i++)
    {
        pivot = a[i];
        l=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<pivot)
            {
                pivot = a[j];
                l=j;
            }
       }
       if(i!=l)
       {
           t = a[i];
           a[i] = a[l];
           a[l] = t;
       }
    }
}


int main()
{
    int array[MAX], n;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    inputArray(array, n);
    printf("Original Array: \n");
    displayArray(array, n);
    selectionSort(array, n);
    printf("Array after Selection Sorting: \n");
    displayArray(array, n);
    return 0;
}