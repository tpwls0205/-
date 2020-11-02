using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _14_GenericWhere
{
    class Wrapper<T> where T : struct  // 클래스(힙):래퍼런스 , 스트럭트(스택):밸류
    {                                   // where를 통해 제약조건을 건다.
        T Value;
        public Wrapper() { Value = default(T); }
        public Wrapper(T aValue)
        { Value = aValue; }
        public T Data
        {
            get { return Value; }
            set { Value = value; }
        }
        public void OutValue()
        {
            Console.WriteLine(Value);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Wrapper<int> gi =
                new Wrapper<int>(1234);
            gi.OutValue();
            Wrapper<float> gf =
            new Wrapper<float>(3.14f);
            gf.OutValue();
            Wrapper<string> gs =
            new Wrapper<string>("대한민국");
            gs.OutValue();
        }
    }
}
