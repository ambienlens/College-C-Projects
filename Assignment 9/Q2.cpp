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

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

int partition (int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);  
    return (i + 1);  
}  

void quickSort(int array[], int low, int high) 
{  
    if (low < high)  
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);  
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
    quickSort(array, 0, n-1);
    printf("Array after Insertion Sorting: \n");
    displayArray(array, n);
    return 0;
}