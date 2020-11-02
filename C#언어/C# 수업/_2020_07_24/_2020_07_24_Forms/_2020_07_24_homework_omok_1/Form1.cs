using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_24_homework_omok_1
{
    public partial class Form1 : Form
    {
        int x, y = 0;                   // 현재 마우스 좌표
        int[][] omok = new int[100][];  // 놓은 돌의 좌표
        int cnt = 0;                    // 참조배열 순서
        int color = 1;                  // 흑돌(1) 백돌(-1) 순서
        public Form1()
        {
            InitializeComponent();
            this.MouseClick += Form1_MouseClick;
            this.Paint += Form1_Paint;
            this.Load += Form1_Load;
            this.DoubleBuffered = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.Width = 860;
            this.Height = 880;
            this.BackColor = Color.BurlyWood;
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            // 배열을 쓴다.
            // 20x20 = 400칸 
            int k = 40;     // 한칸당 x,y 거리
            omok[cnt] = new int[3];
            Graphics g = e.Graphics;
            Pen myPen = new Pen(Brushes.Black, 2);
            Rectangle rc = ClientRectangle;

            for (int i = 0; i <= 20; i++)
            {
                g.DrawLine(myPen, 0, k * i, rc.Right, k * i);
            }
            for (int j = 0; j <= 20; j++)
            {
                g.DrawLine(myPen, k * j, 0, k * j, rc.Bottom);
            }

            for (int i = 0; i <=20; i++)
            {
                for (int j = 0; j <=20; j++)
                {
                    if (this.x > i * k && this.y > j * k && this.x < (i + 1) * k && this.y < (j + 1) * k)
                    {
                        this.x = i * k;
                        this.y = j * k;
                        omok[cnt][0] = this.x;
                        omok[cnt][1] = this.y;
                        omok[cnt][2] = color;
                        color *= -1;
                        cnt++;
                    }
                }
            }
            for (int i = 0; i < cnt; i++)
            {
                if (omok[i][2] == 1)
                {
                    g.FillEllipse(Brushes.Black, omok[i][0], omok[i][1], k, k);
                    
                }
                else if (omok[i][2] == -1)
                {
                    g.FillEllipse(Brushes.White, omok[i][0], omok[i][1], k, k);

                }
            }
        }


    private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.x = e.X;
                this.y = e.Y;
            }
            Invalidate();
        }
    }
}