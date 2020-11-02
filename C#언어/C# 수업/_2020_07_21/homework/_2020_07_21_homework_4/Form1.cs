using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_21_homework_4
{
    public partial class Form1 : Form
    {
        Timer timer = new Timer();
        int catX, catY, mouseX, mouseY;
        bool mouseClicked = false;
        Image image = null;
        Image image1 = null;

        public Form1()
        {
            catX = 30; catY = 50;
            BackColor = Color.White;
            InitializeComponent();
            timer.Interval = 50;
            this.DoubleBuffered = true;
            this.Paint += Form1_Paint;
            this.MouseDown += Form1_MouseDown;
            this.MouseUp += Form1_MouseUp;
            this.MouseMove += Form1_MouseMove;
            image = Properties.Resources.mouse;
            image1 = Properties.Resources.cat;
            timer.Tick += Timer_Tick;
            timer.Start();
        }
        private void Timer_Tick(object sender, EventArgs e)
        {
            if (mouseClicked == true)
            {
                int difX = mouseX - catX, difY = mouseY - catY;
                catX += difX / 10; catY += difY / 10;
                Invalidate();
            }
        }
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawImage(image1, catX, catY, 50, 50);
            if (mouseClicked == true)
            {
                e.Graphics.DrawImage(image, mouseX - 15, mouseY - 15, 50, 50);
            }
        }
        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            mouseClicked = true;
            mouseX = e.X; mouseY = e.Y;
            Invalidate();
        }
        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            mouseClicked = false;
            Invalidate();
        }
        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            mouseX = e.X; mouseY = e.Y;
        }
    }
}
