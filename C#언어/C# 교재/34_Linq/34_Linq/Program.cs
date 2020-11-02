using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _34_Linq
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] ar = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            IEnumerable<int> Query =
                from n in ar where (n % 3 == 0) select n;   // ar로 부터 3배수인 n을 선택해서 가져와라
            foreach (int k in Query)
            {
                Console.WriteLine(k);
            }
        }
    }
}
