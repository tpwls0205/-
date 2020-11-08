using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _08_cvtColor
    {
        static void Main(string[] args)
        {
            Mat src = Cv2.ImRead("../../img/crow.jpg");

            //Mat dst = new Mat(src.Size(), MatType.CV_8UC1);
            //Cv2.CvtColor(src, dst, ColorConversionCodes.BGR2GRAY);

            Mat dst = new Mat(src.Size(), MatType.CV_8UC3);
            Cv2.CvtColor(src, dst, ColorConversionCodes.BGR2HSV);

            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
