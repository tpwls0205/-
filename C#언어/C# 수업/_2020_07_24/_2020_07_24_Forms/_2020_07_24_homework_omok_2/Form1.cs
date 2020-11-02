using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_24_homework_omok_2
{
    public partial class Form1 : Form
    {
        int x, y = 0;                   // 현재 마우스 좌표
        int[][] omok = new int[100][];  // 놓은 돌의 좌표
        int cnt = 0;                    // 참조배열 순서
        int color = 1;                  // 흑돌(1) 백돌(-1) 순서
        const int k = 40;               // 한칸당 x,y 거리
        string str_b = "흑승";
        string str_w = "백승";
        int black_cnt = 1;
        int bingo = 0;
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

            for (int i = 0; i <= 20; i++)
            {
                for (int j = 0; j <= 20; j++)
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
                    // 흑돌 승리조건 omok[i][2] == 1 이 5번 연속으로 존재
                    //x - k * 5 ~x + k * 5 || y - k * 5 ~y + k * 5 || x - k * 5 && y - k * 5 ~x + k * 5 && y + k * 5 || x - k * 5 && y + k * 5 ~x + k * 5 && y - k * 5
                    for (int j = 0; j <= -5; j--)
                    {
                        if (omok[i + j][2] == 1 && (omok[i + j][0] == k || omok[i + j][1] == k))
                        {
                            bingo++;
                            Console.WriteLine("bingo : {0} ", bingo);
                            if (bingo == 5)
                            {
                                Console.WriteLine("흑돌승리");
                            }
                        }
                    }
                }
                else if (omok[i][2] == -1)
                {
                    g.FillEllipse(Brushes.White, omok[i][0], omok[i][1], k, k);
                }
            }

            //for (int k = 0; k < cnt; k++)
            //{
            //    for (int i = 0; i <= 20; i++)
            //    {
            //        for (int j = 0; j <= 20; j++)
            //        {
            //            if (omok[j][2] == 1)
            //            {
            //                black_cnt++;
            //            }
            //            else
            //            {
            //                black_cnt = 0;
            //            }
            //            if (black_cnt == 5)
            //            {
            //                MessageBox.Show(str_b);
            //            }
            //        }
            //    }
            //}
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