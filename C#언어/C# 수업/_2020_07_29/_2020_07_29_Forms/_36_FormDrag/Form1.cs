﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _36_FormDrag
{
    public partial class Form1 : Form
    {
        Point mousePoint;

        public Form1()
        {
            InitializeComponent();

            this.MouseDown += Form1_MouseDown;
            this.MouseMove += Form1_MouseMove;
            this.MouseDoubleClick += Form1_MouseDoubleClick;
            this.MouseClick += Form1_MouseClick;
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Right)
            {
                DialogResult result = MessageBox.Show("종료하시겠습니까?", "Really?", MessageBoxButtons.YesNo);
                if(result == DialogResult.Yes)
                {
                    this.Close();
                }
            }
        }

        private void Form1_MouseDoubleClick(object sender, MouseEventArgs e)
        {   // 더블클릭하면 최대화와 노말 크기 변동
            if(this.WindowState == FormWindowState.Maximized)
            {
                this.WindowState = FormWindowState.Normal;
            }
            else
            {
                this.WindowState = FormWindowState.Maximized;        
            }
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                int moveX = e.X - this.mousePoint.X;
                int moveY = e.Y - this.mousePoint.Y;
                this.Location = new Point(this.Left + moveX, this.Top + moveY); // Location : 좌상단 포인트 좌표
            }
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            this.mousePoint = new Point(e.X, e.Y);
        }
    }
}
