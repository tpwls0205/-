﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _15_is
{
    class Animal { }
    class Feline : Animal { }
    class Canine : Animal { }
    class Cat : Feline { }
    class Tiger : Feline { }
    class Lion : Feline { }
    class Dog : Canine { }
    class Wolf : Canine { }
    class Jindo : Dog { }
    class Program
    {
        static void Eat(Animal A)
        {
            /*
             * A객체는 Cat이거나 Cat의 상속을 받았니?
             * A객체는 Dog이거나 Dog의 상속을 받았니?
             * 
             * A is Cat => true (Cat이거나 Cat의 자식)
             * A as Cat => Cat객체로 변환가능/불가능
             *             Cat cat = A as Cat;
             *             if(cat!=null) : 해당 객체로 형변환
             *             else : 해당 객체가 아니다
             */
            if (A is Cat || A is Dog)
            {
                Console.WriteLine("고기도 먹고, 국에 밥도"
                                   + "말아 먹음");
            }
            else
            {
                Console.WriteLine("고기만 먹음");
            }
        }
        static void EatAs(Animal A)
        {
            Cat C = A as Cat;
            Dog D = A as Dog;
            if (C != null || D != null)
            {
                Console.WriteLine("고기도 먹고, 국에 밥도"
                                   + "말아 먹음");
            }
            else
            {
                Console.WriteLine("고기만 먹음");
            }
        }
        static void Main(string[] args)
        {
            Animal[] ani = new Animal[10];
            ani[0] = new Cat();
            ani[1] = new Tiger();
            ani[2] = new Lion();
            ani[3] = new Dog();
            ani[4] = new Wolf();
            ani[5] = new Jindo();
            for (int i = 0; i <= 5; i++)
                Eat(ani[i]);
            Console.WriteLine();
            for (int i = 0; i <= 5; i++)
                EatAs(ani[i]);
        }
    }
}
