//1. 영문자를 입력받습니다
//   소문자인지 대문자인지 판별하세요(조건 연산자를 사용하세요)
using System;

namespace _2020_07_24_homework_1
{
    class Program
    {
        static void Main(string[] args)
        {
            string snum;
            char num;
            Console.Write("영문자를 입력하세요 >> ");
            snum = Console.ReadLine();
            num = Convert.ToChar(snum);
            if (num >= 'a' && num <= 'z')
            {
                Console.WriteLine("소문자 입니다");
            }
            else if (num >= 'A' && num <= 'Z')
            {
                Console.WriteLine("대문자 입니다");
            }
            else
            {
                Console.WriteLine("잘못 입력 했습니다");
            }
        }
    }
}
