using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _20_ClassPointer
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] ar = { 1, 2, 3, 4, 5 };   // 배열은 클래스(힙메모리, 래퍼런스)
            unsafe
            {
                fixed (int* pi = &ar[0])    // 계좌번호, 금고의 위치를 고정시킨다(CLR의 임의적으로 데이터 위치를 옮기지 못하도록)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        Console.WriteLine(pi[i]);
                    }
                }
            }
        }
    }
}
