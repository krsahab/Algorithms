#include<bits/stdc++.h>
using namespace std;
int minjump(int arr[], int n)
{
    int res[n];
    res[0]=0;
    for(int i=1;i<n;i++)
    {
        res[i] = INT_MAX;
        for(int j=i-1;j>=0;j--)
        {
            if(res[j]!=INT_MAX && arr[j]+j>=i)
            {
                res[i] = min(res[i],1+res[j]);
            }
        }
    }
    return res[n-1];
}

int minimumJumps(int arr[], int n){
    int res = minjump(arr,n);
    if(res!=INT_MAX)
    return res;
    return -1;
}

int main()
{
    int arr[] = {0,1,1,1,1};
    int n=5;
    cout<<minimumJumps(arr,n);
    return 0;
}