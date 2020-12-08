#include<bits/stdc++.h>

using namespace std;

int *arr;
int *nextElement;
int *top;
int nextFree = 0;

void pushElement(int stack, int data)
{
    if(nextFree==-1)
    {
        cout<<"Stack is full"<<endl;
        return;
    }
    int i = nextFree;
    arr[i] = data;
    nextFree = nextElement[i];
    nextElement[i] = top[stack];
    top[stack] = i;
}

int popElement(int stack)
{
    if(top[stack]==-1)
        return -1;
    int i = top[stack];
    top[stack] = nextElement[i];
    nextElement[i] = nextFree;
    nextFree = i;
    return arr[i];
}

int topElement(int stack)
{
    return arr[top[stack]];
}

int main()
{
    int k = 3;
    int n = 100;
    arr = new int[n];
    nextElement = new int[n];
    top = new int[k];
    for(int i=0;i<n-1;i++)
        nextElement[i] = i+1;
    pushElement(1, 2);
    cout<<popElement(1)<<endl;
    return 0;
}