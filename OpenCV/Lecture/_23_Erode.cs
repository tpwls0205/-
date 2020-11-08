using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _23_Erode
    {
        static void Main(string[] args)
        {
            Mat src = Cv2.ImRead("../../img/dandelion.jpg", ImreadModes.Grayscale);
            Mat dst = new Mat();

            Mat kernel = Cv2.GetStructuringElement(MorphShapes.Cross, new Size(7, 7));
            Cv2.Erode(src, dst, kernel, new Point(-1, -1), 3, BorderTypes.Reflect101, new Scalar(0));
            Cv2.PyrDown(src, src);
            Cv2.ImShow("src", src);
            Cv2.PyrDown(dst, dst);
            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
