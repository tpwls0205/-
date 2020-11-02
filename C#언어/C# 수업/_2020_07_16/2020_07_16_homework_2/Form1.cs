using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

//1. 화면에 양쪽 대각선 X로 그릴 것

//2. 키보드로 원을 이동시 원이 화면 영역을 벗어나지 못하도록 할 것

//3. 방향키로 사각형 색칠하기

//4. 타이머를 이용해서 자동으로 원 움직이기

//5. 설계도를 보고 Address App 완성하기

namespace _2020_07_16_homework_2
{
    public partial class Form1 : Form
    {
        const int RAD = 50;
        int x = 10, y = 10;
        const int MOVE_VAL = 10;
        public Form1()
        {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.KeyDown += Form1_KeyDown;
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Left:
                    if (this.ClientRectangle.Left < this.x)
                    { 
                        this.x -= MOVE_VAL;
                    }
                    break;
                case Keys.Right:
                if (this.ClientRectangle.Right - 50 > this.x)
                    {
                        this.x += MOVE_VAL;
                    }
                    break;
                case Keys.Up:
                    if (this.ClientRectangle.Top < this.y)
                    {
                        this.y -= MOVE_VAL;
                    }
                    break;
                case Keys.Down:
                    if (this.ClientRectangle.Bottom - 50 > this.y)
                    {
                        this.y += MOVE_VAL;
                    }
                    break;
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
