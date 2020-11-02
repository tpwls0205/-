//3. 돈의 액수를 입금하세요
//   입금한 돈을 오만원권, 만원권, 오천원권, 천원권, 500원동전, 100원동전, 50원동전, 10원동전, 1원동전 각 몇개로 변환되는지 출력하세요
//   출력 개수는 단위가 큰 것 순서로 계산합니다
//   예를 들어 78670원이면<오만원 1매, 만원 2매, 오천원 1매, 천원 3매, 500원 1개, 100원 1개, 50원 1개, 10원 2개> 입니다.
using System;

namespace _2020_07_24_homework_3
{
    class Program
    {
        static void Main(string[] args)
        {
            string snum;
            int num;
            Console.Write("돈의 액수를 입금하세요 >> ");
            snum = Console.ReadLine();
            num = Convert.ToInt32(snum);
            int num1 = num / 50000;     // 5만원
            num = num % 50000;     // 5만원 나눈 후 잔돈
            int num2 = num / 10000;     // 1만원
            num = num % 10000;     // 1만원 나눈 후 잔돈
            int num3 = num / 5000;      // 5천원
            num = num % 5000;      // 5천원 나눈 후 잔돈
            int num4 = num / 1000;      // 1천원
            num = num % 1000;      // 1천원 나눈 후 잔돈
            int num5 = num / 500;       // 5백원
            num = num % 500;       // 5백원 나눈 후 잔돈
            int num6 = num / 100;       // 1백원
            num = num % 100;       // 1백원 나눈 후 잔돈
            int num7 = num / 50;        // 50원
            num = num % 50;        // 50원 나눈 후 잔돈
            int num8 = num / 10;        // 10원
            num = num % 10;        // 10원 나눈 후 잔돈
            Console.WriteLine("오만원 : {0}매, 만원 : {1}매, 오천원 : {2}매, 천원 : {3}매, 오백원 : {4}매, 백원 : {5}매, 오십원 : {6}매, 십원 : {7}매, " +
                "일원 : {8}매", num1, num2, num3, num4, num5, num6, num7, num8, num);
        }
    }
}
