using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _33_lambda
{
    delegate int dele(int a);

    class Program
    {
        static void Main(string[] args)
        {
            dele d = a => a + 1;        // 델리게이트 변수 = 매개변수 => 리턴 값
            int k = d(3);
            Console.WriteLine("k = " + k);
        }
    }
}
