﻿using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpOpenCV
{
    class _27_ApproxPolyDP
    {
        static void Main(string[] args)
        {
            Mat src = Cv2.ImRead("../../img/chess.png");
            Mat gray = new Mat();
            Mat binary = new Mat();
            Mat morp = new Mat();
            Mat image = new Mat();
            Mat dst = src.Clone();

            Mat kernel = Cv2.GetStructuringElement(MorphShapes.Rect, new Size(3, 3));
            Point[][] contours;
            HierarchyIndex[] hierarchy;

            Cv2.ImShow("src", src);Cv2.WaitKey(0);            
            Cv2.CvtColor(src, gray, ColorConversionCodes.BGR2GRAY);
            Cv2.ImShow("gray", gray); Cv2.WaitKey(0);
            Cv2.Threshold(gray, binary, 230, 255, ThresholdTypes.Binary);
            Cv2.ImShow("binary", binary); Cv2.WaitKey(0);
            Cv2.MorphologyEx(binary, morp, MorphTypes.Close, kernel, new Point(-1, -1), 2);
            Cv2.ImShow("morp", morp); Cv2.WaitKey(0);
            Cv2.BitwiseNot(morp, image);
            Cv2.ImShow("image", image); Cv2.WaitKey(0);

            Cv2.FindContours(image, out contours, out hierarchy, RetrievalModes.Tree, ContourApproximationModes.ApproxTC89KCOS);

            for(int i = 0; i < contours.Length; i++)
            {
                double perimeter = Cv2.ArcLength(contours[i], true);
                double epsilon = perimeter * 0.01;

                Point[] approx = Cv2.ApproxPolyDP(contours[i], epsilon, true);
                Point[][] draw_approx = new Point[][] { approx };
                Cv2.DrawContours(dst, draw_approx, -1, new Scalar(255, 0, 0), 2, LineTypes.AntiAlias);
                //Cv2.ImShow("dst", dst); Cv2.WaitKey(0);
                for (int j = 0; j < approx.Length; j++)
                {
                    Cv2.Circle(dst, approx[j], 1, new Scalar(0, 0, 255), 3);
                    //Cv2.ImShow("dst", dst); Cv2.WaitKey(0);
                }
            }

            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
