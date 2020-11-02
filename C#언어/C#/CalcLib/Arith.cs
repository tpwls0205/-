using System;

namespace CalcLib
{
    public class Arith      // dll -> 직접실행하는 파일이 아니라, 라이브러리 파일
                            // 다른 곳에 기능을 사용할 수 있도록 파일로 전달
    {
        public static double Add(double a, double b)
        {
            return a + b;
        }
        public static double Sub(double a, double b)
        {
            return a - b;
        }
        public static double Mul(double a, double b)
        {
            return a * b;
        }
        public static double Div(double a, double b)
        {
            return a / b;
        }
    }
}
