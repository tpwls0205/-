using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Collections;

namespace _2020_07_30_homework_1
{
    public partial class Form1 : Form
    {
        int imgX;
        int imgY;
        int x1 = 0;
        int x2 = 0;
        int x3 = 0;
        List<int> winner = new List<int>();
        bool bool1 = true;
        bool bool2 = true;
        bool bool3 = true;
        int move = 100;
        private Image image1 = Properties.Resources.박보영;
        private Image image2 = Properties.Resources.아이유;
        private Image image3 = Properties.Resources.장나라;
        Random rand = new Random();
        string name1 = "박보영 승리";
        string name2 = "아이유 승리";
        string name3 = "장나라 승리";
        

        public Form1()
        {
            InitializeComponent();
            this.MouseDoubleClick += Form1_MouseDoubleClick;
            this.Paint += Form1_Paint;
            this.BackColor = Color.Black;
            this.Load += Form1_Load;
            
        }
        
        private void Form1_Load(object sender, EventArgs e)
        {
            this.DoubleBuffered = true;
            imgX = ClientRectangle.Right / 8;
            imgY = ClientRectangle.Bottom / 3;
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawImage(image1, x1, 0, imgX, imgY);
            e.Graphics.DrawImage(image2, x2, imgY, imgX, imgY);
            e.Graphics.DrawImage(image3, x3, imgY * 2, imgX, imgY);
            e.Graphics.DrawLine(new Pen(Brushes.Yellow, 2), 0, imgY, ClientRectangle.Right, imgY);
            e.Graphics.DrawLine(new Pen(Brushes.Yellow, 2), 0, imgY * 2, ClientRectangle.Right, imgY * 2);
            if (winner.Count > 0)
            {
                if (winner[0] == 1)
                {
                    e.Graphics.Clear(Color.Black);
                    e.Graphics.DrawString(name1, new Font("돋움", 50), Brushes.White, (ClientRectangle.Right / 2) - 50, ClientRectangle.Bottom / 2);
                }
                else if (winner[0] == 2)
                {
                    e.Graphics.Clear(Color.Black);
                    e.Graphics.DrawString(name2, new Font("돋움", 50), Brushes.White, (ClientRectangle.Right / 2) - 50, ClientRectangle.Bottom / 2);
                }
                else if (winner[0] == 3)
                {
                    e.Graphics.Clear(Color.Black);
                    e.Graphics.DrawString(name3, new Font("돋움", 50), Brushes.White, (ClientRectangle.Right / 2) - 50, ClientRectangle.Bottom / 2);
                }
            }
        }

        private void Form1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                Thread t = new Thread(new ThreadStart(ThreadProc1));
                Thread r = new Thread(new ThreadStart(ThreadProc2));
                Thread y = new Thread(new ThreadStart(ThreadProc3));
                t.Start();
                r.Start();
                y.Start();
            }
        }

        void ThreadProc1()
        {
            while (winner.Count==0)
            {
                if(bool1)
                {
                    this.x1 += move+50;
                    Thread.Sleep(rand.Next(150));
                    if(this.x1 + imgX >= ClientRectangle.Right)
                    {
                        bool1 = !bool1;
                    }
                }
                else
                {
                    this.x1 -= move+50;
                    Thread.Sleep(rand.Next(150));
                    if(this.x1 <= 0)
                    {
                        winner.Add(1);
                        break;
                    }
                }
                Invalidate();
            }
        }
        void ThreadProc2()
        {
            while (winner.Count == 0)
            {
                if (bool2)
                {
                    this.x2 += move;
                    Thread.Sleep(rand.Next(150));
                    if (this.x2 + imgX >= ClientRectangle.Right)
                    {
                        bool2 = !bool2;
                    }
                }
                else
                {
                    this.x2 -= move;
                    Thread.Sleep(rand.Next(150));
                    if (this.x2 <= 0)
                    {
                        winner.Add(2);
                        break;
                    }
                }
                Invalidate();
            }
        }
        void ThreadProc3()
        {
            while (winner.Count == 0)
            {
                if (bool3)
                {
                    this.x3 += move;
                    Thread.Sleep(rand.Next(150));
                    if (this.x3 + imgX >= ClientRectangle.Right)
                    {
                        bool3 = !bool3;
                    }
                }
                else
                {
                    this.x3 -= move;
                    Thread.Sleep(rand.Next(150));
                    if (this.x3 <= 0)
                    {
                        winner.Add(3);
                        break;
                    }
                }
                Invalidate();
            }
        }
    }
}