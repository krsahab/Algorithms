#include<bits/stdc++.h>
using namespace std;

int knap(int *val, int *wt, int len, int total)
{
    if(total==0 || len<0)
    return 0;
    if(wt[len]<=total)
    return max(val[len]+knap(val,wt,len-1,total-wt[len]),knap(val,wt,len-1,total));
    return knap(val,wt,len-1,total);
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int len;
        cin>>len;
        int total;
        cin>>total;
        int *val = new int[len];
        int *wt = new int[len];
        for(int i=0;i<len;i++)
        {
            cin>>val[i];
        }
        for (int i = 0; i < len; i++)
        {
            cin>>wt[i];
        }
        cout<<knap(val,wt,len-1,total)<<endl;
    }
    
    return 0;
}