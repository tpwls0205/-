using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _03
{
    public partial class Form1 : Form
    {
        Timer timer = new Timer();
        Bitmap bitmap = new Bitmap("../../backRoad.jpg");
        Bitmap resize;
        Size size = new Size(700, 700);
        int map = 700;
        int moveOne = 0;
        Bitmap bitmapCar = new Bitmap("../../silverCar.jpg");
        Bitmap resizeCar;
        int carX, carY;
        bool car = false;
      
        public Form1()
        {
            InitializeComponent();
            this.timer.Interval = 1;
            this.timer.Tick += Timer_Tick;
            this.Paint += Form1_Paint;
            this.Load += Form1_Load;
            this.MouseDown += Form1_MouseDown;
            this.MouseMove += Form1_MouseMove;
            this.MouseUp += Form1_MouseUp;
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            car = false;
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if(car)
            {            
                carX = e.X;
                carY = e.Y;
            }
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            if (carX <= e.X && e.X <= carX+80 && carY <= e.Y && e.Y <= carY+120)
            {
                carX = e.X;
                carY = e.Y;
                car = true;
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            resize = new Bitmap(bitmap, size);
            resizeCar = new Bitmap(bitmapCar, 80,120);
            this.Width = map+10;
            this.Height = map+10;
            timer.Start();
            this.DoubleBuffered = true;
            carX = Width / 2;
            carY = Height / 2;
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawImage(resize,0, moveOne, new Rectangle(0, 0, map, map), GraphicsUnit.Pixel);
            e.Graphics.DrawImage(resize, 0, 0, new Rectangle(0, map-moveOne, map, map), GraphicsUnit.Pixel);
            // GraphicsUnit.Pixel : 사진을 짜른다.  y : 700인데, 1초당 10픽셀씩 짤라서 출력
            e.Graphics.DrawImage(resizeCar, carX-40, carY-60);
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            moveOne += 10;
            if (moveOne > 700)
            {
                moveOne = 0;
            }
            Invalidate();
        }
    }
}
