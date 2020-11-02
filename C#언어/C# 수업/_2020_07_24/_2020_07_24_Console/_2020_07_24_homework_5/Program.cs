//5. 정수 3개를 입력받고 이 3개의 수로 삼각형을 만들 수 있는지를 판별하세요
//   삼각형이 가능하려면 두 변의 합이 다른 한 변의 합보다 반드시 커야 합니다. (조건 연산자를 사용하세요)
using System;

namespace _2020_07_24_homework_5
{
    class Program
    {
        static void Main(string[] args)
        {
            string snum;
            int num1, num2, num3;
            Console.Write("정수 입력 >> ");
            snum = Console.ReadLine();
            num1 = Convert.ToInt32(snum);
            Console.Write("정수 입력 >> ");
            snum = Console.ReadLine();
            num2 = Convert.ToInt32(snum);
            Console.Write("정수 입력 >> ");
            snum = Console.ReadLine();
            num3 = Convert.ToInt32(snum);
            if (num1 > num2 && num1 > num3)
            {
                if (num1 < num2 + num3)
                {
                    Console.WriteLine("삼각형이 가능합니다");
                }
                else
                {
                    Console.WriteLine("불가능");
                }
            }
            if (num2 > num1 && num2 > num3)
            {
                if (num2 < num1 + num3)
                {
                    Console.WriteLine("삼각형이 가능합니다");
                }
                else
                {
                    Console.WriteLine("불가능");
                }
            }
            if (num3 > num1 && num3 > num2)
            {
                if (num3 < num2 + num3)
                {
                    Console.WriteLine("삼각형이 가능합니다");
                }
                else
                {
                    Console.WriteLine("불가능");
                }
            }
        }
    }
}
