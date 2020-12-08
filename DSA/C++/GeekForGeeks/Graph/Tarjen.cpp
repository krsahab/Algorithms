#include<bits/stdc++.h>
#define NIL -1
using namespace std;

stack<int> output;
bool *visited;
int *low;
int *discovery;
bool *rec;

void tarjens(int node, vector<int> adj[], int N)
{
    static int counter = 0;
    discovery[node] = low[node] = ++counter;
    visited[node] = true;
    rec[node] = true;
    output.push(node);
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[i])
        {
            tarjens(i, adj, N);
            low[node] = min(low[node], low[i]);
        }
        else if(rec[i])
            low[node] = min(low[node], low[i]);
        
        if(discovery[node] == low[node])
        {
            while (!output.empty() && output.top()!=node)
            {
                cout<<output.top()<<" ";
                rec[output.top()] = false;
                output.pop();
            }
            cout<<output.top()<<",";
            rec[output.top()] = false;
            output.pop();
        }
    }
    
}

void find(vector<int> adj[], int N) {
    visited = new bool[N];
    low = new int[N];
    discovery = new int[N];
    rec = new bool[N];
    for (int i = 0; i < N; i++)
    {
        low[i] = INT_MAX;
        discovery[i] = INT_MAX;
    }
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            tarjens(i, adj, N);
        }
        
    }
    
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n, m;
        cin>>n>>m;
        vector<int> adj[n+1];
        for (int i = 0; i < m; i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
        find(adj, n);
        cout<<"\n";
    }
    
    return 0;
}