#include<bits/stdc++.h>
using namespace std;

int ConnectRopes(vector<int>length, int n) 
{
    priority_queue<int,vector<int>,greater<int>> q(length.begin(),length.end());
    int t1,t2,t3,sum=0;
    while(q.size()>1)
    {
        t1 = q.top();
        q.pop();
        t2 = q.top();
        q.pop();
        t3 = t1+t2;
        sum+=t3;
        q.push(t3);
    }
    return sum;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(7);
    v.push_back(10);
    cout<<ConnectRopes(v,4);
    return 0;
}