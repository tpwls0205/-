using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_21_homework_3_1
{
        public partial class Form1 : Form
        {
            private const int WIDTH = 130;
            private const int HEIGHT = 110;
            Random R = new Random();
            Timer timer = new Timer();
            private int num = 0;
            public Form1()
            {
                InitializeComponent();
                this.Paint += Form1_Paint;
                timer.Interval = 500;
                timer.Tick += Timer_Tick;
                this.Load += Form1_Load;
            }

            private void Form1_Load(object sender, EventArgs e)
            {
                timer.Start();
            }

            private void Timer_Tick(object sender, EventArgs e)
            {
                this.num = R.Next(3);
                Invalidate();   //Paint 메서드로 이동
            }

            private void Form1_Paint(object sender, PaintEventArgs e)
            {
                Graphics g = e.Graphics;
                Rectangle rc = this.ClientRectangle;
                rc.Inflate(-20, -20);
                g.FillRectangle(Brushes.Black, rc);
                Pen myPen = new Pen(Brushes.White, 2);
                g.DrawEllipse(myPen, 25, 25, WIDTH, HEIGHT);
                g.DrawEllipse(myPen, 25, 135, WIDTH, HEIGHT);
                g.DrawEllipse(myPen, 25, 245, WIDTH, HEIGHT);

                if (num == 0)
                {
                    g.FillEllipse(Brushes.Red, 25, 25, WIDTH, HEIGHT);
                }
                if (num == 1)
                {
                    g.FillEllipse(Brushes.Yellow, 25, 135, WIDTH, HEIGHT);
                }
                if (num == 2)
                {
                    g.FillEllipse(Brushes.Green, 25, 245, WIDTH, HEIGHT);
                }
            }
        }
    }