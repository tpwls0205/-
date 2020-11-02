using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_17_homework_4
{
    public partial class Form1 : Form
    {
        int cnt = 0;
        const int RAD = 50;
        int x = 10, y = 10;
        int x1 = 350, y1 = 350;
        const int MOVE_VAL = 10;
        const int MOVE_VAL1 = 30;
        Timer timer = new Timer();
        bool dirx = true;
        bool diry = true;
        int width = 100;
        int height = 30;
        public Form1()
        {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.KeyDown += Form1_KeyDown;
            timer.Interval = 10;
            timer.Tick += Timer_Tick;
            timer.Start();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch(e.KeyCode)
            {
                case Keys.Left:
                    this.x1 -= MOVE_VAL1;
                    break;
                case Keys.Right:
                    this.x1 += MOVE_VAL1;
                    break;
                case Keys.Up:
                    this.y1 -= MOVE_VAL1;
                    break;
                case Keys.Down:
                    this.y1 += MOVE_VAL1;
                    break;
            }
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            if (this.ClientRectangle.Bottom - 50 < this.y || this.ClientRectangle.Top > this.y)
            {
                diry = !diry;
                if(this.ClientRectangle.Bottom - 50 < this.y)
                {
                    cnt -= 1;
                    Console.WriteLine(cnt);
                }
            }
            if (this.ClientRectangle.Right - 50 < this.x || this.ClientRectangle.Left > this.x)
            {
                dirx = !dirx;
            }
            if (diry)
            {
                this.y += MOVE_VAL;
                if (this.x >= this.x1 && this.x <= this.x1 + width && this.y >= this.y1 && this.y <= this.y1 + height)
                {
                    diry = !diry;
                    cnt += 1;
                }
            }
            if (dirx)
            {
                this.x += MOVE_VAL;
                if (this.x >= this.x1 && this.x <= this.x1 + width && this.y >= this.y1 && this.y <= this.y1 + height)
                {
                    dirx = !dirx;
                    cnt += 1;
                }
            }
            if (!diry)
            {
                this.y -= MOVE_VAL;
                if (this.x >= this.x1 && this.x <= this.x1 + width && this.y >= this.y1 && this.y <= this.y1 + height)
                {
                    diry = true;
                    cnt += 1;
                }
            }
            if (!dirx)
            {
                this.x -= MOVE_VAL;
                if (this.x >= this.x1 && this.x <= this.x1 + width && this.y >= this.y1 && this.y <= this.y1 + height)
                {
                    dirx = true;
                    cnt += 1;
                }
            }
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Pen myPen = new Pen(Brushes.DarkBlue, 5);
            g.DrawEllipse(myPen, x, y, RAD, RAD);
            g.DrawRectangle(myPen, x1, y1, width, height);
            //g.DrawString(cnt, Font, Brushes.Black, 650, 10);
        }
    }
}
