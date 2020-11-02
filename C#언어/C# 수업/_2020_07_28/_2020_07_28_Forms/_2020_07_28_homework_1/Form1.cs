using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_28_homework_1
{
    public partial class Form1 : Form
    {
        List<Line> line = new List<Line>(); 
        int x, y, mx, my;
        bool state = false;
        public Form1()
        {
            InitializeComponent();
            this.DoubleBuffered = true;
            this.Load += Form1_Load;
            this.MouseMove += Form1_MouseMove;
            this.MouseDown += Form1_MouseDown;
            this.MouseUp += Form1_MouseUp;
            this.Paint += Form1_Paint;
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            if(state==true)
                e.Graphics.DrawLine(new Pen(Brushes.White, 10), x, y, mx, my);
            for (int i = 0; i < line.Count; i++)
                e.Graphics.DrawLine(new Pen(Brushes.White, 10), line[i].sx, line[i].sy, line[i].ex, line[i].ey);
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            line.Add(new Line(x, y, e.X, e.Y));     // sx, sy, ex, ey
            state = false;          
            Invalidate();
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            this.x = e.X;  
            this.y = e.Y;
            state = true;
            //Invalidate();
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            //if (state == false) return; // 안눌렀어도 마우스좌표는 이동한다.
            mx = e.X; my = e.Y;
            Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.BackColor = Color.Blue;
        }
    }
    class Line
    {
        public int sx { get; set; }
        public int sy { get; set; }
        public int ex { get; set; }
        public int ey { get; set; }
        public Line(int x1, int y1, int x2, int y2)
        {
            sx = x1; sy = y1; ex = x2; ey = y2;
        }
    }
}
