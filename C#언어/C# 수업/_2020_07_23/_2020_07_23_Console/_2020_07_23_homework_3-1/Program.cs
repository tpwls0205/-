//1. 양의 정수 입력받고 그 수만큼 3의 배수 출력하세요
//   예를 들어 5를 입력받으면 3 6 9 12 15를 출력하면 됩니다
using System;

namespace _2020_07_23_homework_3_1
{
    class Program
    {
        static void Main(string[] args)
        {
            string snum;
            int num = 0;
            Console.Write("양의 정수를 입력해주세요 >> ");
            snum = Console.ReadLine();
            num = Convert.ToInt32(snum);
            for (int i = 1; i <= num; i++)
            {
                Console.WriteLine(i * 3);
            }
        }
    }
}
