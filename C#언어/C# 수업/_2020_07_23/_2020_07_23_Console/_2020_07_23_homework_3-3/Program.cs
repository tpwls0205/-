//3. 구구단을 출력하되 1을 입력하면 홀수단만
//   2를 입력하면 짝수단만 출력하라
using System;

namespace _2020_07_23_homework_3_3
{
    class Program
    {
        static void Main(string[] args)
        {
            string snum;
            int num;
            Console.Write("1은 홀수단, 2는 짝수단 출력 >> ");
            snum = Console.ReadLine();
            num = Convert.ToInt32(snum);
            for(int i = 2; i <= 9; i++)
            {
                for(int j = 1; j <=9; j++)
                {
                    if (num == 1 && i % 2 == 1)
                    {
                        Console.Write("{0} x {1} = {2}  ", i, j, i * j);
                    }
                    else if(num == 2 && i % 2 ==0)
                    {
                        Console.Write("{0} x {1} = {2}  ", i, j, i * j);
                    }
                }
                Console.WriteLine();
            }
        }
    }
}
