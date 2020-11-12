#include<bits/stdc++.h>

using namespace std;

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void bubble_sort(int *arr, int s, int e)
{
    int i=s;
    while (arr[i]>arr[i+1] && i<e)
    {
        swap(&arr[i],&arr[i+1]);
        i++;
    }

}

void merge(int *arr, int s, int m, int e)
{
    for (int i=s; i<=m; i++)
    {
        if(arr[i]>arr[m+1])
        {
            swap(&arr[i],&arr[m+1]);
            bubble_sort(arr,m+1,e);
        }
    }
}

void mergesort(int *arr, int s, int e)
{
    if (s<e)
    {
        int m = s+(e-s)/2;
        mergesort(arr,s,m);
        mergesort(arr,m+1,e);
        merge(arr,s,m,e);
    }
}

int main()
{
    int arr[] = {45,6,3,2,4,6,9,87,6,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,len-1);
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}