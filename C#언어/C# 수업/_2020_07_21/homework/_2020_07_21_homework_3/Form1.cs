using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_21_homework_3
{
    public partial class Form1 : Form
    {
        Timer timer = new Timer();
        Random r = new Random();
        int num = 0;
        public Form1()
        {
            InitializeComponent();
            this.Load += Form1_Load;
            this.Paint += Form1_Paint;
            timer.Interval = 1000;
            timer.Tick += Timer_Tick;
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            this.num = r.Next(3);   // 0~2사이 난수생성
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Pen mypen = new Pen(Brushes.Black, 5);
            g.DrawRectangle(mypen, 10, 10, 100, 300);
            g.FillRectangle(Brushes.Black, 10, 10, 100, 300);
            Pen myPen = new Pen(Brushes.White, 2);
            g.DrawEllipse(myPen, 10, 10, 100, 100);
            g.DrawEllipse(myPen, 10, 110, 100, 100);
            g.DrawEllipse(myPen, 10, 210, 100, 100);
            if(this.num == 0)
            {
                g.FillEllipse(Brushes.Red, 10, 10, 100, 100);
            }
            else if(this.num == 1)
            {
                g.FillEllipse(Brushes.Yellow, 10, 110, 100, 100);
            }
            else if(this.num == 2)
            {
                g.FillEllipse(Brushes.Green, 10, 210, 100, 100);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            timer.Start();
        }
    }
}
