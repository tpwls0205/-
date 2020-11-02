using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_17_homework_3
{
    public partial class Form1 : Form
    {
        const int RAD = 50;
        int x = 10, y = 10;
        const int MOVE_VAL = 10;
        Timer timer = new Timer();
        bool dirx = true;
        bool diry = true;
        public Form1()
        {
            InitializeComponent();
            this.Paint += Form1_Paint;
            timer.Interval = 10;
            timer.Tick += Timer_Tick;
            timer.Start();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            if(this.ClientRectangle.Bottom-50 < this.y || this.ClientRectangle.Top > this.y)
            {
                diry = !diry;
            }
            if(this.ClientRectangle.Right-50 < this.x || this.ClientRectangle.Left > this.x)
            {
                dirx = !dirx;
            }
            if(diry)
            {
                this.y += MOVE_VAL;
            }
            if(dirx)
            {
                this.x += MOVE_VAL;
            }
            if(!diry)
            {
                this.y -= MOVE_VAL;
            }
            if(!dirx)
            {
                this.x -= MOVE_VAL;
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
