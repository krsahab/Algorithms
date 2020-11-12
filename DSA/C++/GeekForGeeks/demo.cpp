#include<bits/stdc++.h>
using namespace std;

vector<int> cellCompete(int* states, int days) 
{
    int pre=0,next,curr;
    vector<int> v;
    int n = sizeof(states);
    for(int j=0;j<days;j++)
    {
        for(int i=0;i<n;i++)
        {
            curr = states[i];
            if(i==n-1)
            next = 0;
            else
            next = states[i+1];
            if(pre==next)
            {
                states[i] = 0;
            }
            else
            {
                states[i] = 1;
            }
            pre = curr;
        }
    }
    for(int i=0;i<n;i++)
    v.push_back(states[i]);
    return v;
}

int main()
{
    int arr[] = {0,1,0,0,0,1,1,0,1,0,1 };
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v = cellCompete(arr,2);
    for(auto i: v)
    cout<<i<<" ";
    return 0;
}