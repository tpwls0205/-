//7. 2차원 평면에서 하나의 직사각형은 두 점으로 표현된다.
//   (50, 50)과(100, 100)의 두 점으로 이루어진 사각형이 있다고 하자.
//  이 때 키보드로부터 한 점을 구성하는 정수 x와 y를 입력받고
//   점(x, y)가 이 직사각형 안에 있는지 밖에 있는지 판별하는 프로그램을
//   작성하세요
using System;

namespace _2020_07_24_homework_7
{
    class Program
    {
        static void Main(string[] args)
        {
            string snum;
            int[] num = new int[2];
            for (int i = 0; i <= 1; i++)
            {
                Console.Write("좌표 입력 >> ");
                snum = Console.ReadLine();
                num[i] = Convert.ToInt32(snum);
            }
            if (num[0] >= 50 && num[0] <= 100 && num[1] >= 50 && num[1] <= 100)
            {
                Console.WriteLine("직사각형 안에 있다.");
            }
            else
            {
                Console.WriteLine("직사각형 안에 없다.");
            }
        }
    }
}
