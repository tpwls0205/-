//4. 0부터 1씩 증가한 값을 누적하여 더합니다.
//   모두 더한값이 1000이 넘을 때 의 총합과
//   더한 값을 구하세요.

using System;

namespace _2020_07_23_homework_3_4
{
    class Program
    {
        static void Main(string[] args)
        {
            int i = 0;
            int sum = 0;
            while(true)
            {
                sum += i++;
                if(sum >= 1000)
                {
                    Console.WriteLine(sum);
                    break;
                }
            }
        }
    }
}
