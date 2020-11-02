using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _26_Chogija
{
    class Human
    {
        public string Name { get; set; }
        public int Age { get; set; }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Human Jang = new Human              // ()로 하는건 생성자 함수를 만들고 값을 줘야하는데
                                                // {}는 프로퍼티를 만들어 두면 안에 초기값을 줄 수 있다.
                                                // 생성자는 객체생성할 때 만들어지고
                                                // 초기자는 객체생성을 한 후 값을 준다
                    { Name = "장길산", Age = 32 };
            Console.WriteLine("이름 : " + Jang.Name
                        + ", 나이 : " + Jang.Age);
        }
    }
}
