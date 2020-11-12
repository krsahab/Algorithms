using System;]
using System.Collections.Generic;

namespace Removable
{
    public class Solution
    {
        public IList<int> FindSubstring(string s, string[] words)
        {
            Dictionary<string, int> inp = new Dictionary<string, int>();
            Dictionary<string, int> curr = new Dictionary<string, int>();
            int len = words[0].Length;
            foreach (var item in words)
            {
                if (inp.ContainsKey(item))
                    inp[item]++;
                else
                    inp.Add(item,1);
            }
            for (int i = 0; i < s.Length-len;)
            {
                string str = s.Substring(i,len);
                if(inp.ContainsKey(str))
                {
                    if (curr.ContainsKey(str))
                        curr[str]++;
                    else
                        curr.Add(str, 1);
                    if(inp.Count==curr.Count)
                    {
                        foreach (var item in inp)
                        {
                            if (inp[item.Key]!=curr[item.Key])
                            {

                            }
                        }
                    }
                }
            }
        }
    }
    static void Main(string[] args)
    {
        //int[] arr = new int[] { 0, 1 };
        Console.WriteLine(Solution.MinWindow("ADOBECODEBANC", "ABC"));
    }
}
}
