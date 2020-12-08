#include<bits/stdc++.h>
using namespace std;

int c = 10;
int s = 0;
int arr[10];

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void minheapify(int i)
{
    int smallest = i;
    int l = left(i);
    int r = right(i);
    if(l<s && arr[i]>arr[l])
    smallest = l;
    if(r<s && arr[smallest]>arr[r])
    smallest = r;
    if(smallest!=i)
    {
    swap(arr[smallest],arr[i]);
    minheapify(smallest);
    }
}

int parent(int i)
{
    return (i-1)/2;
}

int right(int i)
{
    return i*2+2;
}

int left(int i)
{
    return i*2+1;
}

void insert(int num)
{
    if(s==10)
    return;
    arr[s++]=num;
    for(int i=s-1;i>0;i--)
    {
        if(arr[i]<arr[parent(i)])
        swap(arr[i],arr[parent(i)]);
        i=parent(i);
    }
}

int main()
{
    for(int i=0;i<10;i++)
    insert(i+1);
    for(int i=0;i<10;i++)
    cout<<arr[i]<<" ";
    return 0;
}