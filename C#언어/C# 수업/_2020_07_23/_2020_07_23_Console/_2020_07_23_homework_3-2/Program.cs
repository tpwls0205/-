//2. 사용자로부터 정수를 입력받습니다.
//   입력 받은 값을 계속 더합니다
//   사용자가 0을 입력하면 합을 출력합니다
//   프로그램을 종료합니다.
using System;
using System.Diagnostics.CodeAnalysis;

namespace _2020_07_23_homework_3_2
{
    class Program
    {
        static void Main(string[] args)
        {
            string snum;
            int num = 0;
            while (true)
            { 
                Console.Write("정수를 입력해주세요 >> ");
                snum = Console.ReadLine();
                num += Convert.ToInt32(snum);
                Console.WriteLine();
                if(Convert.ToInt32(snum) == 0)
                {
                    Console.WriteLine(num);
                    break;
                }
            }
        }
    }
}
