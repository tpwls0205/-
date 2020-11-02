using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_28_homework_3
{
    public partial class Form1 : Form
    {
        Timer timer = new Timer();
        int sx, sy, mx, my;
        bool state = false;
        bool moveState = false;
        Bitmap bitmap = new Bitmap("../../blueCar.jpg");

        public Form1()
        {
            InitializeComponent();
            this.DoubleBuffered = true;
            this.MouseDown += Form1_MouseDown;
            this.MouseMove += Form1_MouseMove;
            this.MouseUp += Form1_MouseUp;
            this.Paint += Form1_Paint;
            this.Load += Form1_Load;
            timer.Interval = 1;
            timer.Tick += Timer_Tick;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string image = "../../backRoad.jpg";
            this.BackgroundImage = Image.FromFile(image);
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            if (moveState == true)
            {
                e.Graphics.DrawImage(bitmap, mx, my, 80, 120);
            }
            if (state == true)
            {
                e.Graphics.DrawImage(bitmap, sx, sy, 80, 120);
            }
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            Invalidate();
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.mx = e.X;
                this.my = e.Y;
                moveState = true;
                state = false;
                Invalidate();
            }
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.sx = e.X;
                this.sy = e.Y;
                state = true;
                //Invalidate();
            }
        }
    }
}


