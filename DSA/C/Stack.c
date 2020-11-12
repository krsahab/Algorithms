#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node;

void push(int arr[], int *top, int size, int item)
{
	if(*top==size-1)
	{
		printf("Overflow");
		return;
	}
	arr[++*top]=item;
}

int pop(int arr[], int *top)
{
	if(*top==-1)
	{
		printf("Underflow");
		return;
	}
	return arr[*top--];
}

void lpush(node* head, int item)
{
	node* ptr = (node*)malloc(sizeof(node));
	if(ptr==NULL)
	return;
	ptr->data = item;
	ptr->next = head;
	head = ptr;
}

int lpop(node* head)
{
	if(head==NULL)
	{
		printf("Underflow");
		return;
	}
	int item = head->data;
	node* temp = head;
	head=head->next;
	free(temp);
}

int main()
{
	int top=-1;
	int max=100;
	int arr[max];
	push(arr, &top, max, 6);
	printf("%d",pop(arr,&top));
}
