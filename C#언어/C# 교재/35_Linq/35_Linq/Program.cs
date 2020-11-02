using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _35_Linq
{
    class Program
    {
        static void Main(string[] args)
        {
            var Files = 
                from f in Directory.GetFiles("c:\\")   // 파일목록중에서 c:\\에 있는 f를 선택해라 
                select f;
            foreach (var f in Files)
            {
                Console.WriteLine("Name : " + f);
            }
        }
    }
}
