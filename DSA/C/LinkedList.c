#include<stdio.h>
#include<stdlib.h>

int counter = 0;
struct node
{
	int e;
	struct node *next;
};

void print(struct node* head)
{
	struct node* ptr = head;
	while(ptr->next!=NULL);
	{
		printf("%d %d\n",ptr->e,ptr->next);
		ptr = ptr->next;
	}
}

struct node* create()
{
	struct node* element = (struct node*)malloc(sizeof(struct node));
	element->e = counter++;
	element->next = NULL;
	return element;
}

void add_end(struct node* head)
{
	struct node* ptr = head;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next = create();
	print(head);
}

void add_start(struct node* head)
{
	struct node* ptr = create();
	ptr->next = head;
	head = ptr;
	print(head);
}

void add_position(int position, struct node* head)
{
	struct node* ptr = head;
	struct node* element = create();
	while(ptr->e!=position)
	ptr = ptr->next;
	element->next = ptr->next;
	ptr->next = element;
}

void delete(struct node* head, int position)
{
	struct node* ptr = head;
	if(position==0)
	{
		if(ptr->next!=NULL)
		ptr = ptr->next;
		free(head);
	}
	else if(position==NULL)
	{
		if(ptr==NULL)
		return;
		if(ptr->next==NULL)
		{
			free(ptr);
			ptr==NULL;
			return;
		}
		while(ptr->next->next!=NULL)
		ptr=ptr->next;
		free(ptr->next);
		ptr->next=NULL;
	}
	else
	{
		if(ptr->e==position)
		{
			free(ptr);
			return;
		}
		while(ptr->next->e!=position)
		ptr=ptr->next;
		struct node* temp = ptr->next->next;
		free(ptr->next);
		ptr->next = temp;
	}
}
int main()
{
	struct node* head = create();
	print(head);
	add_end(head);
	add_start(head);
	add_end(head);
	add_start(head);
	add_end(head);
	add_start(head);
	add_end(head);
	add_start(head);
	add_end(head);
	add_start(head);
}

void forward(struct node* head)
{
	if(head!=NULL)
	{
		printf("%d",head->e);
		forward(head->next);
	}
}

void backward(struct node* head)
{
	if(head!=NULL)
	{
		backward(head->next);
		printf("%d",head->e);
	}
}

struct node* reverse(struct node* curr)
{
	struct node* pre = NULL;
	struct node* nex = NULL;
	while(curr)
	{
		nex=curr->next;
		curr->next = pre;
		pre = curr;
		curr = nex;
	}
	return pre;
}

void rev(struct node* pre, struct node* curr)
{
	if(curr)
	{
		rev(curr,curr->next);
		curr->next = pre;
	}
	else
	{
		head = pre;
	}
}
