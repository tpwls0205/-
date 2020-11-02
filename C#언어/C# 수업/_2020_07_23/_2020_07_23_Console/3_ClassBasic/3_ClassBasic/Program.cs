using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _3_ClassBasic
{
    class Student           // 각 항목마다 접근권한을 부여(public)
    {
        public string Name;
        public int Age;
        public void Intro()
        {
            Console.WriteLine("이름: " + Name);
            Console.WriteLine("나이: " + Age);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Student Kim;            // Student의 참조변수
            Kim = new Student();    // Student의 객체 생성(new로 해야함) 
            Kim.Name = "김길동";
            Kim.Age = 25;
            Kim.Intro();
        }
    }
}
