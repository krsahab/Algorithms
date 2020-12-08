#include<bits/stdc++.h>
using namespace std;

int *parent;
int *rankArr;

struct Edge
{
    int source;
    int destination;
    int weight;
    Edge(int s, int d, int w)
    {
        this->source = s;
        this->destination = d;
        this->weight = w;
    }
};

bool myComp(Edge *e1, Edge *e2)
{
    return e1->weight<e2->weight;
}

int find(int x)
{
    if(parent[x]==x)
        return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void Union(int a, int b)
{
    int p1 = parent[a];
    int p2 = parent[b];
    if(rankArr[p1]<rankArr[p2])
        parent[p1] = p2;
    if(rankArr[p1]>rankArr[p2])
        parent[p2] = p1;
    else
    {
        parent[p2] = p1;
        rankArr[p1]++;
    }
}

int MST(vector<Edge> &graph, int V)
{
    sort(graph.begin(), graph.end(), myComp);
    int res = 0;
    for (int i = 0, s = 0; s < V-1; i++)
    {
        int p1 = find(graph[i].destination);
        int p2 = find(graph[i].source);
        if(p1 == p2)
            continue;
        res+=graph[i].weight;
        Union(p1, p2);
        s++;
    }
    return res;
}

int main()
{
    int n;
    parent = new int[n];
    rankArr = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rankArr[i] = 0;
    }
    return 0;
}