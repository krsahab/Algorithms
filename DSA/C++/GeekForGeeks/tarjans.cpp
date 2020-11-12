#include<iostream> 
#include <list> 
#include <stack> 
#define NIL -1 
using namespace std; 
  
// A class that represents an directed graph 
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // A dynamic array of adjacency lists 
  
    // A Recursive DFS based function used by SCC() 
    void SCCUtil(int u, int disc[], int low[], 
                 stack<int> *st, bool stackMember[]); 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // function to add an edge to graph 
    void SCC();    // prints strongly connected components 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
} 
  
// A recursive function that finds and prints strongly connected 
// components using DFS traversal 
// u --> The vertex to be visited next 
// disc[] --> Stores discovery times of visited vertices 
// low[] -- >> earliest visited vertex (the vertex with minimum 
//             discovery time) that can be reached from subtree 
//             rooted with current vertex 
// *st -- >> To store all the connected ancestors (could be part 
//           of SCC) 
// stackMember[] --> bit/index array for faster check whether 
//                  a node is in stack 
void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st, 
                    bool stackMember[]) 
{ 
    static int time=0;
    disc[u]=low[u]=++time;
    st->push(u);
    stackMember[u] = true;
    for(auto i : adj[u])
    {
        if(disc[i]==NIL)
        {
            SCCUtil(i,disc,low,st,stackMember);
            low[u] = min(low[u],low[i]);

        }
        if(stackMember[i])
        {
            low[u] = min(low[u],disc[i]);
        }
    }

    int w=0;
    if(disc[u]==low[u])
    {
        while (st->top()!=u)
        {
            w = st->top();
            st->pop();
            stackMember[w] = false;
            cout<<w<<" ";
        }
        w = st->top();
        st->pop();
        stackMember[w] = false;
        cout<<w<<" ";
    }
} 
  
// The function to do DFS traversal. It uses SCCUtil() 
void Graph::SCC() 
{ 
    int *disc = new int[V];
    int *low = new int[V];
    bool *isstack = new bool[V];
    stack<int> *st = new stack<int>();
    for(int i=0;i<V;i++)
    {
        isstack[i] = false;
        disc[i] = NIL;
        low[i] = NIL;
    }
    for(int i=0;i<V;i++)
    {
        if(disc[i]==NIL)
        SCCUtil(i,disc,low,st,isstack);
    }
} 
  
// Driver program to test above function 
int main() 
{ 
    cout << "\nSCCs in first graph \n"; 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.SCC(); 
  
    cout << "\nSCCs in second graph \n"; 
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.SCC(); 
  
    cout << "\nSCCs in third graph \n"; 
    Graph g3(7); 
    g3.addEdge(0, 1); 
    g3.addEdge(1, 2); 
    g3.addEdge(2, 0); 
    g3.addEdge(1, 3); 
    g3.addEdge(1, 4); 
    g3.addEdge(1, 6); 
    g3.addEdge(3, 5); 
    g3.addEdge(4, 5); 
    g3.SCC(); 
  
    cout << "\nSCCs in fourth graph \n"; 
    Graph g4(11); 
    g4.addEdge(0,1);g4.addEdge(0,3); 
    g4.addEdge(1,2);g4.addEdge(1,4); 
    g4.addEdge(2,0);g4.addEdge(2,6); 
    g4.addEdge(3,2); 
    g4.addEdge(4,5);g4.addEdge(4,6); 
    g4.addEdge(5,6);g4.addEdge(5,7);g4.addEdge(5,8);g4.addEdge(5,9); 
    g4.addEdge(6,4); 
    g4.addEdge(7,9); 
    g4.addEdge(8,9); 
    g4.addEdge(9,8); 
    g4.SCC(); 
  
    cout << "\nSCCs in fifth graph \n"; 
    Graph g5(5); 
    g5.addEdge(0,1); 
    g5.addEdge(1,2); 
    g5.addEdge(2,3); 
    g5.addEdge(2,4); 
    g5.addEdge(3,0); 
    g5.addEdge(4,2); 
    g5.SCC(); 
  
    return 0; 
} 