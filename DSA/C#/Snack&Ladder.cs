using System;
using System.Collections.Generic;

namespace ConsoleApp2
{
    internal class Program
    {
        private static int minAttempt(List<int>[] graph)
        {
            Queue<int> q = new Queue<int>();
            q.Enqueue(1);
            int res = 0;
            bool[] visited = new bool[31];
            visited[1] = true;
            while (q.Count > 0)
            {
                int temp = q.Count;
                for (int i = 0; i < temp; i++)
                {
                    int t = q.Dequeue();
                    if (t == 30)
                        return res;
                    foreach (var item in graph[t])
                    {
                        if (item == 30)
                            return res + 1;
                        if (visited[item] == false)
                        {
                            q.Enqueue(item);
                            visited[item] = true;
                        }
                    }
                }
                res++;
            }
            return res;
        }

        private static void Main(string[] args)
        {
            int t = Convert.ToInt32(Console.ReadLine());
            while (t-- > 0)
            {
                int l = Convert.ToInt32(Console.ReadLine());
                int[] arr = Array.ConvertAll(Console.ReadLine().Trim().Split(), x => Convert.ToInt32(x));
                List<int>[] graph = new List<int>[31];
                Dictionary<int, int> edge = new Dictionary<int, int>();
                for (int i = 0; i < arr.Length; i += 2)
                    edge.Add(arr[i], arr[i + 1]);
                for (int i = 0; i < 30; i++)
                {
                    graph[i] = new List<int>();
                    if (edge.ContainsKey(i))
                        continue;
                    for (int j = 1; j <= 6; j++)
                        if (i + j <= 30)
                            if (edge.ContainsKey(i + j))
                                graph[i].Add(edge[i + j]);
                            else
                                graph[i].Add(i + j);
                }
                Console.WriteLine(minAttempt(graph));
            }
        }
    }
}
