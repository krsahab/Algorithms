#include <bits/stdc++.h>
using namespace std;

int Min_Time(int arr[], int n, int k)
{
    deque<int> dq[k];
    int sum[k]={0};
    int f = n/k;
    int c=0;
    int tsum = 0;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<f;j++)
        {
            if(c<n)
            {
                tsum+=arr[c];
                sum[i]+=arr[c];
                dq[i].push_back(arr[c++]);
            }
        }
    }
    int sf = tsum/k;
    int result = sum[0];
    for(int i=0;i<k-1;i++)
    {
        while(sf>sum[i]+dq[i+1].front() || sum[i]+dq[i+1].front()<sum[i+1])
        {
            dq[i].push_back(dq[i+1].front());
            dq[i+1].pop_front();
            sum[i]+=dq[i].back();
            sum[i+1]-=dq[i].back();
        }
        result = max(result,sum[i]);
    }
    return max(result,sum[k-1]);
}

int main()
{
    int arr[] = { 10, 10, 10, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout<<Min_Time(arr,n,k);
    return 0;
}