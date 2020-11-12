#include<bits/stdc++.h>
using namespace std;

int findMinCoin(int num, int coins[], int s)
{
    if(s==0)
    return 0;
    if(num==0)
    return 1;
    if(coins[s-1]<=num)
    {
        int res = 1+findMinCoin(num-coins[s-1],coins,s)
    }
    return 1+findMinCoin(num-coins[s-1],coins,s),findMinCoin(num,coins,s-1));
    else
    return findMinCoin(num,coins,s-1);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int s;
        cin>>s;
        int coins[s];
        for(int i=0;i<s;i++)
        cin>>coins[i];
        int num;
        cin>>num;
        sort(coins,coins+s);
        cout<<findMinCoin(num,coins,s)<<endl;
    }
    return 0;
}