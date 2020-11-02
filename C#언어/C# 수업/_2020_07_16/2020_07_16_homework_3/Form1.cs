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

namespace _2020_07_16_homework_3
{
    public partial class Form1 : Form
    {
        int i = 0;
        public Form1()
        {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.KeyDown += Form1_KeyDown;
            this.KeyUp += Form1_KeyUp;
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            if(i==1||i==2||i==3||i==4)
            {
                i = 0;
            }
   
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Left:
                    i = 1;
                    break;
                case Keys.Right:
                    i = 2;
                    break;
                case Keys.Up:
                    i = 3;
                    break;
                case Keys.Down:
                    i = 4;
                    break;
            }
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Rectangle rc = new Rectangle();
            Pen myPen = new Pen(Brushes.Black, 3);
            Font f = new Font("맑은 고딕", 10);
            rc.Width = 50;
            rc.Height = 50;

            rc.X = 40;
            rc.Y = 90;
            g.DrawRectangle(myPen, rc); // 왼쪽
            g.DrawString("왼쪽", f, Brushes.DarkBlue, rc);
            if (i == 1)
            {
                g.FillRectangle(Brushes.Aquamarine, rc);
                g.DrawString("왼쪽", f, Brushes.DarkBlue, rc);
            }
            if (i == 0)
            {
                g.FillRectangle(Brushes.White, rc);
            }


            rc.X = 140;
            rc.Y = 90;
            g.DrawRectangle(myPen, rc); // 오른쪽
            g.DrawString("오른쪽", f, Brushes.DarkBlue, rc);
            if (i == 2)
            {
                g.FillRectangle(Brushes.Yellow, rc);
                g.DrawString("오른쪽", f, Brushes.DarkBlue, rc);
            }
            if (i == 0)
            {
                g.FillRectangle(Brushes.White, rc);
            }


            rc.X = 90;
            rc.Y = 40;
            g.DrawRectangle(myPen, rc); // 위쪽
            g.DrawString("위쪽", f, Brushes.DarkBlue, rc);
            if (i == 3)
            {
                g.FillRectangle(Brushes.Green, rc);
                g.DrawString("위쪽", f, Brushes.DarkBlue, rc);
            }
            if (i == 0)
            {
                g.FillRectangle(Brushes.White, rc);
            }



            rc.X = 90;
            rc.Y = 140;
            g.DrawRectangle(myPen, rc); // 아래쪽
            g.DrawString("아래쪽", f, Brushes.DarkBlue, rc);
            if (i == 4)
            {
                g.FillRectangle(Brushes.Purple, rc);
                g.DrawString("아래쪽", f, Brushes.DarkBlue, rc);
            }
            if (i == 0)
            {
                g.FillRectangle(Brushes.White, rc);
            }



        }
    }
}
