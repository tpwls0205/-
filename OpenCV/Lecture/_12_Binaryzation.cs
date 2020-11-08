using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _12_Binaryzation
    {
        static void Main(string[] args)
        {
            //Mat src = Cv2.ImRead("../../img/swan.jpg");
            //Mat src = Cv2.ImRead("../../img/coins.png");
            //Mat src = Cv2.ImRead("../../img/neutrophils.png");
            Mat src = Cv2.ImRead("../../img/flower.jpg");
            Mat gray = new Mat(src.Size(), MatType.CV_8UC1);
            Mat binary = new Mat(src.Size(), MatType.CV_8UC1);

            Cv2.CvtColor(src, gray, ColorConversionCodes.BGR2GRAY);
            Cv2.Threshold(gray, binary, 127, 255, ThresholdTypes.Otsu);

            Cv2.Resize(binary, binary, new Size(1024, 768), 0, 0, InterpolationFlags.Linear);
            Cv2.ImShow("binary", binary);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
