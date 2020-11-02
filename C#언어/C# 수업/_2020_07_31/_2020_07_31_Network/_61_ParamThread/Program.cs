using System;
using System.Threading;

namespace _61_ParamThread
{
    class Program
    {
        static void ThreadProc(object obj)      // 스레드의 매개변수는 object로 받아야한다
        {
            int cnt = (int)obj;
            for(int i = 0; i < cnt; i++)
            {
                Console.WriteLine(i);
                Thread.Sleep(500);
            }
            Console.WriteLine("직원 스레드 종료");
        }
        static void Main(string[] args)
        {
            Thread t = new Thread(new ParameterizedThreadStart(ThreadProc));    // 매개변수를 통해서 객체가 전달
            t.Start(10);        // Start에서 전달
            Console.WriteLine("주 스레드 대기...");
            t.Join();
            Console.WriteLine("주 스레드 종료...");
        }
    }
}
