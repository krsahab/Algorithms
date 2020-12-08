#include<bits/stdc++.h>
using namespace std;


int min_coin(int *coin, int n, int value)
{
    if(value==0)
    return 0;
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(coin[i]<=value)
        {
        int sres = min_coin(coin,n,value-coin[i]);
        if(sres!=INT_MAX)
        res=min(res,sres+1);
        }
    }
    return res;
}
int main()
{
    int coin[] = {25,10,5};
    cout<<min_coin(coin,3,30);
    return 0;
}