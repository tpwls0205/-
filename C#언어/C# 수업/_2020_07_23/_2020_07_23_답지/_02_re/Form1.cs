using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _02_re
{
    public partial class Form1 : Form
    {
        /// ///////////// 뱀
        List<user> snake = new List<user>();
        List<user> hood = new List<user>();
        Random r = new Random();
        int Back1X = 0, Back1Y = 0;
        int Back2X = 780, Back2Y = 820;
        const int boxSize = 20, moveBack = 50;
        const int widthMap = 817, HeightMap = 880;
        const int userStart = 120, useStartTail = 5;
        int moveY = 20;
        int moveX = 20;
        Timer timer = new Timer();

        Pen myPen = null;
        Pen userPen = null;

        /// ///////////// 공
        bool chekPoint = true;

        int ballLeft, ballTop;
        const int BALL_SIZE = 30; // const가 붙은 애는 static 적용이 된다.
        double speed = 100;             // 초속
        double degree = 75;             // 각도
        const double G = 9.80665D;      // 중력가속도
        Brush ballBrush = Brushes.Green;
        double x, y;
        bool fire = false;
        double radian;
        double t = 0;
        Stopwatch st = new Stopwatch();

        public Form1()
        {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.Load += Form1_Load;
            this.KeyDown += Form1_KeyDown;
            this.timer.Interval = 50;
            this.timer.Tick += Timer_Tick;
            st.Start();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            if (fire)
            {
                x = speed * Math.Cos(radian) * t;
                y = (this.speed * Math.Sin(radian) * t) - (G * t * t * 0.5);
                y = -y;
                t += 0.5;
            }
            
            for (int j = 0; j < hood.Count; j++)
            {
                if (ballLeft + x - 30 <= hood[j].X && ballLeft + x + 30 >= hood[j].X &&
                    ballTop + y - 30 <= hood[j].Y && ballTop + y + 30 >= hood[j].Y)
                {
                    hood.RemoveAt(j);
                }
            }

            if (y > this.ClientRectangle.Bottom)
            {
                fire = false; t = 0;
                ballLeft = snake[snake.Count - 1].X + moveX;
                ballTop = snake[snake.Count - 1].Y - 5;
            }
            Invalidate();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Left || e.KeyCode == Keys.Right || e.KeyCode == Keys.Down || e.KeyCode == Keys.Up)
            {
                snake.Add(new user());
                snake[snake.Count - 1].X = snake[snake.Count - 2].X;
                snake[snake.Count - 1].Y = snake[snake.Count - 2].Y;
                snake[snake.Count - 1].Tail = snake[snake.Count - 2].Tail;
                snake[snake.Count - 1].TailMove = snake[snake.Count - 2].TailMove;
            }


            switch (e.KeyCode)
            {
                case Keys.Left:
                    moveX = -20;
                    snake[snake.Count - 1].X += moveX;
                    ChkP();
                    Remove();
                    break;
                case Keys.Right:
                    moveX = 20;
                    snake[snake.Count - 1].X += moveX;
                    Remove();
                    if (!fire)
                    {
                        ballLeft = snake[snake.Count - 1].X + moveX;
                        ballTop = snake[snake.Count - 1].Y - 5;
                    }
                    chekPoint = true;
                    break;
                case Keys.Up:
                    moveY = -20;
                    snake[snake.Count - 1].Y += moveY;
                    Remove();
                    ChkP();
                    break;
                case Keys.Down:
                    moveY = 20;
                    snake[snake.Count - 1].Y += moveY;
                    Remove();
                    ChkP();
                    break;
                case Keys.W:
                    if (!fire)
                        degree += 5;
                    break;
                case Keys.S:
                    if (!fire)
                        degree -= 5;
                    break;
                case Keys.A:
                    if (!fire)
                        speed -= 5;
                    break;
                case Keys.D:
                    if (!fire)
                        if (timer.Interval > 5)
                        {
                            speed += 2;
                            timer.Interval -= 5;
                        }
                    break;
                case Keys.Enter:
                    {
                      if(chekPoint)
                        fire = true;
                        break;
                    }
            }
            radian = degree * Math.PI / 180;
            Invalidate();
        }

        private void ChkP()
        {
            chekPoint = false;
        }
        private void Remove()
        {
            if (snake.Count > snake[snake.Count - 1].Tail)
            {
                snake.RemoveAt(0);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.Width = widthMap;
            this.Height = HeightMap;
            this.DoubleBuffered = true;
            this.BackColor = Color.Black;
            myPen = new Pen(Brushes.White, 3);
            userPen = new Pen(Brushes.Red, 3);
            for (int i = 0; i < useStartTail; i++)
            {
                snake.Add(new user());
                snake[i].X = userStart + i * boxSize;
                snake[i].Y = userStart;
                snake[i].Tail = useStartTail;
            }
            for (int i = 0; i < useStartTail * 2; i++)
            {
                hood.Add(new user());
                hood[i].X = r.Next(360) + 400;
                hood[i].Y = r.Next(770) + 30;
            }
            radian = degree * Math.PI / 180;
            ballLeft = snake[snake.Count - 1].X + moveX;
            ballTop = snake[snake.Count - 1].Y - 5;
            timer.Start();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            for (int i = 0; i < widthMap / boxSize; i++)
            {
                e.Graphics.DrawRectangle(myPen, Back1X, Back1Y, boxSize, boxSize);
                e.Graphics.DrawRectangle(myPen, Back1X, Back2Y, boxSize, boxSize);
                Back1X += boxSize;
            }
            Back1X = 0;
            for (int i = 0; i < HeightMap / boxSize - 3; i++)
            {
                e.Graphics.DrawRectangle(myPen, Back1X, Back1Y, boxSize, boxSize);
                e.Graphics.DrawRectangle(myPen, Back2X, Back1Y, boxSize, boxSize);
                Back1Y += boxSize;
            }
            Back1Y = 0;
            for (int j = 0; j < snake.Count; j++)
            {
                e.Graphics.DrawRectangle(userPen, snake[j].X, snake[j].Y, boxSize, boxSize);
                e.Graphics.FillEllipse(Brushes.Red, snake[j].X, snake[j].Y, boxSize, boxSize);
            }
            for (int j = 0; j < hood.Count; j++)
            {
                e.Graphics.FillEllipse(Brushes.GreenYellow, hood[j].X, hood[j].Y, boxSize, boxSize);
            }
            if (chekPoint && !fire) e.Graphics.FillEllipse(this.ballBrush, this.ballLeft, this.ballTop, BALL_SIZE, BALL_SIZE);
            if (fire)
            {
                e.Graphics.FillEllipse(Brushes.Gold, (float)(x + this.ballLeft), (float)(y + this.ballTop), BALL_SIZE, BALL_SIZE);
            }
            if (hood.Count == 0)
            { st.Stop(); timer.Stop(); e.Graphics.DrawString("Game Clear", new Font("맑은 고딕", 50), Brushes.White, widthMap / 2-150, HeightMap / 2-100); };
         
            e.Graphics.DrawString(st.Elapsed.ToString(), new Font("맑은 고딕", 20), Brushes.Red, Back2X-250, Back2Y-50) ;
        }


        class user
        {
            public int X
            { get; set; }
            public int Y
            { get; set; }
            public int Tail
            { get; set; }
            public int TailMove
            { get; set; } = 0;
        }
    }
}
