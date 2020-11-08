using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _25_Sobel
    {
        static void Main(string[] args)
        {
            Mat src = Cv2.ImRead("../../img/book.jpg", ImreadModes.Grayscale);
            Mat dst = new Mat();
            Mat dst1 = new Mat();
            Cv2.Sobel(src, dst, MatType.CV_8UC1, 1, 0, 3, 1, 0, BorderTypes.Reflect101);

            Cv2.PyrDown(dst, dst);
            Cv2.ImShow("dst", dst);

            Cv2.Canny(src, dst1, 100, 200);
            Cv2.PyrDown(dst1, dst1);
            Cv2.ImShow("dst1", dst1);

            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
