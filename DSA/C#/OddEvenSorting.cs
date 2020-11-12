using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OddEvenSorting
{
    class CustomCompare : IComparer<int>
    {
        public int Compare(int x, int y)
        {
            if(x%2==0)
            {
                if (y % 2 == 0)
                    return x.CompareTo(y);
                else
                    return 1;
            }
            else if(y%2==0)
            {
                return -1;
            }
            else
            {
                return -(x.CompareTo(y));
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = { 1, 3, 4, 2, 5, 10, 56, 11, 32, 45, 87, 45 };
            Array.Sort(arr, new CustomCompare());
            foreach (var item in arr)
            {
                Console.WriteLine(item);
            }
        }
    }
}
