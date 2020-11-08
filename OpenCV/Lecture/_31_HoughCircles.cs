using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _31_HoughCircles
    {
        static void Main(string[] args)
        {
            Mat src = Cv2.ImRead("../../img/colorball.png");
            Mat image = new Mat();
            Mat dst = src.Clone();

            Mat kernel = Cv2.GetStructuringElement(MorphShapes.Rect, new Size(3, 3));
            Cv2.ImShow("src", src); Cv2.WaitKey(0);
            Cv2.CvtColor(src, image, ColorConversionCodes.BGR2GRAY);
            Cv2.ImShow("image", image); Cv2.WaitKey(0);
            Cv2.Dilate(image, image, kernel, new Point(-1, -1), 3);
            Cv2.ImShow("Dilate", image); Cv2.WaitKey(0);
            Cv2.GaussianBlur(image, image, new Size(13, 13), 3, 3, BorderTypes.Reflect101);
            Cv2.ImShow("GaussianBlur", image); Cv2.WaitKey(0);
            Cv2.Erode(image, image, kernel, new Point(-1, -1), 3);
            Cv2.ImShow("Erode", image); Cv2.WaitKey(0);

            CircleSegment[] circles = Cv2.HoughCircles(image, HoughMethods.Gradient, 1, 100, 100, 35, 0, 0);

            for(int i = 0; i < circles.Length; i++)
            {
                Point center = new Point(circles[i].Center.X, circles[i].Center.Y);

                Cv2.Circle(dst, center, (int)circles[i].Radius, Scalar.White, 3);
                Cv2.Circle(dst, center, 5, Scalar.AntiqueWhite, Cv2.FILLED);
            }

            Cv2.ImShow("dst", dst); Cv2.WaitKey(0);
            
            Cv2.DestroyAllWindows();
        }
    }
}
