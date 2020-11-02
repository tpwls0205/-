using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _02_prac_Animation {
    public partial class Form1 : Form {
        Image img = null;
        Timer timer = new Timer();
        int cnt = 0;
        int x = 100, y = 100;
        public Form1() {
            InitializeComponent();

            this.Paint += Form1_Paint;
            this.Load += Form1_Load;
            this.Layout += Form1_Layout;
            this.MouseClick += Form1_MouseClick;
            this.KeyDown += Form1_KeyDown;

            timer.Interval = 1000;
            timer.Tick += Timer_Tick;
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e) {
            switch (e.KeyCode) {
                case Keys.Left:
                    x -= 20;
                    break;
                case Keys.Right:
                    x += 20;
                    break;
            }
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e) {
            x = e.X;
            y = e.Y;
            Invalidate();
        }

        private void Timer_Tick(object sender, EventArgs e) {
            ++cnt;
            Invalidate();
        }

        private void Form1_Layout(object sender, LayoutEventArgs e) {
            Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e) {
            img = Image.FromFile("../../ani.png");
            this.BackColor = Color.Black;
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            timer.Start();
            e.Graphics.DrawImage(img, x- img.Width/5/2, y - img.Height/2, 
                new Rectangle(img.Width / 5 * (cnt%5), 0, img.Width/5 , img.Height), 
                GraphicsUnit.Pixel);
        }
    }
}
