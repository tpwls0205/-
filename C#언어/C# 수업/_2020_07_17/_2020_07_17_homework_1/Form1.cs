using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_17_homework_1
{
    public partial class Form1 : Form
    {
        const int RAD = 50;
        int x = 10, y = 100;
        const int MOVE_VAL = 10;
        Timer timer = new Timer();
        int i = 0;
        public Form1()
        {
            InitializeComponent();
            this.Paint += Form1_Paint;
            timer.Interval = 100;
            timer.Tick += Timer_Tick;
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            timer.Start();
            if (this.ClientRectangle.Right - 50 > this.x && i == 0)
            {
                x += MOVE_VAL;
                if (this.ClientRectangle.Right - 50 <= this.x)
                {
                    i = 1;
                }
            }
            if (this.ClientRectangle.Left < this.x && i ==1)
            {
                x -= MOVE_VAL;
                if(this.ClientRectangle.Left >= this.x)
                {
                    i = 0;
                }
            }
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Pen myPen = new Pen(Brushes.DarkBlue, 5);
            g.DrawEllipse(myPen, x, y, RAD, RAD);
        }
    }
}