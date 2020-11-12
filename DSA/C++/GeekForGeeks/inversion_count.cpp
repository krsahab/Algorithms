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

int merge_count(int *arr, int s, int m, int e)
{
    int count = 0;
    for (int p = m+1; p <= e; p++)
    {
        for (int q = s; q <= m; q++)
        {
            if (arr[q]>arr[p])
            {
                count+=(m-q+1);
                break;
            }
            
        }
    }
    merge(arr,s,m,e);
    return count;
}

int inversions(int *arr, int s, int e)
{
    int counts = 0;
    if(s<e)
    {
        int m = s+(e-s)/2;
        counts+=inversions(arr,s,m);
        counts+=inversions(arr,m+1,e);
        counts+=merge_count(arr,s,m,e);
        for(int i=s;i<=e;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    }
    return counts;
}

int main()
{
    int arr[] = {2,4,1,3,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    int count = inversions(arr,0,len-1);
    cout<<"Inversion Count = "<<count;
    return 0;
}