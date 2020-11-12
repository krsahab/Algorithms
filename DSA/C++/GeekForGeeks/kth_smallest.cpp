#include<bits/stdc++.h>
#include<climits>

using namespace std;

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

// int partition(int *arr,int s,int e)
// {
//     int pivot = arr[e];
//     int r=e-1;
//     for (int i = s; i <= r; i++)
//     {
//         if (arr[i]>pivot)
//         {
//             while (arr[r]>pivot && r>i)
//                  r--;
//             swap(&arr[i],&arr[r]);
//         }
//     }
//     swap(&arr[r],&arr[e]);
//     return r;
// }

int partition(int arr[], int l, int r) 
{ 
    int x = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 

int kth_smallest(int *arr, int s, int e, int k)
{
    if(k>0 && k<=e-s+1)
    {
        int p = partition(arr,s,e);
        if (p-s==k-1)
        return arr[p];
        if(p-s<k-1)
        return kth_smallest(arr,p+1,e,k-(p-s+1));
        else
        return kth_smallest(arr,s,p-1,k);
    }
    return INT_MAX;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int len = sizeof(arr)/sizeof(arr[0]);
    int k=9;
    int kth = kth_smallest(arr, 0, len-1, k);
    cout<<kth;
    return 0;
}