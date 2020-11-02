using System;
using System.Threading;

namespace _56_ThreadError
{
    // cpu가 12개 100개가 넘는 프로세스를 감당하려면 돌아가면서 사용(화장실 이용하듯이)
    // 스케줄링 : 스레드는 스케줄링에 의해서 돌아가면서 실행한다 : 하지만 사용시간이 일정하지않다
    // 컨텍스트 스위칭 : 스레드가 스케줄링에 의해서 다른 스레드로 권한이 넘어갈때 기존 실행정보를 보관하는 작업
    // 스레드 동기화 : 여러 스레드에서 공유하는 변수는 연산이 정상적으로 구동하기 위해 방어하는 코드가 필요하다
    class Program
    {
        static int cnt = 0;
        static void ThreadAdd()
        {
            for(int i =0; i<100000; i++)
            {
                cnt++;
            }
        }
        static void ThreadSub()
        {
            for(int i =0; i<100000; i++)
            {
                cnt--;
            }
        }
        static void Main(string[] args)
        {
            Thread tAdd = new Thread(new ThreadStart(ThreadAdd));
            Thread tSub = new Thread(new ThreadStart(ThreadSub));
            tAdd.Start();
            tSub.Start();

            tAdd.Join();
            tSub.Join();

            Console.WriteLine("2개 스레드의 결과값은 " + cnt);
        }
    }
}
