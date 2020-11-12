#include<bits/stdc++.h>

using namespace std;

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void bubble_sort(int *arr, int len)
{
    while (len)
    {
        for (int i = 0; i < len-1; i++)
        {
            if(arr[i]>arr[i+1])
            swap(&arr[i],&arr[i+1]);
        }
        len--;
    }
    
}

void merge(int *arr1, int *arr2, int l1, int l2)
{
    for (int i=0; i<l1; i++)
    {
        int n1 = arr1[0];
        int n2 = arr2[0];
        if(arr1[i]>arr2[0])
        {
            swap(&arr1[i],&arr2[0]);
            bubble_sort(arr2,l2);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l1,l2;
        cin>>l1;
        cin>>l2;
        int arr1[l1];
        int arr2[l2];
        for(int i=0;i<l1;i++)
        cin>>arr1[i];
        for(int j=0;j<l2;j++)
        cin>>arr2[j];
        merge(arr1,arr2,l1,l2);
        for(int i=0;i<l1;i++)
        cout<<arr1[i]<<" ";
        for(int j=0;j<l2;j++)
        cout<<arr2[j]<<" ";
        cout<<endl;
    }
    return 0;
}