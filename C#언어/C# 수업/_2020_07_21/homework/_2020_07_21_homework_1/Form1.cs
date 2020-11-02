using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_21_homework_1
{
    public partial class Form1 : Form
    {
        Image image = null;                        
        Image image1 = null;
        private int x, y = 0;
        private const int height = 100, width = 100;
        int[][] ar = new int[100][];
        int cnt = 0;

        public Form1()
        {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.MouseClick += Form1_MouseClick;
            this.Load += Form1_Load;
            this.DoubleBuffered = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.BackColor = Color.Black;
            image = Properties.Resources.강아지;
            image1 = Properties.Resources.고양이;
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            ar[cnt] = new int[3];
            if (e.Button == MouseButtons.Left)
            {
                this.x = e.X - width/2;
                this.y = e.Y - height/2;
                ar[cnt][2] = 0;
            }
            else if(e.Button == MouseButtons.Right)
            {
                this.x = e.X - width/2;
                this.y = e.Y - height/2;
                ar[cnt][2] = 1;
            }
            ar[cnt][0] = this.x;
            ar[cnt][1] = this.y;
            cnt++;
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            for (int i = 0; i < cnt; i++)
            {
                if (ar[i][2] == 0)
                {  
                    g.DrawImage(image, ar[i][0], ar[i][1], width, height);
                }
                else if (ar[i][2] == 1)
                {
                    g.DrawImage(image1, ar[i][0], ar[i][1], width, height);
                }
            }
        }
    }
}
