//8. 두 개의 정수를 입력받습니다.
//   두 정수를 포함한 사이의 정수의 합을 출력하세요
//   예를 들면 3과 5를 입력하면 3+4+5의 합을 출력하면 됩니다.
using System;
using System.Numerics;

namespace _2020_07_23_homework_3_8
{
    class Program
    {
        static void Main(string[] args)
        {
            string snum1;
            string snum2;
            int num1;
            int num2;
            int sum = 0;
            Console.Write("두 개의 정수 입력 >> ");
            snum1 = Console.ReadLine();
            snum2 = Console.ReadLine();
            num1 = Convert.ToInt32(snum1);
            num2 = Convert.ToInt32(snum2);
            if(num2-num1 >= 0)
            {
                for(int i = num1;i <= num2;i++)
                {
                    sum += i;
                }
            }
            else if(num2-num1 < 0)
            {
                for (int i = num2; i <= num1; i++)
                {
                    sum += i;
                }
            }
            Console.WriteLine(sum);
        }
    }
}
