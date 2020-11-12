#include <stdio.h>
#include <stdlib.h>

typedef struct node
	{
		int value;
		struct node *node_left;
		struct node *node_right;
	}Node;
	
int main()
{	
	int n;
	scanf("%d",&n);
	struct node *n1 = NULL;
	struct node *n2 = NULL;
	struct node *n3 = NULL;
	
	n1 = (struct node*)malloc(sizeof(struct node));
	n2 = (struct node*)malloc(sizeof(struct node));
	n3 = (struct node*)malloc(sizeof(struct node));
	
	n1->node_left = n2;
	n1->node_right = n3;
	n1->value = 10;
	n2->node_left = NULL;
	n2->node_right = NULL;
	n2->value = 20;
	n3->node_left = NULL;
	n3->node_right = NULL;
	n3->value = 30;
	
	printf("data: %i",n1->node_left);
	printf("data: %i",n1->node_right);
}
