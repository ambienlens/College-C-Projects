//Debayan Majumder
//evaluation of postfix expression in C

#include <stdio.h>
#include <math.h>
#define MAX 100
char arr[MAX];
float value[MAX];
int top=-1;

void push(char ch)
{
    if(top==MAX-1)
    {
        printf("\n Stack Overflow");
        return;
    }
    arr[++top]=ch;
}

int pop()
{
    if(top==-1)
    {
        printf("\n Stack Underflow");
        return -1;
    }
    return arr[top--];
}

int postfixEvaluation(char postfix[], float value[])
{
    int i=0;
    char ch;
    float op1, op2, s;
    while (postfix[i]!=NULL)
    {
        ch=postfix[i];
        if((ch>=65 && ch<=90) || (ch>=97 && ch<=122))
        {
            push(value[i]);
        }
        else
        {
            op2=pop();
            op1=pop();
            switch (ch)
            {
                case '+':
                push(op1+op2);
                break;

                case '-':
                push(op1-op2);
                break;

                case '*':
                push(op1*op2);
                break;

                case '/':
                push(op1/op2);
                break;

                case '^':
                push(pow(op1,op2));
                break;

            }
        }
        i++;
    }
    return pop();
}

int main()
{
    char ch;
    float result;
    int i=0;
    printf("\n Enter a valid postfix expression:");
    gets_s(arr);
    while(arr[i]!='\0')
    { 
        ch = arr[i];
        if((ch>=65 && ch<=90) || (ch>=97 && ch<=122))
        {
            printf("\n Enter value for %c",ch);
            scanf("%f",&value[i]);
        }
        i++;
    }
    result = postfixEvaluation(arr, value);
    printf("\n Result = %f", result);
    return 0;
}