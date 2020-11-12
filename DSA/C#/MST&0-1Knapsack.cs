using System;
using System.Linq;
using System.Collections.Generic;
public class GFG
{
    static public int maxValue(int[] wt, int[] val, int W, int N)
    {
        int[,] result = new int[W+1,N+1];
        for (int i = 0; i <= W; i++)
        {
            for (int j = 0; j <= N; j++)
            {
                if (i == 0 || j == 0)
                    result[i, j] = 0;
                else
                {
                    if (wt[j-1] <= i)
                        result[i, j] = Math.Max(result[i, j - 1], val[j-1] + result[i - wt[j-1], j - 1]);
                    else
                        result[i, j] = result[i, j - 1];
                }

            }
        }
        return result[N, N];
        //if (W == 0 || N == 0)
        //{
        //    return 0;
        //}

        //if (wt[N - 1] <= W)
        //{
        //    return Math.Max(val[N - 1] + maxValue(wt, val, W - wt[N - 1], N - 1), maxValue(wt, val, W, N - 1));
        //}

        //return maxValue(wt, val, W, N - 1);
    }

    static public int MST(int[,] adj,int n)
    {
        bool[] set = new bool[n];
        int[] distance = Enumerable.Repeat(int.MaxValue,n).ToArray();
        distance[0] = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int t = -1;
            int min = int.MaxValue;
            for (int j = 0; j < n; j++)
            {
                if (set[j]==false && (t==-1||distance[j]<min))
                {
                    min = distance[j];
                    t = j;
                }
            }
            res += distance[t];
            set[t] = true;
            for (int j = 0; j < n; j++)
            {
                if (set[j]==false && adj[t,j]>0 && distance[j]>adj[t,j])
                {
                    distance[j] = adj[t, j];
                }
            }
        }
        return res;
    }
    static public void Main()
    {
        int t = Convert.ToInt32(Console.ReadLine());
        while (t-- > 0)
        {
            int N = Convert.ToInt32(Console.ReadLine());
            int W = Convert.ToInt32(Console.ReadLine());
            int[] val = Array.ConvertAll(Console.ReadLine().Trim().Split(), x => Convert.ToInt32(x));
            int[] wt = Array.ConvertAll(Console.ReadLine().Trim().Split(), x => Convert.ToInt32(x));
            Console.WriteLine(maxValue(wt, val, W, N));
        }
    }
}