using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.VisualStyles;

namespace _2020_07_27_homework_basic_1
{
    public partial class Form1 : Form
    {
        int x, y = 0;
        bool color = false;
        public Form1()
        {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.MouseClick += Form1_MouseClick; ;
        }
        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            this.x = e.X;
            this.y = e.Y;
            if (this.x >= 100 && this.y >= 100 && this.x <= 250 && this.y <= 250)
            {
                color = !color;
            }
            Invalidate();
        }
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Pen pen = new Pen(Brushes.DarkBlue, 7);
            e.Graphics.DrawEllipse(pen, 100, 100, 250, 250);
            if (color == true)
            {
                e.Graphics.FillEllipse(Brushes.Pink, 100, 100, 250, 250);
            }
        }
    }
}
