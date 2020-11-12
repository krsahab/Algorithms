#include<iostream>
#include<bits/stdc++.h>
#include<list>
using namespace std;

class graph
{
    int ver;
    list <int> *vertices;
    bool *visited;
    public:
    graph(int v)
    {
        ver = v;
        vertices = new list<int> [v];
    }
    void add_edge(int src, int des)
    {
        vertices[src].push_back(des);
        vertices[des].push_back(src);
    }
    void bfs(int index)
    {
        visited = new bool[ver];
        for(int i=0;i<ver;i++)
        {
            visited[i] = false;
        }
        list<int> q;
        visited[index] = true;
        q.push_back(index);
        list<int>::iterator i;
        while(!q.empty())
        {
            int currvertex = q.front();
            cout<<currvertex<<" is visited"<<endl;
            q.pop_front();
            for(i = vertices[currvertex].begin(); i!=vertices[currvertex].end(); i++)
            {
                int adjvertext = *i;
                if(!visited[adjvertext])
                {
                    visited[adjvertext] = true;
                    q.push_back(adjvertext);
                }
            }
        }
    }
};
int main()
{
    graph g(10);
    g.add_edge(0, 1); 
    g.add_edge(0, 4); 
    g.add_edge(1, 2); 
    g.add_edge(1, 3); 
    g.add_edge(1, 4); 
    g.add_edge(2, 3); 
    g.add_edge(3, 4); 
    g.bfs(1);
    return 0; 
}