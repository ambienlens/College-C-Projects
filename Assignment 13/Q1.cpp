//Debayan Majumder
//C Program to Implement a Stack using Linked List

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*temp;
int count = 0;

void create()
{
    top = NULL;
}
 
void stack_count()
{
    printf("\nNo. of elements in stack : %d", count);
}
 
void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}

void display()
{
    top1 = top;
    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
 }
 

int pop()
{
    top1 = top;
    if (top1 == NULL)
    {
        printf("\nEmpty stack, cant take input");
        return 0;
    }
    else
        top1 = top1->ptr;
    
    //printf("\nPopped value : %d", top->info);
    free(top);
    top = top1;
    count--;
    
    return top->info;
}
 

int topelement()
{
    return(top->info);
}

void main()
{
    int no, ch, e, hehe;
    create();
 
    printf("***STACK OPERATIONS USING LINKED LIST***");
    while (1)
    {
        printf("\n1 - Push");
        printf("\n2 - Pop");
        printf("\n3 - Top");
        printf("\n4 - Stack Count");
        printf("\n5 - Dipslay");
        printf("\n6 - Exit");

        printf("\nEnter choice : ");
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            hehe = pop();
            printf("Kicked value: %d", hehe);
            break;
        case 3:
            if (top == NULL)
                printf("No elements in stack");
            else
            {
                e = topelement();
                printf("\nTop element : %d", e);
            }
            break;
        case 4:
            stack_count();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default :
            printf("Wrong Input, Enter correct option.");
            break;
        }
    }
}