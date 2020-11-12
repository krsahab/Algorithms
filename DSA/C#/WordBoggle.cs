using System;
using System.Linq;

namespace WordBoggle
{
    class Program
    {
        static string[] arr;
        static string[,] charArray;
        static bool[,] visited;
        static string result;

        static int[] row = { -1, -1, -1, 1, 1, 1, 0, 0 };
        static int[] col = { -1, 0, 1, -1, 0, 1, -1, 1 };
        static bool isvalid(int r, int c, int m, int n)
        {
            if (r >= 0 && r < m && c >= 0 && c < n)
                return true;
            return false;
        }
        static void PrintWords(int r, int c, int m, int n)
        {
            visited[r, c] = true;
            result += charArray[r, c];
            if (arr.Any(x => x == result))
                Console.Write(result + " ");
            for (int i = 0; i < 8; i++)
            {
                int tr = r + row[i], tc = c + col[i];
                if (isvalid(tr, tc, m, n) && !visited[tr, tc])
                {
                    PrintWords(tr, tc, m, n);
                }
            }
            visited[r, c] = false;
            result = result.Substring(0, result.Length - 1);
        }
        static void Main(string[] args)
        {
            int t = Convert.ToInt32(Console.ReadLine());
            while (t-- > 0)
            {
                int size = Convert.ToInt32(Console.ReadLine());
                arr = Console.ReadLine().Trim().Split();
                int[] dim = Array.ConvertAll(Console.ReadLine().Trim().Split(), x => Convert.ToInt32(x));
                int m = dim[0];
                int n = dim[1];
                charArray = new string[m, n];
                string[] input = Console.ReadLine().Trim().Split();
                int p = 0;
                for (int i = 0; i < m; i++)
                    for (int j = 0; j < n; j++)
                        charArray[i, j] = input[p++];
                visited = new bool[m, n];
                for (int i = 0; i < m; i++)
                    for (int j = 0; j < n; j++)
                        if (arr.Any(x => x.StartsWith(charArray[i, j])))
                            PrintWords(i, j, m, n);
                Console.WriteLine();
            }
        }
    }
}
