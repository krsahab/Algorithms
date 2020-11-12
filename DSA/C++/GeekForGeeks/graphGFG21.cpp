#include<bits/stdc++.h>
using namespace std;

int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
int ind[m]={0};
    vector<int> gr[n];
    for(auto i:dependency)
    {
        gr[i.first].push_back(i.second);
        ind[i.second]++;
    }
    bool visited[n] = {false};
    queue<int> v;
    for(int i=0;i<m;i++)
    {
        if(ind[i]==0)
        v.push(i);
    }
    int dur = 0;
    int mdur = 0;
    while(!v.empty())
    {
        int s = v.size();
        mdur=0;
        for(int it=0;it<s;it++)
        {
            int t = v.front();
            v.pop();
            visited[t] = true;
            for(auto i: gr[t])
            {
                ind[i]--;
                if(ind[i]==0)
                v.push(i);
            }
            mdur = max(mdur,duration[t]);
        }
        dur+=mdur;
    }
    return dur;
}

int main()
{
    vector<pair<int, int>> de = {{5, 2},{5, 0},{4, 0},{4, 1},{2, 3},{3, 1}};
    int du[] = {1, 2, 3, 1, 3, 2};
    cout<<minTime(de,du,6,6);
    return 0;
}