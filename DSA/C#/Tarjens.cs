using System;
using System.Collections.Generic;

namespace ConsoleApp4
{
    class Program
    {
        static Stack<int> output = new Stack<int>();
        static int dis = 0;
        static bool[] visited;
        static bool[] parent;
        static int[] discovery;
        static int[] lowValue;

        static void dfs(List<int>[] graph, int node)
        {
            visited[node] = true;
            discovery[node] = ++dis;
            lowValue[node] = dis;
            output.Push(node);
            parent[node] = true;
            foreach (var item in graph[node])
            {
                if (!visited[item])
                {
                    dfs(graph, item);
                    if (lowValue[item] < lowValue[node])
                        lowValue[node] = lowValue[item];
                }
                else
                {
                    if (parent[item] && lowValue[item] < lowValue[node])
                        lowValue[node] = lowValue[item];
                }
            }
            if (lowValue[node]==discovery[node])
            {
                while(output.Count>0 && output.Peek()!=node)
                {
                    parent[output.Peek()]=false;
                    Console.Write(output.Pop() + " ");
                }
                parent[output.Peek()] = false;
                Console.Write(output.Pop()+",");
            }
        }
        static void ConnectedComponent(List<int>[] graph)
        {
            int ver = graph.Length;
            visited = new bool[ver];
            parent = new bool[ver];
            discovery = new int[ver];
            lowValue = new int[ver];
            for (int i = 0; i < ver; i++)
            {
                if (!visited[i])
                {
                    dfs(graph, i);
                }
            }
        }

        static void Main(string[] args)
        {
            int t = Convert.ToInt32(Console.ReadLine());
            while (t-- > 0)
            {
                output.Clear();
                int[] inp = Array.ConvertAll(Console.ReadLine().Trim().Split(), x => Convert.ToInt32(x));
                int v = inp[0];
                int e = inp[1];
                int[] edge = Array.ConvertAll(Console.ReadLine().Trim().Split(), x => Convert.ToInt32(x));
                List<int>[] graph = new List<int>[v];
                for (int i = 0; i < v; i++)
                    graph[i] = new List<int>();
                for (int i = 0; i < edge.Length; i += 2)
                {
                    graph[edge[i]].Add(edge[i + 1]);
                }
                ConnectedComponent(graph);
                Console.WriteLine();
            }
        }
    }
}
