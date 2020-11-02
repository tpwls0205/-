using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_17_homework_5
{
    public partial class Form1 : Form
    {
        private bool isSelEllipse = false; // 왼쪽 마우스 눌렀니?
        public Form1()
        {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.MouseDown += Form1_MouseDown;
            this.Load += Form1_Load;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.BackColor = Color.White;
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                isSelEllipse = true;
                Invalidate();
            }
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Pen myPen = new Pen(Color.Black, 5);
            Rectangle rc = this.ClientRectangle;
            g.DrawRectangle(myPen, rc);
            // 가로 7, 세로 3
            g.DrawLine(myPen, 100, 0, 100, 450);
            g.DrawLine(myPen, 200, 0, 200, 450);
            g.DrawLine(myPen, 300, 0, 300, 450);
            g.DrawLine(myPen, 400, 0, 400, 450);
            g.DrawLine(myPen, 500, 0, 500, 450);
            g.DrawLine(myPen, 600, 0, 600, 450);
            g.DrawLine(myPen, 700, 0, 700, 450);
            g.DrawLine(myPen, 0, 90, 800, 90);
            g.DrawLine(myPen, 0, 180, 800, 180);
            g.DrawLine(myPen, 0, 270, 800, 270);
            g.DrawLine(myPen, 0, 360, 800, 360);

            if (this.isSelEllipse)
            {
                myPen = new Pen(Color.Aquamarine, 10);
                g.DrawEllipse(myPen, 0,0,90,100);
            }

        }
    }
}
