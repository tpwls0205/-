//9.int배열을 10개 생성해라
//  사용자로부터 10개의 값을 입력받고
//  순서대로 출력하고
//  총합을 구하세요
using System;

namespace _2020_07_24_homework_9
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] num = new int[10];
            string snum;
            int sum = 0;
            for (int i = 0; i < 10; i++)
            {
                Console.Write("값 입력 >> ");
                snum = Console.ReadLine();
                num[i] = Convert.ToInt32(snum);
                sum += num[i];
            }
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine("{0}", num[i]);
            }
            Console.WriteLine("총합은 : {0}", sum);
        }
    }
}
