//Debayan Majumder
//Write programs to sort a list of elements using Quick sort algorithm considering
//First element as a pivot

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

void quickSort(int array[], int n)
{
    int l, pivot, t;
    for(int i=0; i<n-1; i++){
        pivot = array[i];
        l = i;
        for(int j=i+1; j<n; j++)
        {
            if(array[j] < pivot)
            {
                pivot = array[j];
                l=j;
            }
        }
        if(i! = l)
        {
            t = array[i];
            array[i] = array[l];
            array[l] = t;
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
    quickSort(array, n);
    printf("Array after Insertion Sorting: \n");
    displayArray(array, n);
    return 0;
}