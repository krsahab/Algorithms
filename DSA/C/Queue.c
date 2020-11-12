#include<stdio.h>
#include<stdlib.h>

int enque(int arr[], int size, int item, int *f, int *r)
{
	*r=(*r+1)%size;
	if(*r==*f)
	{
		printf("List is full");
		if(*r==0)
		*r = size-1;
		else
		*r-=1;
		return 0;
	}
	else
	{
		arr[*r] = item;
		return 1;
	}
}

int deque(int arr[], int size, int *f, int *r)
{
	if(*f==*r)
	{
		printf("List is empty");
		return -1;
	}
	else
	{
		*f=(*f+1)%size;
		return arr[*f];
	}
}

int main()
{
	int size = 100, f = 0, r = 0;
	int arr[size];
	enque(arr, size, 6, &f, &r);
	enque(arr, size, 7, &f, &r);
	enque(arr, size, 10, &f, &r);
	enque(arr, size, 8, &f, &r);
	int num = deque(arr, size, &f, &r);
	printf("%d",num);
}
