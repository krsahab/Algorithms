#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    vector<int> res(V,INT_MAX);
    bool visited[V];
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    res[0] = 0;
    visited[0] = true;
    for(int i=0;i<V;i++)
    {
        if(g[0][i]!=0)
        {
            pq.push(make_pair(g[0][i],i));
            res[i] = min(res[i],res[0]+g[0][i]);
        }
    }
    while(!pq.empty())
    {
        int ver = pq.top().second;
        int val = pq.top().first;
        visited[ver] = true;
        pq.pop();
        for(int i=0;i<V;i++)
        {
            if(g[ver][i]!=0)
            {
                if(!visited[i])
                pq.push(make_pair(g[ver][i],i));
                res[i] = min(res[i],res[ver]+g[ver][i]);
            }
        }
    }
    return res;
}

int main()
{
    vector<int> res;
    res = dijkstra(g,src,V);
    return 0;
}