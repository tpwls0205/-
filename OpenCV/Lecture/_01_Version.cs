using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _01_Version
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Cv2.GetVersionString());
        }
    }
}
