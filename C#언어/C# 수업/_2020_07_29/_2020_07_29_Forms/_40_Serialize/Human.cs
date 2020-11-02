using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _40_Serialize
{
    [Serializable]  // 이 객체(클래스)는 시리얼라이즈로 읽어들이는게 가능하다.
    class Human
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public float Height { get; set; }
        public float Weight { get; set; }

        public override string ToString()       // 오브젝트 클래스로부터 상속받은 ToString()
        {
            return Name + ":" + Age + ":" + Height + ":" + Weight;
        }
    }
}
