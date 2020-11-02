using System;                                   // 인클루드, 라이브러리 개념

namespace _2020_07_16                           // c#은 규모가 큰 프로젝트를 하기때문에 namespace가 필수
{
    class Program
    {
        static void Main(string[] args)         // static을 붙치면 객체가 생성되지 않아도 메모리에 바로 등록
        {
            Console.WriteLine("Hello World!");  // Line 개행
        }
    }
}

/*
    Int32.Parse : 문자열을 정수로 변환
    C# 에서는 정수로 True, false를 구분 할 수 없다.(0,1)
    {0:d2} : 2자리로 출력. d3 : 3자리로 출력
    ReadLine() : 아무거나 입력받으면 다음 창으로 넘어가기 위해
    try catch : exception 클래스(message(오류) , stack(오류위치))

    string[] =>  array클래스의 자료형
    C++은 객체선언은 ;로 하면되지만
    C# 부터는 객체선언을 할때 무조건 = new 를 통해 동적할당을 해야한다.
*/