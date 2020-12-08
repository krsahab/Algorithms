#include<bits/stdc++.h>
using namespace std;
// int lis(int *arr, int len)
// {
//     int l[len];
//     l[0] = 1;
//     for (int i = 1; i < len; i++)
//     {
//         l[i] = 1;
//         for (int j = 0; j < i; j++)
//         {
//             if (arr[j]<arr[i])
//             {
//                 l[i] = max(l[i],1+l[j]);
//             }
//         }
//     }
//     int res = l[0];
//     for (int i = 0; i < len; i++)
//     {
//         res = max(res,l[i]);
//     }
//     return res;
// }
int ceil(int *arr, int l, int r, int x)
{
    while(l<r)
    {
        int m = l+(r-l)/2;
        if(arr[m]>=x)
        r=m;
        else
        l=m+1;
    }
    return r;
}

int lis(int *arr, int len)
{
    int l[len];
    l[0] = arr[0];
    int p = 0;
    for (int i = 1; i < len; i++)
    {
        if (arr[i]>l[p])
            l[++p] = arr[i];
        else if(arr[i]<l[p])
        l[ceil(l,0,p,arr[i])] = arr[i];
    }
    return p+1;
}

int main()
{
    int arr[] = {3,4,2,8,10,5,1};
    cout<<lis(arr,7);
    return 0;
}