using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_28_homework_2
{
    public partial class Form1 : Form
    {
        int x, y, mx, my;
        public Form1()
        {
            InitializeComponent();
            this.DoubleBuffered = true;
            this.MouseMove += Form1_MouseMove;
            this.MouseDown += Form1_MouseDown;
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.x = e.X;
                this.y = e.Y;
            }
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {   
            this.mx = e.X;
            this.my = e.Y;
            Graphics g = CreateGraphics();
            if (e.Button == MouseButtons.Left)
            {
                g.DrawLine(new Pen(Brushes.Black, 1), mx, my, x, y);
                this.x = this.mx;
                this.y = this.my;
            }
        }
    }
}
