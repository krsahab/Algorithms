using System;
public class GFG
{
    static public int FindOperations(string s1, string s2, int l1, int l2)
    {
        if (l1 == 0 && l2 == 0)
            return 0;
        if (l1 == 0)
            return l2;
        if (l2 == 0)
            return l1;
        if (s1[l1 - 1] == s2[l2 - 1])
            return FindOperations(s1, s2, l1 - 1, l2 - 1);
        else
            return 1 + Math.Min(Math.Min(FindOperations(s1,s2,l1,l2-1), FindOperations(s1, s2, l1-1, l2)), FindOperations(s1, s2, l1-1, l2 - 1));
    }
    static public void Main()
    {
        int t = Convert.ToInt32(Console.ReadLine());
        while (t-- > 0)
        {
            int[] inp = Array.ConvertAll(Console.ReadLine().Trim().Split(), x => Convert.ToInt32(x));
            string[] input = Console.ReadLine().Trim().Split();
            Console.WriteLine(FindOperations(input[0], input[1], input[0].Length, input[1].Length));
        }
    }
}