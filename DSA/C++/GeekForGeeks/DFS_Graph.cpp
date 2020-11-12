#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph
{
    int vertex;
    list <int> *adjecencylist;
    bool *visited;
    public:
    graph(int ver)
    {
        vertex = ver;
        adjecencylist = new list <int> [ver];
        visited = new bool[ver];
        for(int i=0; i<vertex;i++)
        {
            visited[i] = false;
        }
    }
    void add_edge(int src, int des)
    {
        adjecencylist[src].push_back(des);
        adjecencylist[des].push_back(src);
    }
    void dfs(int ver)
    {
        visited[ver] = true;
        cout<<ver<<" visited"<<endl;
        for(auto i : adjecencylist[ver])
        {
            if(visited[i]==false)
            dfs(i);
        }
    }
};

int main()
{
    graph g(10);
    g.add_edge(0, 1); 
    g.add_edge(0, 2); 
    g.add_edge(1, 2); 
    g.add_edge(2, 0); 
    g.add_edge(2, 3); 
    g.add_edge(3, 3); 
    g.dfs(2);
    return 0; 
}