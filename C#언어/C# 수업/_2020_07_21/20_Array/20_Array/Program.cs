using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _20_Array
{
    class Program
    {
        static void Main(string[] args)
        {
            // 관습으로 익숙해져서 허용한다
            //int[] ar = { 1, 2, 3, 4, 5 };
            int[] ar;   // ar 참조변수로 클래스이다. / 클래스이기때문에 ar.메서드를 호출할 수 있다.
            ar = new int[5];

            Console.WriteLine(ar.GetHashCode());

            for (int i = 0; i < 5; i++)
            {
                ar[i] = i * 2;
            }
            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine(ar[i]);
            }
        }
    }
}
