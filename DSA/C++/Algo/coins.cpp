#include<bits/stdc++.h>
using namespace std;
// int ways(int *arr, int n, int sum)
// {
//     if(sum==0)
//     return 1;
//     if(n==0)
//     return 0;
//     int res = ways(arr,n-1,sum);
//     if(arr[n-1]<=sum)
//     res = res+ways(arr,n,sum-arr[n-1]);
//     return res;
// }

int ways(int *arr, int n, int sum)
{
    int tab[sum+1][n+1];
    for(int i=0;i<=n;i++)
        tab[0][i] = 1;
    for(int i=1; i<=sum;i++)
        tab[i][0] = 0;
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            tab[i][j] = tab[i][j-1];
            if(arr[j-1]<=i)
            tab[i][j] += tab[i-arr[j-1]][j];
        }
    }
    return tab[sum][n];
}

int main()
{
    int arr[] = {2,5,3,6};
    cout<<ways(arr,4,10);
    return 0;
}