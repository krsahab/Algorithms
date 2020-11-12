using System;
using System.Collections.Generic;

namespace ConsoleApp4
{
    class Program
    {
        static int ver;
        static int dis = 0;
        static bool[] visited = new bool[ver];
        static int[] parent = new int[ver];
        static int[] discovery = new int[ver];
        static int[] lowValue = new int[ver];
        static bool[] isArticulation = new bool[ver];

        static void dfs(List<int>[] graph, int node)
        {
            int child = 0;
            visited[node] = true;
            discovery[node] = ++dis;
            lowValue[node] = dis;
            foreach (var item in graph[node])
            {
                if (!visited[item])
                {
                    child++;
                    parent[item] = node;
                    dfs(graph, item);
                    if (lowValue[item] < lowValue[node])
                        lowValue[node] = lowValue[item];
                    if (parent[node]==-1 && child>1)
                        isArticulation[item] = true;
                    if (parent[node]!=-1 && lowValue[item] >= discovery[node])
                        isArticulation[item] = true;
                }
                else
                {
                    if (parent[node]!=item && lowValue[item] < lowValue[node])
                        lowValue[node] = lowValue[item];
                }
            }
        }
        static void ArticulationPoints(List<int>[] graph)
        {
            int v = graph.Length;

            for (int i = 0; i < v; i++)
            {
                if (!visited[i])
                {
                    parent[i] = -1;
                    dfs(graph, i);
                }
            }
        }

        static void Main(string[] args)
        {
            ver = 5;
            Console.WriteLine("Hello World!");
        }
    }
}
