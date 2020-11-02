//6. 입력받은 숫자의 구구단을 출력하는데 역순으로 출력
//  예) 3*9=27
//      3*8=24...
using System;

namespace _2020_07_23_homework_3_6
{
    class Program
    {
        static void Main(string[] args)
        {
            string snum;
            int num;
            Console.Write("2~9 숫자 입력 >> ");
            snum = Console.ReadLine();
            num = Convert.ToInt32(snum);
            for(int i =9; i >= 1; i--)
            {
                Console.WriteLine("{0} x {1} = {2}  ", num, i, num * i);
            }
        }
    }
}
