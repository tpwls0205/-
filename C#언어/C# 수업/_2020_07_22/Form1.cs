using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_22
{
    public partial class Form1 : Form
    {
        Timer timer = new Timer();
        Random r = new Random();
        private int x = 30, y = 30;    // 지렁이 좌표
        private int speed = 10;
        private int widthX = 20, heightY = 20; // 지렁이 몸체 하나의 크기
        private int boxX = 20, boxY = 20;
        private int cnt = 0; // box의 개수
        public Form1()
        {   
            this.Paint += Form1_Paint;
            this.Load += Form1_Load;
            this.KeyDown += Form1_KeyDown;
            timer.Interval = 500;
            timer.Tick += Timer_Tick;
            InitializeComponent();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch(e.KeyCode)
            {
                case Keys.Enter:
                    timer.Start();
                    break;
                case Keys.Left:
                    this.x -= speed;
                    break;
                case Keys.Right:
                    this.x += speed;
                    break;
                case Keys.Up:
                    this.y -= speed;
                    break;
                case Keys.Down:
                    this.y += speed;
                    break;
            }
            Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.BackColor = Color.Black;
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Pen myPen = new Pen(Brushes.White, 2);
            Rectangle rc = this.ClientRectangle;
            rc.Inflate(-20, -20);
            g.DrawRectangle(myPen, rc);
            Pen mypen = new Pen(Brushes.Blue, 2);
            g.DrawRectangle(mypen, this.x, this.y, widthX, heightY);
            if (cnt == 0)
            {
                for (int i = 0; i < 10; i++)
                {
                    int x = r.Next(300);
                    g.DrawRectangle(myPen, x, x, boxX, boxY);
                }
            }
        }
    }
}
