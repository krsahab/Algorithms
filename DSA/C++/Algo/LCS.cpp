#include<bits/stdc++.h>
using namespace std;

// int lcs(string s1, string s2, int n1, int n2)
// {
//     if(n1==0||n2==0)
//     return 0;
//     if (s1[n1-1]==s2[n2-1])
//     {
//         return 1 + lcs(s1,s2,n1-1,n2-1);
//     }
//     return max(lcs(s1,s2,n1-1,n2),lcs(s1,s2,n1,n2-1));
    
// }

//memoization
// int memo[5][4];
// int lcs(string s1, string s2, int n1, int n2)
// {
//     if(memo[n1][n2]!=-1)
//     return memo[n1][n2];
//     if(n1==0||n2==0)
//     memo[n1][n2]=0;
//     else
//     {
//     if(s1[n1-1]==s2[n2-1])
//     memo[n1][n2] = 1+lcs(s1,s2,n1-1,n2-1);
//     else
//     memo[n1][n2] = max(lcs(s1,s2,n1-1,n2),lcs(s1,s2,n1,n2-1));
//     }
//     return memo[n1][n2];
// }

//tabulation
int lcs(string s1, string s2, int n1, int n2)
{
    int memo[n1+1][n2+1];
    for (int i = 0; i <= n1; i++)
        memo[i][0] = -1;
    for(int i=0;i<=n2;i++)
        memo[0][i] = -1;
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if(s1[n1-1]==s2[n2-1])
            memo[i][j]= 1+memo[i-1][j-1];
            else
            memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
        }
    }
    return memo[n1][n2];
}

int main()
{
    string s1 = "AXYZ";
    string s2 = "BAZ";
    int n1 = 4, n2 = 3;
    cout<<lcs(s1, s2, n1, n2);
    return 0;
}