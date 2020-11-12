#include<bits/stdc++.h>
using namespace std;


bool isCyclicUtil(int v, bool visited[], vector<int> adj[], int parent) 
{ 
    visited[v] = true;
    for (auto i:adj[v]) 
    { 
        if (!visited[i]) 
        { 
            if(isCyclicUtil(i, visited, adj, v))
            return true;
        } 
        else if (i == 0 && parent !=0) 
        return true;
    } 
    return false; 
} 
string machine_tunnel(int n , int m , vector<int> graph[] )
{
    if(m<n)
    return "NO";
    bool *visited = new bool[n]; 
    for (int i = 0; i < n; i++)
    {
        if(graph[i].size()==0)
        return "NO";
    }
    
    for (int i = 0; i < n; i++) 
        visited[i] = false; 
    if (isCyclicUtil(0, visited, graph, -1)) 
    {
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            return "NO";
        }
        return "YES";
    }
    return "NO";
}

int main()
{

    vector<int> grp[3];
    for(int i=0;i<3;i++)
    {
        grp[0].push_back(1);
        grp[1].push_back(2);
        //grp[2].push_back(3);
        grp[2].push_back(0);  
    }
    cout<<machine_tunnel(3,3,grp);

    return 0;
}