using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _19_WarpAffine
    {
        static void Main(string[] args)
        {
            Mat src = Cv2.ImRead("../../img/glass.jpg");
            Mat dst = new Mat();

            Cv2.Flip(src, dst, FlipMode.Y);
            Mat matrix = Cv2.GetRotationMatrix2D(new Point2f(src.Width / 2, src.Height / 2), 90.0, 1.0);
            Cv2.WarpAffine(dst, dst, matrix, new Size(src.Width, src.Height));

            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
