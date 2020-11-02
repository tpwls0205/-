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

namespace _2020_07_16_homework_4
{
        public partial class Form1 : Form
    {
        const int RAD = 100;
        const int MOVE_VAL = 20;
        int x = 0, y = 0;
        Timer timer = new Timer();
        public Form1()
        {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.KeyDown += Form1_KeyDown;
            timer.Interval = 100;
            timer.Tick += Timer_Tick;
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            int cnt = 0;
            if(Keys.Enter == e.KeyCode && cnt == 0)
            {
                timer.Start();
                cnt ++;
            }
            if (cnt == 1)
            {
                switch (e.KeyCode)
                {
                    case Keys.Enter:

                        break;
                }
            }
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            x += MOVE_VAL;

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
