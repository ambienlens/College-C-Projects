//Debayan Majumder
//Menu driven linked list program

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType
{
    int data;
    struct nodeType *next;
} node;

void createList(node *head)
{
    char ch;
    while (1)
    {
        printf("Enter the data: \n");
        scanf("%d", &head ->data);
        printf("Want to enter another node? (Y/N)");
        scanf("%c", &ch);
        if (ch == 'n' || ch == 'N')
        {
            head ->next = NULL;
            break;
        }
        head ->next = (node*)malloc(sizeof(node));
        head = head ->next;
    }
}

void displayList(node *head)
{
    while(head ->next != NULL)
    {
        printf("%d ->", head ->data);
        head = head ->next;
    }
    printf("%d", head ->data);
}

node *findNode(node *head, int x)
{
    while(head ->data != x && head != NULL)
    {
        head = head->next;
	}
	return head;
}

node *insertBeforeFirstNode(node *head)
{
    node *n1;
    n1 = (node*)malloc(sizeof(node));
    printf("Enter data for new node: ");
    scanf("%d", n1 ->data);
    n1 ->next = head;
    return n1;
}

node *insertAfterSpecificNode(node *head)
{
    node *n1, *l;
	int x;
	printf("Enter data of a node after which you want to insert: \n");
	scanf("%d",&x);
	l = findNode(head,x);
	if(l==NULL)
    {
		printf("Node is not found \n");
		return head;
	}
	n1 = (node *)malloc(sizeof(node));
	printf("Enter data for the new node: \n");
	scanf("%d",&n1->data);
	n1->next = l->next;
	l->next = n1;
	return head;
}

int main()
{
    node *h, *l;
	int x, y;
	h = (node *)malloc(sizeof(node));
	while(1)
    {
		printf("\n Press 1 to create a linked list");
		printf("\n Press 2 to display Linked list");
		printf("\n Press 3 to insert a new node");
		printf("\n Press 4 to exit");
		scanf("%d",&x);
		switch(x){
			case 1: createList(h);
					break;
			case 2: printf("\n The list is:");
					displayList(h);
					break;
			case 3: 
					printf("\n Press 1 to insert a new node before the 1st node");
					printf("\n Press 2 to insert a new node after a specific node");
					printf("\n Press 3 to insert a new node after the last node");
					printf("\n Press 4 to go to the previous menu");
					scanf("%d",&y);
					switch(y){
						case 1: h = insertBeforeFirstNode(h);
								break;
						case 2: h = insertAfterSpecificNode(h);
								break;
						case 3: //h = insertAfterLastNode(h);
								break;
						case 4: break;
					}
					break;
			case 4: exit(0);
		}
    }
    return 0;
}