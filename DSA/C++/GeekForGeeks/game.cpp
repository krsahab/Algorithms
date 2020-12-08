#include<bits/stdc++.h>
using namespace std;

// int opt(int *arr, int s, int e, int sum)
// {
//     if(e==s+1)
//     return max(arr[e], arr[s]);
//     else
//     return max(sum-opt(arr,s+1,e,sum-arr[s]),sum-opt(arr,s,e-1,sum-arr[e]));
// }

int opt(int *arr, int s, int e)
{
    if(e==s+1)
    return max(arr[e], arr[s]);
    else
    return max(arr[s]+min(opt(arr,s+2,e),opt(arr,s+1,e-1)),arr[e]+min(opt(arr,s,e-2),opt(arr,s+1,e-1)));
}

int main()
{
    int arr[] = {20,5,4,6};
    int sum=0;
    for(int i=0;i<4;i++)
    sum=sum+arr[i];
    cout<<opt(arr,0,3);
    return 0;
}