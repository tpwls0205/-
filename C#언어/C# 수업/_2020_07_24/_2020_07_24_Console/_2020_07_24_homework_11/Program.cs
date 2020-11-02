//11. 정수 10개를 입력받아 배열에 저장하고,
//이 정수중에서 2의 배수와 3의 배수를 출력하세요
using System;

namespace _2020_07_24_homework_11
{
    class Program
    {
        static void Main(string[] args)
        {
            string snum;
            int[] num = new int[10];
            for (int i = 0; i < 10; i++)
            {
                Console.Write("정수 입력 >> ");
                snum = Console.ReadLine();
                num[i] = Convert.ToInt32(snum);
            }
            for (int i = 0; i < 10; i++)
            {
                if (num[i] % 2 == 0 || num[i] % 3 == 0)
                {
                    Console.WriteLine("{0}", num[i]);
                }
            }
        }
    }
}
