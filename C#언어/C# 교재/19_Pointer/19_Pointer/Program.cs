using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _19_Pointer
{
    class Program
    {
        static void Main(string[] args)
        {
            int i = 3, j;
            // C# 포인터를 사용하려면 : 프로젝트 -> 속성 -> 빌드 -> 안전하지 않은 코드 허용 체크
            unsafe  // C# 포인터는 unsafe라는 범위 내에서 사용
            {
                int* pi;
                pi = &i;
                j = *pi;
            }
            Console.WriteLine("i={0}, j={1}", i, j);
        }
    }
}
