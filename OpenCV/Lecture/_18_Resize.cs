using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _18_Resize
    {
        static void Main(string[] args)
        {
            Mat src = Cv2.ImRead("../../img/car.png");
            Mat dst0 = new Mat(new Size(1, 1), MatType.CV_8UC3);
            Mat dst1 = new Mat(new Size(1, 1), MatType.CV_8UC3);

            dst0 = src.SubMat(280, 310, 240, 405);
            dst1 = src.SubMat(280, 310, 240, 405);
            Cv2.Resize(dst0, dst0, new Size(9999, 0), 8.0, 8.0, InterpolationFlags.Cubic);
            Cv2.Resize(dst1, dst1, new Size(9999, 0), 8.0, 8.0, InterpolationFlags.Nearest);
            Cv2.ImShow("src", src);
            Cv2.ImShow("dst0", dst0);
            Cv2.ImShow("dst1", dst1);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
