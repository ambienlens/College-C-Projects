//Debayan Majumder
//Write a program to sort a list of elements using bubble sort algorithm and also implement modified bubble sort.

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

void bubbleSort(int array[], int n)
{
    int temp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    printf("Array after bubble sorting: \n");
    displayArray(array, n);
}

void modifiedBubbleSort(int array[], int n)
{
    int temp, c;
    for(int i=0; i<n-1; i++)
    {
        c = 1;
        for(int j=0; j<n-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                c = 0;
            }
        }
        if(c == 1)
            break;
    }
    printf("Array after modified bubble sorting: \n");
    displayArray(array, n);
}

int main()
{
    int array[MAX], n, choice;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    inputArray(array, n);
    printf("Original Array: \n");
    displayArray(array, n);

    printf("Enter 1 for normal  Bubble Sort, and 2 for Modified Bubble Sort: \n");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
        bubbleSort(array, n);
        break;

        case 2:
        modifiedBubbleSort(array, n);
        break;

        default:
        printf("Wrong Input!\n");
    }
    return 0;
}