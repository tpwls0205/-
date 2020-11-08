using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _30_HoughLineP
    {
        static void Main(string[] args)
        {
            Mat src = Cv2.ImRead("../../img/card.jpg");
            Mat gray = new Mat();
            Mat binary = new Mat();
            Mat morp = new Mat();
            Mat canny = new Mat();
            Mat dst = src.Clone();

            Mat kernel = Cv2.GetStructuringElement(MorphShapes.Rect, new Size(3, 3));
            Cv2.ImShow("src", src); Cv2.WaitKey(0);
            Cv2.CvtColor(src, gray, ColorConversionCodes.BGR2GRAY);
            Cv2.ImShow("gray", gray); Cv2.WaitKey(0);
            Cv2.Threshold(gray, binary, 150, 255, ThresholdTypes.Binary);
            Cv2.ImShow("binary", binary); Cv2.WaitKey(0);
            Cv2.Dilate(binary, morp, kernel, new Point(-1, -1));
            Cv2.ImShow("Dilate", morp); Cv2.WaitKey(0);
            Cv2.Erode(morp, morp, kernel, new Point(-1, -1), 3);
            Cv2.ImShow("Erode", morp); Cv2.WaitKey(0);
            Cv2.Dilate(morp, morp, kernel, new Point(-1, -1), 2);
            Cv2.ImShow("Dilate", morp); Cv2.WaitKey(0);
            Cv2.Canny(morp, canny, 0, 0, 3);
            Cv2.ImShow("Canny", canny); Cv2.WaitKey(0);

            LineSegmentPoint[] lines = Cv2.HoughLinesP(canny, 1, Cv2.PI / 180, 140, 50, 10);

            for(int i = 0; i < lines.Length; i++)
            {
                Cv2.Line(dst, lines[i].P1, lines[i].P2, Scalar.Yellow, 2);
            }

            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
