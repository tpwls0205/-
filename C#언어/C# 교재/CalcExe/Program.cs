using System;
using CalcLib;

namespace CalcExe
{
    class Program                   // dll파일, 프로젝트 -> 프로젝트 참조추가 -> 찾아보기 -> dll파일 선택 -> 종속성(어셈블리) 확인
    {
        static void Main(string[] args)
        {
            Console.Write("첫 번째 숫자 입력 : ");
            double num0 = Double.Parse(Console.ReadLine());
            Console.Write("두 번째 숫자 입력 : ");
            double num1 = Double.Parse(Console.ReadLine());

            Console.WriteLine("+ 결과 " + Arith.Add(num0, num1));
            Console.WriteLine("- 결과 " + Arith.Sub(num0, num1));
            Console.WriteLine("* 결과 " + Arith.Mul(num0, num1));
            Console.WriteLine("/ 결과 " + Arith.Div(num0, num1));
        }
    }
}
