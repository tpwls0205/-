//4. 369게임을 작성합니다.
//   1~99까지의 정수를 입력받고
//   3,6,9중 하나가 있으면 "박수짝"을 출력하고
//   2개가 있으면 "박수짝짝"을 출력하세요
//   예를 들어 13은 "박수짝"
//   36인 경우는 "박수짝짝"을 출력하면 됩니다.
using System;

namespace _2020_07_24_homework_4
{
    class Program
    {
        static void Main(string[] args)
        {
            int num;
            string snum;
            Console.Write("1~99까지의 정수를 입력하세요 >> ");
            snum = Console.ReadLine();
            num = Convert.ToInt32(snum);
            int num1 = num / 10;// 32 -> num/10 = 3 / 32->10->3.2 -> 값3
            int num2 = num % 10;// 32 -> num%10 = 2 / 32->10->3.2 -> 나머지2
            if (num2 == 3 || num2 == 6 || num2 == 9 || num1 == 3 || num1 == 6 || num1 == 9)
            {
                if ((num2 == 3 || num2 == 6 || num2 == 9) && (num1 == 3 || num1 == 6 || num1 == 9))
                {
                    Console.WriteLine("박수짝짝");
                }
                else
                {
                    Console.WriteLine("박수짝");
                }
            }
        }
    }
}
