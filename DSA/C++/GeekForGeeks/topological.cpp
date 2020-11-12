#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph
{
    int vertex;
    list <int> *adjecencylist;
    bool *visited;
    vector <int> indegree;
    public:
    graph(int ver)
    {
        vertex = ver;
        adjecencylist = new list <int> [ver];
        visited = new bool[ver];
        for(int i=0; i<vertex;i++)
        {
            visited[i] = false;
            indegree.push_back(0);
        }
    }
    void add_edge(int src, int des)
    {
        adjecencylist[src].push_back(des);
        indegree[des]++;
    }
    void topological(vector<int> result)
    {
        for(auto i : result)
        {
            if(indegree[i]==0 && !visited[i])
            {
                cout<<"visited: "<<i<<endl;
                visited[i] = true;
                result.erase(result.begin());
                for(auto ver: adjecencylist[i])
                {
                    result.push_back(ver);
                    indegree[ver]--;
                }
            }
        }
        topological(result);
    }
    void call_topological()
    {
        vector<int> res;
        for(int i=0;i<vertex;i++)
        {
            if(indegree[i]==0)
            {
                res.push_back(i);
            }
        }
        topological(res);
    }
};

int main()
{
    graph g(6);
    g.add_edge(5, 2); 
    g.add_edge(5, 0); 
    g.add_edge(4, 0); 
    g.add_edge(4, 1); 
    g.add_edge(2, 3); 
    g.add_edge(3, 1); 
    g.call_topological();
    return 0; 
}