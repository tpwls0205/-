using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_23_homework_2
{
    public partial class Form1 : Form
    {
        int ballLeft, ballTop;
        int barLeft, barTop;
        const int BAR_SIZE = 30;
        const int BALL_SIZE = 30;
        double speed = 100;        // 초속 // 단축키
        double degree = 45;        // 각도 // 단축키
        const int MOVE_VAL = 20;
        const int MOVE_BAR = 10;
        const double G = 9.80665D; // 중력가속도
        Brush ballBrush = Brushes.Yellow;

        Random random = new Random();
        Timer timer = new Timer();

        public Form1()
        {
            InitializeComponent();
            this.Load += Form1_Load;
            this.KeyDown += Form1_KeyDown;
            this.Paint += Form1_Paint;
            timer.Interval = 100;
            timer.Tick += Timer_Tick;
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            barLeft = ballLeft - BALL_SIZE*2;
            barTop = ballTop;
            e.Graphics.FillEllipse(this.ballBrush, this.ballLeft, this.ballTop, BALL_SIZE, BALL_SIZE);
            e.Graphics.FillRectangle(Brushes.White, this.barLeft, this.barTop, BAR_SIZE * 2, BAR_SIZE);
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Space:
                    {
                        Graphics g = CreateGraphics();      // 임시로 그래픽을 만들수있다

                        for (int t = 0; ; t++)
                        {
                            double x, y;
                            g.Clear(Color.Black);   // 한번 돌때마다 검은색으로 칠한다.
                            double radian = this.degree * Math.PI / 180;
                            x = this.speed * Math.Cos(radian) * t;
                            y = (this.speed * Math.Sin(radian) * t) - (G * t * t * 0.5);
                            y = -y;     // y축이 Catersian 좌표에 반대라서
                            g.FillRectangle(Brushes.White, this.barLeft, this.barTop, BAR_SIZE * 2, BAR_SIZE);
                            g.FillEllipse(Brushes.Gold,
                                (float)(x + this.ballLeft),
                                (float)(y + this.ballTop),
                                BALL_SIZE, BALL_SIZE);
                            if (y > this.ClientRectangle.Bottom)
                            {
                                break;
                            }

                            System.Threading.Thread.Sleep(100);
                        }
                        g.Dispose();    // 소멸자 대신 .NET Class에서는 소멸자의 호출시점을 정확하게 알 수 없으므로
                                        // 대신에 IDisposable을 상속받게 해서
                                        // 사용하지 않을 때는 Dispose()메서드를 호출해서
                                        // 객체 내부의 리소스를 해제하도록 한다
                    }
                    break;
                case Keys.W:       // 각도
                    degree += MOVE_VAL;
                    break;
                case Keys.S:     // 각도
                    degree -= MOVE_VAL;
                    break;
                case Keys.A:     // 속도
                    speed -= MOVE_VAL;
                    break;
                case Keys.D:    // 속도
                    speed += MOVE_VAL;
                    break;
                case Keys.Up:
                    this.ballTop -= MOVE_BAR;
                    this.barTop -= MOVE_BAR;
                    break;
                case Keys.Down:
                    this.ballTop += MOVE_BAR;
                    this.barTop += MOVE_BAR;
                    break;
                case Keys.Left:
                    this.ballLeft -= MOVE_BAR;
                    this.barLeft -= MOVE_BAR;
                    break;
                case Keys.Right:
                    this.ballLeft += MOVE_BAR;
                    this.barLeft += MOVE_BAR;
                    break;
            }
            Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.BackColor = Color.Black;
            this.ballLeft = this.Width / 10;        // form크기의 10분에 1 지점
            this.ballTop = this.Height / 10 * 7;    // 상단을 기준으로 10분에 9 지점
        }
    }
}
