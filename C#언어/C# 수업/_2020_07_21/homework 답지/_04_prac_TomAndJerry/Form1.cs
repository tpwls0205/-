using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _04_prac_TomAndJerry {
    public partial class Form1 : Form {
        float catX = 50, catY = 50;
        const float catSpeed = 5;
        bool isMouse = false;
        float mouseX, mouseY;
        Timer timer = new Timer();
        Image catImg = Image.FromFile("../../cat.jpg");
        Image dogImg = Image.FromFile("../../puppy.jpg");
        public Form1() {
            InitializeComponent();

            this.Paint += Form1_Paint;
            this.MouseDown += Form1_MouseDown;
            this.MouseUp += Form1_MouseUp;
            this.MouseMove += Form1_MouseMove;

            timer.Interval = 1;
            timer.Tick += Timer_Tick;

            this.DoubleBuffered = true;
        }

        private void Timer_Tick(object sender, EventArgs e) {
            if (isMouse) {
                if (catX < mouseX)
                    catX += catSpeed;
                else if (catX == mouseX) { }
                else
                    catX -= catSpeed;

                if (catY < mouseY)
                    catY += catSpeed;
                else if (catY == mouseY) { }
                else
                    catY -= catSpeed;
            }
            Invalidate();
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e) {
            if (isMouse) {
                this.mouseX = e.X;
                this.mouseY = e.Y;
            }
            Invalidate();
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e) {
            if (e.Button == MouseButtons.Left) {
                this.isMouse = false;
            }
            Invalidate();
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e) {
            if (e.Button == MouseButtons.Left) {
                this.isMouse = true;
                this.mouseX = e.X;
                this.mouseY = e.Y;
            }
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Graphics g = e.Graphics;

            timer.Start();
            g.DrawImage(dogImg, catX, catY);

            if (this.isMouse)
                g.DrawImage(catImg, mouseX, mouseY);


        }
    }
}
