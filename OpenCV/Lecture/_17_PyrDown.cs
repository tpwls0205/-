using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _17_PyrDown
    {
        static void Main(string[] args)
        {
            Mat src = Cv2.ImRead("../../img/ferris-wheel.jpg");
            Mat[] dst = new Mat[4];
            for(int i=1;i< dst.Length; i++)
                dst[i] = new Mat(src.Size(), MatType.CV_8UC3);

            dst[0] = src;
            for (int i=1;i< dst.Length; i++)
                Cv2.PyrDown(dst[i-1], dst[i]);

            Cv2.ImShow("src", src);
            
            for(int i=1;i< dst.Length; i++)
                Cv2.ImShow("dst"+i, dst[i]);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
