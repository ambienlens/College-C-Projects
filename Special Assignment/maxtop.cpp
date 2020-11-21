#include <stdio.h>
#define MAX 100
int top=-1, n=0, k=0;
int arr[MAX];
int stack[MAX];

void push(int ch)
{
    if(top==MAX-1)
      return;
    stack[++top]=ch;
}

int pop()
{
    if(top==-1)
      return -1;
    return stack[top--];
}

int peek(void){
   int x;
   if(top == -1)
   {
       printf("\n Stack is empty");
       return -1;
   }
   x = stack[top];
   return x;
}

int maxTop(int n, int k)
{
    int max = peek(), poped;   //init.
    for(int i=0; i<k; i++)
    {
        poped = pop();
        if(poped>max)
            max = poped;
    }

    push(max);
    return max;
}

int main()
{
    //INPUT BLOCK
    printf("Enter the no. of Elements: ");
    scanf("%d", &n);
    printf("Enter the no of Operations: ");
    scanf("%d", &k);

    printf("ENTER THE ELEMENTS: ");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    //reversing array
    for (int i = n-1; i>=0; i--)
        push(arr[i]);

    //finding the MAX element from the poped ones and storing
    int result=0;
    result = maxTop(n, k);

    printf("The Max: %d\n", result);      //printing out result
    return 0;
}