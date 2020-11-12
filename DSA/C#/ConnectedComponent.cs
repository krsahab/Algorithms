using System;
using System.Collections.Generic;

namespace ConsoleApp3
{
    class Program
    {
        static Stack<int> st = new Stack<int>();
        static List<int>[] rgraph;
        static void dfs(List<int>[] graph, int node, bool[] visited, bool rev)
        {
            visited[node] = true;
            foreach (var item in graph[node])
            {
                if (!visited[item])
                    dfs(graph, item, visited, rev);
            }
            if (!rev)
                st.Push(node);
        }

        static void Reverse(List<int>[] graph)
        {
            rgraph = new List<int>[graph.Length];
            for (int i = 0; i < graph.Length; i++)
                rgraph[i] = new List<int>();
            for (int i = 0; i < graph.Length; i++)
            {
                foreach (var item in graph[i])
                {
                    rgraph[item].Add(i);
                }
            }
        }
        static void ConnectedComponent(List<int>[] graph, int v)
        {
            bool[] visited = new bool[v];
            for (int i = 0; i < v; i++)
            {
                if (!visited[i])
                    dfs(graph, i, visited, false);
            }
            Reverse(graph);
            visited = new bool[v];
            while (st.Count > 0)
            {
                dfs(rgraph, st.Peek(), visited, true);
                while (st.Count>0 && visited[st.Peek()])
                {
                    Console.Write(st.Peek() + " ");
                    st.Pop();
                }
                Console.Write(",");
            }
        }
        static void Main(string[] args)
        {
            int t = Convert.ToInt32(Console.ReadLine());
            while (t-- > 0)
            {
                st.Clear();
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
                ConnectedComponent(graph, v);
                Console.WriteLine();
            }
        }
    }
}
