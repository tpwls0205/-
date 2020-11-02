using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _05_prac_SelectRectShowCircleToColor {
    public partial class Form1 : Form {

        const int BOX_WID = 100;
        bool swap = false;
        bool[,,] witchBoxClick = new bool[4, 8, 2];

        public Form1() {
            InitializeComponent();

            this.Paint += Form1_Paint;
            this.Layout += Form1_Layout;
            this.MouseDown += Form1_MouseDown;

            this.DoubleBuffered = true;
        }

        private void Form1_Layout(object sender, LayoutEventArgs e) {
            Invalidate();
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e) {
            if (e.Button == MouseButtons.Left) {
                for (int y = 0; y < 4; y++) {
                    for (int x = 0; x < 8; x++) {
                        if (e.X > BOX_WID * x && e.X < BOX_WID * (x + 1) &&
                            e.Y > BOX_WID * y && e.Y < BOX_WID * (y + 1)) {
                            witchBoxClick[y, x, 0] = true;
                            witchBoxClick[y, x, 1] = swap;
                        }
                    }
                }
                swap = !swap;
            }
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Graphics g = e.Graphics;

            Pen boxPen = new Pen(Brushes.Black, 2);
            Pen cir1Pen = new Pen(Brushes.Blue, 1);
            Pen cir2Pen = new Pen(Brushes.Red, 1);

            Rectangle[,] rc = new Rectangle[4, 8];

            for (int y = 0; y < 4; y++) {
                for (int x = 0; x < 8; x++) {
                    rc[y, x] = new Rectangle(BOX_WID * x, BOX_WID * y, BOX_WID, BOX_WID);

                    g.DrawRectangle(boxPen, rc[y, x]);

                    if (witchBoxClick[y, x, 0]) {
                        if (witchBoxClick[y, x, 1])
                            g.DrawEllipse(cir1Pen, BOX_WID * x, BOX_WID * y, BOX_WID, BOX_WID);
                        else
                            g.DrawEllipse(cir2Pen, BOX_WID * x, BOX_WID * y, BOX_WID, BOX_WID);
                    }
                }
            }

        }


    }
}