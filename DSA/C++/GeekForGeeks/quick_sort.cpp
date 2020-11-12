#include<bits/stdc++.h>

using namespace std;

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int partition(int *arr,int s,int e)
{
    int pivot = arr[e];
    int r=e-1;
    for (int i = s; i <= r; i++)
    {
        if (arr[i]>pivot)
        {
            while (arr[r]>pivot && r>i)
                 r--;
            swap(&arr[i],&arr[r]);
        }
    }
    swap(&arr[r],&arr[e]);
    return r;
}

void quicksort(int *arr, int s, int e)
{
    if(s<e)
    {
        int p = partition(arr,s,e);
        quicksort(arr,s,p-1);
        quicksort(arr,p+1,e);
    }
}
int main()
{
    int arr[] = {2,3,4,8,0,1,3,5,7,8,90,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,len-1);
    for(int i=0; i<len; i++)
    cout<<arr[i]<<" ";
    return 0;
}