using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _20_AffineTransform
    {
        static void Main(string[] args)
        {
            Mat src = Cv2.ImRead("../../img/clouds.jpg");
            Mat dst = new Mat();

            List<Point2f> src_pts = new List<Point2f>()
            {
                new Point2f(0f, 0f),
                new Point2f(0f, src.Height),
                new Point2f(src.Width, src.Height)
            };

            List<Point2f> dst_pts = new List<Point2f>()
            {
                new Point2f(300f, 300f),
                new Point2f(300f, src.Height),
                new Point2f(src.Width-400f, src.Height-200f)
            };

            Mat M = Cv2.GetAffineTransform(src_pts, dst_pts);

            Cv2.WarpAffine(src, dst, M, new Size(src.Width, src.Height), borderValue: new Scalar(127, 127, 127, 0));

            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
