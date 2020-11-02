//5. 두 수를 입력받고 최소공배수를 구하세요.
using System;

namespace _2020_07_23_homework_3_5
{
    class Program
    {
        static void Main(string[] args)
        {
            string snum1;
            string snum2;
            int num1;
            int num2;
            Console.Write("두 개의 정수 입력 >> ");
            snum1 = Console.ReadLine();
            snum2 = Console.ReadLine();
            num1 = Convert.ToInt32(snum1);
            num2 = Convert.ToInt32(snum2);
            for (int i = 1; ; i++)
            {
                if (i % num1 == 0 && i % num2 == 0)
                {
                    Console.WriteLine(i);
                    break;
                }
            }
        }
    }
}
