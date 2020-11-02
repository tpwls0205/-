//9. 5를 입력하면 아래처럼 그림을 출력하세요
//*
//o*
//oo*
//ooo*
//oooo*
using System;

namespace _2020_07_23_homework_3_9
{
    class Program
    {
        static void Main(string[] args)
        {
            string snum;
            int num;
            Console.Write("정수를 입력하세요 >> ");
            snum = Console.ReadLine();
            num = Convert.ToInt32(snum);
            for(int i = 1; i <=num;i++)
            {
                for(int j = 1; j<i; j++)
                {
                    Console.Write("o");
                }
                Console.WriteLine("*");
            }
        }
    }
}
