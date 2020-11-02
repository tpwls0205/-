//10.int 배열로 10개의 공간을 생성하라
//  1 ~ 10까지의 임의의 수를 저장하고
//  홀수만 골라서 출력하라
using System;

namespace _2020_07_24_homework_10
{
    class Program
    {
        static void Main(string[] args)
        {
            Random r = new Random();
            int[] num = new int[10];
            for (int i = 0; i < 10; i++)
            {
                num[i] = r.Next(10) + 1; // r.Next(10) = 0~9
                if (num[i] % 2 == 1)
                {
                    Console.WriteLine("{0}", num[i]);
                }
            }
        }
    }
}
