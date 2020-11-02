using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _9_Constant
{
    /*
     * const는 static속성을 부여하게 된다.
     * 객체 선언을 하지 않아도 된다.
     */
    class SEASON
    {
        public const string SPRING = "봄";
        public const string SUMMER = "여름";
        public const string FALL = "가을";
        public const string WINTER = "겨울";
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("{0}", SEASON.SPRING);
            Console.WriteLine("{0}", SEASON.SUMMER);
            Console.WriteLine("{0}", SEASON.FALL);
            Console.WriteLine("{0}", SEASON.WINTER);
        }
    }
}
