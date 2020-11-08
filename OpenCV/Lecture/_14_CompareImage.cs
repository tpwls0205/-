using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _14_CompareImage
    {
        static void Main(string[] args)
        {
            Mat src1 = Cv2.ImRead("../../img/gerbera.jpg");
            Mat dst = new Mat(src1.Size(), MatType.CV_8UC3);

            Cv2.ImShow("src", src1);

            Cv2.Compare(src1, new Scalar(200, 127, 100), dst, CmpTypes.GT);
            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
