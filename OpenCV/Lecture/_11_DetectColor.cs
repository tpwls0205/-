using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _10_DetectColor
    {
        static void Main(string[] args)
        {
            Mat src = Cv2.ImRead("../../img/tomato.jpg");
            Mat hsv = new Mat(src.Size(), MatType.CV_8UC3);
            Mat orange = new Mat(src.Size(), MatType.CV_8UC3);
            Mat blue = new Mat(src.Size(), MatType.CV_8UC3);
            Mat added_color = new Mat(src.Size(), MatType.CV_8UC3);
            Mat dst = new Mat(src.Size(), MatType.CV_8UC3);

            Cv2.CvtColor(src, hsv, ColorConversionCodes.BGR2HSV);

            Cv2.InRange(hsv, new Scalar(8, 100, 100), new Scalar(20, 255, 255), orange);
            Cv2.InRange(hsv, new Scalar(110, 100, 100), new Scalar(130, 255, 255), blue);
            Cv2.AddWeighted(orange, 1.0, blue, 1.0, 0.0, added_color);

            Cv2.BitwiseAnd(hsv, hsv, dst, added_color);
            Cv2.CvtColor(dst, dst, ColorConversionCodes.HSV2BGR);

            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
