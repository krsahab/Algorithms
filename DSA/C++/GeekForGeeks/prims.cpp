#include<bits/stdc++.h>
using namespace std;
#define V 5  

int minKey(int key[],bool visited[])
{
    int m = INT_MAX; int idx = 0;
    for(int i=0;i<V;i++)
    {
        if(!visited[i] && key[i]<m)
        {
            m = key[i];
            idx = i;
        }
    }
    return idx;
}

// void primMST(int g[V][V])
// {
//     bool visited[V];
//     int key[V] = {INT_MAX};
//     int result[V];

//     int k = 0;
//     key[0]=0;
//     result[0] = -1;
//     for (int j = 0; j < V; j++)
//     {
//         k = minind(key,visited);
//         visited[k] = true;
//             for(int i=0;i<V;i++)
//             {
//                 if(g[k][i]!=0 && !visited[i] && key[i]>g[k][i])
//                 {
//                     result[i]=k;
//                     key[i] = g[k][i];
//                 }
//             }
//     }
//     for(int i=0;i<V;i++)
//     {
//         cout<<result[i]<<" ";
//     }
// }

void primMST(int graph[V][V])  
{  
    // Array to store constructed MST  
    int parent[V];  
      
    // Key values used to pick minimum weight edge in cut  
    int key[V];  
      
    // To represent set of vertices not yet included in MST  
    bool mstSet[V];  
  
    // Initialize all keys as INFINITE  
    for (int i = 0; i < V; i++)  
        key[i] = INT_MAX, mstSet[i] = false;  
  
    // Always include first 1st vertex in MST.  
    // Make key 0 so that this vertex is picked as first vertex.  
    key[0] = 0;  
    parent[0] = -1; // First node is always root of MST  
  
    // The MST will have V vertices  
    for (int count = 0; count < V - 1; count++) 
    {  
        // Pick the minimum key vertex from the  
        // set of vertices not yet included in MST  
        int u = minKey(key, mstSet);  
  
        // Add the picked vertex to the MST Set  
        mstSet[u] = true;  
  
        // Update key value and parent index of  
        // the adjacent vertices of the picked vertex.  
        // Consider only those vertices which are not  
        // yet included in MST  
        for (int v = 0; v < V; v++)  
  
            // graph[u][v] is non zero only for adjacent vertices of m  
            // mstSet[v] is false for vertices not yet included in MST  
            // Update the key only if graph[u][v] is smaller than key[v]  
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])  
                parent[v] = u, key[v] = graph[u][v];  
    }  
  
    // print the constructed MST  
    for(int i=0;i<V;i++)
     {
         cout<<parent[i]<<" ";
     }
}  

int main()  
{ 
    int graph[V][V] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } }; 
    primMST(graph);  
    return 0;  
}  
