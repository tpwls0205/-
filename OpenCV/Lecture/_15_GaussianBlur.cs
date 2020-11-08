using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _15_GaussianBlur
    {
        static void Main(string[] args)
        {
            Mat src = Cv2.ImRead("../../img/crescent.jpg");
            Mat dst = new Mat(src.Size(), MatType.CV_8UC3);
            Mat dst1 = new Mat(src.Size(), MatType.CV_8UC3);

            Cv2.GaussianBlur(src, dst, new Size(9, 9), 3, 3, BorderTypes.Isolated);
            Cv2.ImShow("dst", dst);

            Cv2.BilateralFilter(src, dst1, 100, 33, 11, BorderTypes.Isolated);
            Cv2.ImShow("dst1", dst1);

            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
