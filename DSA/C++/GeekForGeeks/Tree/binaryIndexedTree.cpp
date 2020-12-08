#include<bits/stdc++.h>
using namespace std;

int *tree;
int getSum(int x)
{
    x +=1;
    int res = 0;
    while (x>0)
    {
        res += tree[x];
        x = x-x&(-x);
    }
    return res;
}

void updateElement(int index, int diff, int size)
{
    index += 1;
    while (index <= size)
    {
        tree[index] += diff;
        index = index + index&(-index);
    }
}

void CreateTree(int arr[], int n)
{
    for(int i=0;i<n;i++)
        updateElement(i, arr[i], n);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    tree = new int[n+1];
    for(int i=1;i<=n;i++)
        tree[i] = 0;
    return 0;
}