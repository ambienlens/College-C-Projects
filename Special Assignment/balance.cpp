#include <stdio.h>
#define MAX 50
char arr[MAX];
char tempArr[MAX];
int top=-1;

int checkBrackets(char bracket)
{
    int flag=0;
    if((bracket=='(')||(bracket==')'))
        flag=1;
    else if((bracket=='{')||(bracket=='}'))
        flag=2;
    else if ((bracket=='[')||(bracket==']'))
        flag=3;
    
    return flag;
}

void push(char ch)
{
    if(top==MAX-1)
      return;
    arr[++top]=ch;
}

int pop()
{
    if(top==-1)
      return -1;
    return arr[top--];
}

int peek(void){
   int x;
   if(top == -1)
	return -1;
   x = arr[top];
   return x;
}

int checkForSize(char brackets[])
{
    int c=0;
    for(int i=0;i<MAX;i++)
        if((checkBrackets(brackets[i])==1)||(checkBrackets(brackets[i])==2)||(checkBrackets(brackets[i])==3))
            c++;
    
    return c;
}


int checkBalance(char myArr[], int n)
{
    int c=0;
    int i=0;
    
    while (i!=n)
    {
        char ch=myArr[i];
        if((ch=='(')||(ch=='{')||(ch=='['))
        {
            push(ch);
            c++;
        }
        else if ((ch==')')||(ch=='}')||(ch==']'))
        {
            int checkLast = peek();
            if(checkBrackets(checkLast)==checkBrackets(ch))
            {
                pop();
                c--;
            }
            else
            {
                push(ch);
                c++;
            }
            
        }
        i++;
    }

    if(c==0)
    return 1;
    else
    return 0;
}

int main()
{
    int n;
    int number;
    int c=1;

    printf("Enter number of expressions: ");
    scanf("%d", &number);

    while (number!=0)
    {
        printf("EXPRESSION NO: %d \n", c);
        printf("Enter the list \n");
        scanf("%s", tempArr);
        n = checkForSize(tempArr);

        if(checkBalance(tempArr,n)==1)
            printf("Yes \n");
        else
            printf("No \n");

        number--;
        c++;
    }
    return 0;
}