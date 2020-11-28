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

void insertionSort(int array[], int n)
{
    int i, j, key;
    for(i=1; i<n; i++)
    {
        key = array[i];
        j = i-1;
        while(j>=0 && array[j]>key)
        {
            array[j+1] = array[j];
            j--;
        } 
        array[j+1] = key;
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
    insertionSort(array, n);
    printf("Array after Insertion Sorting: \n");
    displayArray(array, n);
    return 0;
}