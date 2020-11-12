#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void add_edge(vector<int> vect[], int u, int v)
{
    vect[u].push_back(v);
    vect[v].push_back(u);
}

void printgraph(vector<int> vect[], int v)
{
    for(int i=0;i<v;i++)
    {
        cout<<"adjecency list of vertex "<<i<<"\n head ";
        for(auto x : vect[i])
        {
            cout<<"->"<<x;
        }
        cout<<endl;
    }
}
int main()
{
    int size = 5;
    vector<int> v[size];
    add_edge(v, 0, 1); 
    add_edge(v, 0, 4); 
    add_edge(v, 1, 2); 
    add_edge(v, 1, 3); 
    add_edge(v, 1, 4); 
    add_edge(v, 2, 3); 
    add_edge(v, 3, 4); 
    printgraph(v, size); 
    return 0; 
}