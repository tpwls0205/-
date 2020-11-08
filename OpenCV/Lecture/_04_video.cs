using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _04_video
    {
        static void Main(string[] args)
        {
            VideoCapture capture = new VideoCapture("../../img/Star.mp4");
            Mat frame = new Mat();

            while (true)
            {
                if (capture.PosFrames == capture.FrameCount)
                    capture.Open("../../img/Star.mp4");

                capture.Read(frame);
                Cv2.ImShow("VideoFrame", frame);

                if (Cv2.WaitKey(33) == 'q')
                    break;
            }

            capture.Release();
            Cv2.DestroyAllWindows();
        }
    }
}
