#include<bits/stdc++.h>
using namespace std;

// int ks(int *v, int *w, int n, int wt)
// {
//     if(n==0||wt==0)
//     return 0;
//     if(w[n-1]>wt)
//     return ks(v,w,n-1,wt);
//     return max(ks(v,w,n-1,wt),ks(v,w,n-1,wt-w[n-1])+v[n-1]);
// }

int ks(int *v, int *w, int n, int wt)
{
    int dp[n+1][wt+1];
    for(int i=0;i<=wt;i++)
    dp[0][i]=0;
    for(int i=0;i<=n;i++)
    dp[i][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=wt;j++)
        {
            if(w[i-1]>j)
            dp[i][j] = dp[i-1][j];
            else
            dp[i][j] = max(dp[i-1][j],v[i-1]+dp[i-1][j-w[i-1]]);
        }
    }
    return dp[n][wt];
}

int main()
{
    int v[] = {10,40,30,50};
    int w[] = {5,4,6,3};
    cout<<ks(v,w,4,10);
    return 0;
}