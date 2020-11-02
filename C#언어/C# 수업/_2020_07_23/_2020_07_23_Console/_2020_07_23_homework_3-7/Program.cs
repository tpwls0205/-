//7. 정수 n을 입력받고 n!을 구하세요.(factorial)
//   5를 입력한경우 1*2*3*4*5를 구하세요.

using System;

namespace _2020_07_23_homework_3_7
{
    class Program
    {
        static void Main(string[] args)
        {
            string snum;
            int num;
            int value = 1;
            Console.Write("정수 입력 >> ");
            snum = Console.ReadLine();
            num = Convert.ToInt32(snum);
            for(int i = 1; i <= num; i++)
            {
                value *= i;
            }
            Console.WriteLine(value);
        }
    }
}
