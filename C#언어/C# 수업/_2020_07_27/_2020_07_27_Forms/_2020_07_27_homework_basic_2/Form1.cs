using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_27_homework_basic_2
{

    public partial class Form1 : Form
    {
        const int DIA = 300;
        Image[] image = new Image[5];
        int imageCnt = 0;
        int x, y = 0;

        public Form1()
        {
            InitializeComponent();
            this.Paint += Form1_Paint1;
            this.Load += Form1_Load1;
            this.MouseClick += Form1_MouseClick;
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            this.x = e.X;
            this.y = e.Y;
            if (this.x >= 10 && this.y >= 10 && this.x <= 310 && this.y <= 310)
            {
                imageCnt++;
            }
            if (imageCnt == 5)
            {
                imageCnt = 0;
            }
            Invalidate();
        }

        private void Form1_Load1(object sender, EventArgs e)
        {
            for (int i = 0; i < 5; i++)
            {
                string str = "../../";
                str += (i + ".jpg");
                image[i] = Image.FromFile(str);
            }
        }

        private void Form1_Paint1(object sender, PaintEventArgs e)
        {
            TextureBrush tbrush = new TextureBrush(image[imageCnt]);
            e.Graphics.FillEllipse(tbrush, 10, 10, DIA, DIA);
            Pen pen = new Pen(Brushes.DarkBlue, 5);
            e.Graphics.DrawEllipse(pen, 10, 10, DIA, DIA);
        }
    }
}
