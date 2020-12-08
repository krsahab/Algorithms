#include<bits/stdc++.h>

using namespace std;

class graph
{
    int vertex;
    list<int> *adj;
    public:
    graph(int v)
    {
        vertex = v;
        adj = new list<int> [v];
    }
    void addEdge(int src, int des)
    {
        adj[src].push_back(des);
    }
    void topologicalutil(int v, bool visited[], stack<int> &s)
    {
        visited[v] = true;
        list<int>::iterator i;
        for (i = adj[v].begin(); i!=adj[v].end(); i++)
        {
            if(!visited[*i])
            topologicalutil(*i,visited,s);
        }
        s.push(v);
    }
    void calltopological()
    {
        stack<int> s;
        bool  *visited = new bool[vertex];
        for (int i = 0; i < vertex; i++)
        {
            visited[i] = false;
        }
        for (int i = 0; i < vertex; i++)
        {
            if(visited[i]==false)
            topologicalutil(i,visited,s);
        }
        while (s.empty()==false)
        {
            cout<<s.top()<<endl;
            s.pop();
        }
    }

};
int main()
{
    graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given graph \n"; 
    g.calltopological(); 
  
    return 0; 
}