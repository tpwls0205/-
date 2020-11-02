//2. 영문자를 입력받습니다
//   소문자는 대문자로, 대문자는 소문자로 변경해서 출력하세요
//   (조건 연산자를 사용하세요)
//   (아스키테이블/유니코드테이블을 참조하면 됩니다)
using System;

namespace _2020_07_24_homework_2
{
    class Program
    {
        static void Main(string[] args)
        {
            string snum;
            char num;
            Console.Write("영문자를 입력하세요 >> ");
            snum = Console.ReadLine();
            num = Convert.ToChar(snum);
            if (num >= 'a' && num <= 'z')
            {
                Console.WriteLine(Convert.ToChar(num-32));
            }
            else if (num >= 'A' && num <= 'Z')
            {
                Console.WriteLine(Convert.ToChar(num+32));
            }
            else
            {
                Console.WriteLine("잘못 입력 했습니다");
            }
        }
    }
}
