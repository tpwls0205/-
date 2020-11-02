using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_21_homework_2
{
    public partial class Form1 : Form
    {
        int x, y = 0;   // x, y는 주전자 좌표
        int move = 10;  // 키보드 이동거리
        Timer timer = new Timer();
        private Image image = null;
        int cnt = 0;

        public Form1()
        {
            InitializeComponent();
            this.Load += Form1_Load;
            this.KeyDown += Form1_KeyDown;
            this.MouseDown += Form1_MouseDown;
            this.Paint += Form1_Paint;
            this.DoubleBuffered = true;
            timer.Interval = 50;
            timer.Tick += Timer_Tick;
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            ++cnt;
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            g.DrawImage(image, x - image.Width / 5 / 2 , y - image.Height / 2,
                new Rectangle(image.Width / 5 * (cnt % 5), 0, image.Width / 5, image.Height),
                GraphicsUnit.Pixel);
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            this.x = e.X;
            this.y = e.Y;
            Invalidate();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch(e.KeyCode)
            {
                case Keys.Left:
                    this.x -= move;
                    break;
                case Keys.Right:
                    this.x += move;
                    break;
                case Keys.Up:
                    this.y -= move;
                    break;
                case Keys.Down:
                    this.y += move;
                    break;
            }
            Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.BackColor = Color.Black;
            image = Properties.Resources.ani;
            timer.Start();
        }
    }
}
