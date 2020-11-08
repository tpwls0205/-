using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _21_PerspectiveTransform
    {
        static void Main(string[] args)
        {
            Mat src = Cv2.ImRead("../../img/clouds.jpg");
            Mat dst = new Mat();

            List<Point2f> src_pts = new List<Point2f>()
            {
                new Point2f(0f, 0f),
                new Point2f(src.Width, 0f),
                new Point2f(src.Width, src.Height),
                new Point2f(0f, src.Height)
            };

            List<Point2f> dst_pts = new List<Point2f>()
            {
                new Point2f(300f, 300f),
                new Point2f(900f, 200f),
                new Point2f(src.Width-700f, src.Height-700f),
                new Point2f(0f, src.Height-300f)
            };

            Mat M = Cv2.GetPerspectiveTransform(src_pts, dst_pts);

            Cv2.WarpPerspective(src, dst, M, new Size(src.Width, src.Height), borderValue: new Scalar(255, 255, 255, 0));

            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
