using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _01_prac_ClickPositionImage {
    public partial class Form1 : Form {
        float x, y;
        Image img = null;
        bool isClick = false;
        Graphics g;
        public Form1() {
            InitializeComponent();

            this.MouseClick += Form1_MouseClick;
            this.Paint += Form1_Paint;
            this.Load += Form1_Load;
        }

        private void Form1_Load(object sender, EventArgs e) {
            this.BackColor = Color.Black;
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e) {
            switch (e.Button) {
                case MouseButtons.Left:
                    x = e.X;
                    y = e.Y;
                    img = Image.FromFile("../../puppy.jpg");
                    isClick = true;
                    break;
                case MouseButtons.Right:
                    x = e.X;
                    y = e.Y;
                    img = Image.FromFile("../../cat.jpg");
                    isClick = true;
                    break;
            }

        }

    private void Form1_Paint(object sender, PaintEventArgs e) {
            //g = e.Graphics;
            
            if (isClick) {
                e.Graphics.DrawImage(img, x, y);
                //g.DrawImage(img, x, y);
            }
        }
    }
}
