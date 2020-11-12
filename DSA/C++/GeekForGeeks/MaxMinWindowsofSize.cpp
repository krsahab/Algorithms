#include<bits/stdc++.h>
using namespace std;

vector <int> printMaxOfMin(int arr[], int N) {
    vector<int> ans(N+1,INT_MIN);
    int minvaluer[N];
    int minvaluel[N];
    stack<int> s;
    for(int i=0;i<N;i++)
    {
        while(!s.empty() && arr[s.top()]>=arr[i])
        s.pop();
        minvaluel[i] = s.empty()?-1:s.top();
        s.push(i);
    }
    while(!s.empty())
    s.pop();
    for(int i=N-1;i>=0;i--)
    {
        while(!s.empty() && arr[s.top()]>=arr[i])
        s.pop();
        minvaluer[i] = s.empty()?N:s.top();
        s.push(i);
    }
    for(int i=0;i<N;i++)
    {
        int len = minvaluer[i]-minvaluel[i]-1;
        ans[len] = ans[len]>arr[i]?ans[len]:arr[i];
    }
    for(int i=N-1;i>=1;i--)
    {
        ans[i] = ans[i]>ans[i+1]?ans[i]:ans[i+1];
    }
    return ans;
}

int main()
{
    int arr[] ={10,20,30,50,10,70,30};
    vector<int> res =printMaxOfMin(arr,7);
    for (int i = 1; i <= 7; i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}