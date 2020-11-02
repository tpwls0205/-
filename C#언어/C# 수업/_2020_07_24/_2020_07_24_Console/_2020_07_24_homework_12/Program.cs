//12. 1부터 10까지 곱해서
//그 결과를 출력하는 프로그램을 작성하세요
using System;

namespace _2020_07_24_homework_12
{
    class Program
    {
        static void Main(string[] args)
        {
            int sum = 1;
            for (int i = 1; i <= 10; i++)
            {
                sum *= i;
            }
            Console.WriteLine("{0}", sum);
        }
    }
}
