//8.int배열을 10개 생성해라.
// int배열에 3의 배수를 차례대로 저장해라.
// 그리고 거꾸로 출력해라.
using System;

namespace _08
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] num = new int[10];
            for (int i = 0; i < 10; i++)
            {
                num[i] = 3 * (i + 1);
            }
            for (int i = 9; i >= 0; i--)
            {
                Console.WriteLine("{0}", num[i]);
            }
        }
    }
}
