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

int main()
{
    int arr[] = {2,4,6,3,5,7,9,2,43,6,9,1,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,len);
    for(int i=0; i<len; i++)
    cout<<arr[i]<<" ";
    return 0;
}