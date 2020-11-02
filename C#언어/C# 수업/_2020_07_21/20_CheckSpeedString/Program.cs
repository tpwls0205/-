using System;
using System.Diagnostics;
using System.Text;

namespace _20_CheckSpeedString
{
    class Program
    {
        static void Main(string[] args)
        {
            Stopwatch sw = new Stopwatch();
            
            string str = "알파벳";
            sw.Start();
            for (char a='a';a<='z';a++)
            {
                str += a;
            }
            sw.Stop();
            Console.WriteLine(str + " : " + sw.Elapsed);    // 시작부터 종료까지 시간간격을 잰다.

            sw.Reset();
            
            StringBuilder sb = new StringBuilder("알파벳", 40);
            sw.Start();
            for (char a='a';a<='z';a++)
            {
                sb.Append(a);
            }
            sw.Stop();
            Console.WriteLine(sb.ToString() + " : " + sw.Elapsed);   // tostring : 빌더를 string클래스로 변환
        }
    }
}
