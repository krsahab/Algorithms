#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void sort(int *arr, int len)
{
    int m = 0;
    int e = len-1;
    for (int i = 0; i < len; i++)
    {
        top:
        if (arr[i]==1)
        {
            continue;
        }
        if (arr[i]==2)
        {
            while(arr[i]==arr[e] && i<e)
                e--;
            if(i==e)
            break;
            swap(&arr[i],&arr[e--]);
            goto top;
        }
        if (arr[i]==0)
        {
            if(arr[i]==arr[m])
            {
                m++;
                continue;
            }
            swap(&arr[i],&arr[m++]);
        }
    }
}

int main()
{
    int arr[] = {0,1,2,0,0,2,2,1,1,2};
    int len = sizeof(arr)/sizeof(arr[0]);
    sort(arr,len);
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}