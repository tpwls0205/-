using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_27_homework_1
{
    public partial class Form1 : Form
    {
        int centX, centY;       // 중심좌표
        int timerX = 20;        // 왼쪽상단 타이머좌표
        int timerY = 20;        // 왼쪽상단 타이머좌표
        double sx, sy;
        double mx, my;
        double hx, hy;
        const int RADIUS = 200; // 원의 반지름
        const int RADIUS_M = 150;
        const int RADIUS_H = 100;
        DateTime dt = DateTime.Now; // 현재시간값
        Timer timer = new Timer();  // 타이머

        public Form1()
        {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.Load += Form1_Load;
            timer.Interval = 1000;  //1초
            timer.Tick += Timer_Tick;
            DoubleBuffered = true;
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            dt = DateTime.Now;
            int sec = dt.Second;
            int min = dt.Minute;
            int hour = dt.Hour;

            sx = this.centX + (RADIUS * Math.Cos(6 * (sec - 15) * Math.PI / 180));
            sy = this.centY + (RADIUS * Math.Sin(6 * (sec - 15) * Math.PI / 180));
            mx = this.centX + (RADIUS_M * Math.Cos(6 * (min - 15) * Math.PI / 180));
            my = this.centY + (RADIUS_M * Math.Sin(6 * (min - 15) * Math.PI / 180));
            hx = this.centX + (RADIUS_H * Math.Cos(30 * (hour - 2.5) * Math.PI / 180));
            hy = this.centY + (RADIUS_H * Math.Sin(30 * (hour - 2.5) * Math.PI / 180));
            Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.BackColor = Color.Black;
            this.centX = this.Width / 2;
            this.centY = this.Height / 2;
            dt = DateTime.Now;
            int sec = dt.Second;
            int min = dt.Minute;
            int hour = dt.Hour;
            sx = this.centX + (RADIUS * Math.Cos(6 * (sec - 15) * Math.PI / 180));
            sy = this.centY + (RADIUS * Math.Sin(6 * (sec - 15) * Math.PI / 180));
            mx = this.centX + (RADIUS_M * Math.Cos(6 * (min - 15) * Math.PI / 180));
            my = this.centY + (RADIUS_M * Math.Sin(6 * (min - 15) * Math.PI / 180));
            hx = this.centX + (RADIUS_H * Math.Cos(30 * (hour - 2.5) * Math.PI / 180));
            hy = this.centY + (RADIUS_H * Math.Sin(30 * (hour - 2.5) * Math.PI / 180));
            timer.Start();
        }

        void DrawWatchEllipse(Graphics g, int cnt)
        {
            g.FillEllipse(Brushes.White, new RectangleF((float)centX - 10, (float)centY - 10, 20, 20));
            Pen pen = new Pen(Brushes.Gold, 10);
            int degree = 360 / cnt;             // 몇도씩 움직일 것인지

            for (int i = 0; i < 360; i += degree)
            {
                double x = this.centX + (RADIUS * Math.Cos(i * Math.PI / 180));
                double y = this.centY + (RADIUS * Math.Sin(i * Math.PI / 180));
                g.DrawEllipse(pen, new RectangleF((float)x - 20, (float)y - 20, 40, 40));
                g.FillEllipse(Brushes.Blue, new RectangleF((float)x - 20, (float)y - 20, 40, 40));
            }

            Font font = new Font("Arial", 20);
            int clock = 3;
            for (int i = 0; i < 360; i += degree)
            {
                double x = this.centX + (RADIUS * Math.Cos(i * Math.PI / 180));
                double y = this.centY + (RADIUS * Math.Sin(i * Math.PI / 180));
                string num = Convert.ToString(clock);
                g.DrawString(num, font, Brushes.White, (float)x - 20, (float)y - 20);
                clock++;
                if (clock == 13)
                {
                    clock = 1;
                }
            }

        }

        void DrawWatchLine(Graphics g, int cnt)
        {
            int degree = 360 / cnt;  
            for (int i = 0; i < 360; i += degree)
            {
                double x = this.centX + (RADIUS * Math.Cos(i * Math.PI / 180));
                double y = this.centY + (RADIUS * Math.Sin(i * Math.PI / 180));
                g.FillEllipse(Brushes.White, new RectangleF((float)x - 5, (float)y - 5, 10, 10));
            }
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Font font = new Font("Arial", 32);
            Pen penSec = new Pen(Brushes.SkyBlue, 3);
            Pen penMin = new Pen(Brushes.Green, 6);
            Pen penHour = new Pen(Brushes.Yellow, 9);
            DrawWatchLine(e.Graphics, 360);
            DrawWatchEllipse(e.Graphics, 12);
            e.Graphics.DrawString(dt.ToString("HH:mm:ss"), font, Brushes.White, timerX, timerY);
            e.Graphics.DrawLine(penSec, this.centX, this.centY, (float)sx, (float)sy);
            e.Graphics.DrawLine(penMin, this.centX, this.centY, (float)mx, (float)my);
            e.Graphics.DrawLine(penHour, this.centX, this.centY, (float)hx, (float)hy);
        }
    }
}
