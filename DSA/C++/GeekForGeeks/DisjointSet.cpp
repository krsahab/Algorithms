#include<bits/stdc++.h>
using namespace std;

int *parent;
int *rankArr;

//No need to create extra rank array, store rank & parent in same array, with -ve sign to denote it is parent and value is no of child it has

int find(int x)
{
    if(parent[x]==x)
        return x;
    else
        return find(parent[x]);
}

//O(1) solution with Union
int PathCompressionFind(int x)
{
    if(parent[x] == x)
        return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void Union(int a, int b)
{
    int p1 = parent[a];
    int p2 = parent[b];
    if(p1 == p2) return;
    parent[p2] = p1;
}

//O(logn solution with find)
void UnionByRank(int a, int b)
{
    int p1 = parent[a];
    int p2 = parent[b];
    if(p1 == p2) return;
    if(rankArr[p1]<rankArr[p2])
        parent[p1] = p2;
    else if(rankArr[p1]>rankArr[p2])
        parent[p2] = p1;
    else
    {
        parent[p2] = p1;
        rankArr[p1]++;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    parent = new int[n];
    rankArr = new int[n];
    for(int i=0;i<n;i++)
    {
        parent[i] = i;
        rankArr[i] = 0;
    }
    return 0;
}