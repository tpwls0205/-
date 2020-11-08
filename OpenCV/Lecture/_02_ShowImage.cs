using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _02_ShowImage
    {
        static void Main(string[] args)
        {
            Mat src = Cv2.ImRead("../../img/jang.jpg", ImreadModes.Grayscale);

            Cv2.NamedWindow("src", WindowMode.AutoSize);
            Cv2.SetWindowProperty("src", WindowProperty.Fullscreen, 0);
            Cv2.ImShow("src", src);
            Cv2.WaitKey(0);
            Cv2.DestroyWindow("src");
        }
    }
}
