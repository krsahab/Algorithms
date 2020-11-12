using System;

namespace GeekCollectsBall
{
    class Program
    {
        static int TotalSum(int[] road1, int[] road2, int m, int n)
        {
            int i = 0, j = 0, sum1 = 0, sum2 = 0, res = 0;
            while (i < m && j < n)
            {
                if (road1[i] == road2[j])
                {
                    if (i < m - 1 && road1[i + 1] == road1[i])
                    {
                        sum1 += road1[i];
                        i++;
                    }
                    else if (j < n - 1 && road2[j + 1] == road2[j])
                    {
                        sum2 += road2[j];
                        j++;
                    }
                    else
                    {
                        res = res + Math.Max(sum1, sum2) + road2[j];
                        sum1 = 0;
                        sum2 = 0;
                        i++;
                        j++;
                    }
                }
                else
                {
                    if (road1[i] > road2[j])
                    {
                        sum2 += road2[j];
                        j++;
                    }
                    else
                    {
                        sum1 += road1[i];
                        i++;
                    }
                }
            }
            while (i < m)
            {
                sum1 += road1[i];
                i++;
            }
            while (j < n)
            {
                sum2 += road2[j];
                j++;
            }
            res = res + Math.Max(sum1, sum2);
            return res;
        }
        static void Main(string[] args)
        {
            int t = Convert.ToInt32(Console.ReadLine());
            while (t-- > 0)
            {
                int[] size = Array.ConvertAll(Console.ReadLine().Trim().Split(), x => Convert.ToInt32(x));
                int m = size[0];
                int n = size[1];
                int[] road1 = Array.ConvertAll(Console.ReadLine().Trim().Split(), x => Convert.ToInt32(x));
                int[] road2 = Array.ConvertAll(Console.ReadLine().Trim().Split(), x => Convert.ToInt32(x));
                Console.WriteLine(TotalSum(road1, road2, m, n));
            }
        }
    }
}
