#include<bits/stdc++.h>
using namespace std;

int *sTree;

struct segmentTree
{
    int start;
    int end;
    int sumTotal;
    segmentTree *left;
    segmentTree *right;
};

segmentTree *buildTree(int arr[], int s, int e)
{
    segmentTree *tree = new segmentTree();
    tree->start = s;
    tree->end = e;
    if(e-s>0)
    {
        int m = s+(e-s)/2;
        tree->left = buildTree(arr, s, m);
        tree->right = buildTree(arr, m+1, e);
        tree->sumTotal = tree->left->sumTotal+tree->right->sumTotal;
    }
    else
        tree->sumTotal = arr[s];
    return tree;
}

int buildSTree(int arr[], int s, int e, int i)
{
    if(s == e)
    {
        sTree[i] = arr[s];
        return sTree[i];
    }
    int m = (s+e)/2;
    sTree[i] = buildSTree(arr, s, m, 2*i+1) + buildSTree(arr, m+1, e, 2*i+2);
    return sTree[i];
}

int getSum(int qs, int qe, int ss, int se, int i)
{
    if(qe<ss || qs>se)
        return 0;
    if(qs<=ss && qe>=se)
        return sTree[i];
    int mid = (ss+se)/2;
    return getSum(qs, qe, ss, mid, 2*i+1) + getSum(qs, qe, mid+1, se, 2*i+2);
}

//diff - current value - previous value
void UpdateValue(int ss, int se, int i, int diff)
{
    if(ss>i || se<i)
        return;
    sTree[i] += diff;
    if(ss<se)
    {
        int mid = (ss+se)/2;
        UpdateValue(ss, mid, 2*i+1, diff);
        UpdateValue(mid+1, se, 2*i+2, diff); 
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    sTree = new int[4*n];
    buildSTree(arr, 0, n-1, 0);
    for(int i=0;i<4*n;i++)
        cout<<sTree[i]<<" ";
    return 0;
}