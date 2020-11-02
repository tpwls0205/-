using System;
using System.Threading;

namespace _59_ThreadMonitor
{
    /*  cnt++을 3단계의 과정을 거쳐서 연산이 이루어진다
     *  1. RAM에 cnt값을 레지스터로 복사
     *  2. 레지스터의 값을 1 증가
     *  3. 증가한 레지스터 값을 RAM의 cnt에 복사한다
     *  
     *  그런데 이 3단계 과정 중 어디에서나 다른 스레드로 실행제어권이 넘어갈 수 있다.
     *  이 과정을 Context Switching이라 부르는데
     *  공유변수의 값의 왜곡이 종종 발생하게 된다.
     *  
     *  그래서 자물쇠(object)를 마련해 이 3단계 과정 중에 실행제어권이 넘어가지 않도록 방어한다.
     */
    class Program
    {
        // lock을 걸기 위한 자물쇠
        static object obj = new object();

        static int cnt = 0;

        static void ThreadAdd()
        {
            Monitor.Enter(obj); // 자물쇠로 잠근다
            for (int i = 0; i < 100000; i++)
            {
                cnt++;
            }
            Monitor.Exit(obj);  // 자물쇠를 연다
        }
        static void ThreadSub()
        {
            Monitor.Enter(obj); // 자물쇠로 잠근다
            for (int i = 0; i < 100000; i++)
            {
                cnt--;
            }
            Monitor.Exit(obj);  // 자물쇠를 연다
        }
        static void Main(string[] args)
        {
            Thread tAdd0 = new Thread(new ThreadStart(ThreadAdd));
            Thread tAdd1 = new Thread(new ThreadStart(ThreadAdd));
            Thread tAdd2 = new Thread(new ThreadStart(ThreadAdd));
            Thread tSub0 = new Thread(new ThreadStart(ThreadSub));
            Thread tSub1 = new Thread(new ThreadStart(ThreadSub));
            Thread tSub2 = new Thread(new ThreadStart(ThreadSub));
            tAdd0.Start();
            tAdd1.Start();
            tAdd2.Start();
            tSub0.Start();
            tSub1.Start();
            tSub2.Start();

            tAdd0.Join();
            tAdd1.Join();
            tAdd2.Join();
            tSub0.Join();
            tSub1.Join();
            tSub2.Join();

            Console.WriteLine("2개 스레드의 결과값은 " + cnt);
        }
    }
}
