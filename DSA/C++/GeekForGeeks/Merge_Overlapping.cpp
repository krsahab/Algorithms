#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct intervals
{
    int s, e;
};

bool mycomp(intervals i1, intervals i2)
{
    return (i1.s<i2.s);
}

int main()
{
    intervals arr[] = {{6,8}, {1,9}, {2,4}, {4,7}};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,mycomp);
    int p=0;
    for (int i = 1; i < n; i++)
    {
        if (arr[p].e>=arr[i].s)
        {
            arr[p].e = max(arr[p].e,arr[i].e);
        }
        else
        {
            arr[++p].s = arr[i].s;
            arr[p].e = arr[i].e;
        }
    }
    for (int j = 0; j <= p; j++)
    {
        cout<<arr[j].s<<" "<<arr[j].e<<endl;
    }
    
    return 0;
}