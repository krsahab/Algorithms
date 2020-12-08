#include<bits/stdc++.h>
using namespace std;

// int min_jump(int *arr, int n)
// {
//     int res = INT_MAX;
//     if(n==1)
//     return 0;
//     for (int i = 0; i < n-1; i++)
//     {
//         if (i+arr[i]>=n-1)
//         {
//             int sub_res = min_jump(arr,i+1);
//             if(sub_res!=INT_MAX)
//             res = min(res,sub_res+1);
//         }
        
//     }
//     return res;
// }

int min_jump(int *arr, int n)
{
    int dp[n];
    dp[0] = 0;
    for(int i=1;i<n;i++)
    dp[i] = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(arr[j]+j>=i)
            {
                if(dp[j]!=INT_MAX)
                dp[i] = min(dp[j]+1,dp[i]);
            }
        }
        
    }
    return dp[n-1];
}
int main()
{
    int arr[] = {3,4,2,1,2,1};
    cout<<min_jump(arr,6);
    return 0;
}