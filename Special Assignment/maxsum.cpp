#include <stdio.h>
#define MAX 100
int mainArr[MAX];
int dupArr[MAX];
int queue[MAX];
int sum[MAX];
int top=-1, front = -1, rear = -1, n=0, k=0;

void push(int ch)
{
    if(top==MAX-1)
      return;
    dupArr[++top]=ch;
}

int pop()
{
    if(top==-1)
      return -1;
    return dupArr[top--];
}

void enQueue(int value) 
{
  if (rear == MAX - 1)
    printf("\nQueue is Full");
  else
  {
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
  }
}

int deQueue()
{
    int value;
    if (front == -1)
    printf("\nQueue is Empty");
    else
    {
        value = queue[front];
        front++;
        if (front > rear)
            front = rear = -1;
    }

    return value;
}

//converting stack to queue.
void stackToQueue(int array[], int n)
{
    front = -1, rear = -1;                                  //reinitialising for new iteration
    for (int i = 0; i < n; i++)
        enQueue(array[i]);
}

void findMAX(int arr[], int n)
{
    int max=0;

    for (int i = 0; i < n; i++)
    {
        if(max < arr[i])
        max=arr[i];
    }

    printf("The Sum: %d", max);
}

int main()
{
    int x=0;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);                                       //No. of elements in the main array
    printf("Enter the no. elements to get deleted: ");
    scanf("%d", &k);                                       //No. of elements to be Deleted

    //INPUT BLOCK
    printf("ENTER THE ARRAY ELEMENTS: \n");
    for(int i=0;i<n;i++)
        scanf("%d", &mainArr[i]);

    int popN = 1, deqN = k-1;
    while (x!=k-1)
    {
        int s=0;
        //backup for main array
        for(int i=0;i<n;i++)
        {
            push(mainArr[i]);
        }
        printf("\n");

        //poping elements
        for(int i=0; i<popN; i++)
            s = s + pop();
        
        stackToQueue(dupArr, (n-popN));

        //deQueuing elements
        for (int i = 0; i < deqN; i++)
            s = s + deQueue();

        sum[x]=s;
        x++;
        popN++;
        deqN--;
    }
    
    findMAX(sum,k);
    return 0;
}