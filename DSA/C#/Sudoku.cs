using System;
using System.Collections.Generic;

namespace Sudoku
{
    class Program
    {
        static int[][] grid = new int[9][];
        static List<KeyValuePair<int, int>> emptyCell = new List<KeyValuePair<int, int>>();

        static int findStart(int num)
        {
            if (num <= 2)
                return 0;
            else if (num <= 5)
                return 3;
            else
                return 6;
        }
        static KeyValuePair<int, int> findGrid(int x, int y)
        {
            int r = findStart(x);
            int c = findStart(y);
            return new KeyValuePair<int, int>(r, c);
        }
        static bool isvalid(int n, int x, int y)
        {
            for (int i = 0; i < 9; i++)
            {
                if (grid[x][i] == n)
                    return false;
                if (grid[i][y] == n)
                    return false;
                var StartPoint = findGrid(x, y);
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        if (grid[StartPoint.Key + j][StartPoint.Value + k] == n)
                            return false;
                    }
                }
            }
            return true;
        }
        static bool solveSudoku(int index)
        {
            if (index == emptyCell.Count)
                return true;
            for (int i = 1; i <= 9; i++)
            {
                if (isvalid(i, emptyCell[index].Key, emptyCell[index].Value))
                {
                    grid[emptyCell[index].Key][emptyCell[index].Value] = i;
                    if (solveSudoku(index + 1))
                        return true;
                    grid[emptyCell[index].Key][emptyCell[index].Value] = 0;
                }
            }
            return false;
        }
        static void Main(string[] args)
        {
            int t = Convert.ToInt32(Console.ReadLine());
            while (t-- > 0)
            {

                for (int i = 0; i < 9; i++)
                    grid[i] = Array.ConvertAll(Console.ReadLine().Trim().Split(), x => Convert.ToInt32(x));
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 9; j++)
                    {
                        if (grid[i][j] == 0)
                            emptyCell.Add(new KeyValuePair<int, int>(i, j));
                    }
                }
                solveSudoku(0);
                for (int i = 0; i < 9; i++)
                    Array.ForEach(grid[i], x => Console.Write(x + " "));
                Console.WriteLine();
            }
        }
    }
}
