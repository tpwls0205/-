using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

//1. 화면에 양쪽 대각선 X로 그릴 것

//2. 키보드로 원을 이동시 원이 화면 영역을 벗어나지 못하도록 할 것

//3. 방향키로 사각형 색칠하기

//4. 타이머를 이용해서 자동으로 원 움직이기

//5. 설계도를 보고 Address App 완성하기

namespace _2020_07_16_homework_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.Paint += Form1_Paint1;
            this.Layout += Form1_Layout;
        }

        private void Form1_Layout(object sender, LayoutEventArgs e)
        {
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            // this.ClientRectangle는 Form클래스로부터 상속받은
            // 현재 화면크기를 나타내는 구조체

            Graphics g = e.Graphics;
            Pen myPen = new Pen(Brushes.Red, 10);
            g.DrawLine(myPen, 0, 0, this.ClientRectangle.Right, this.ClientRectangle.Bottom);
        }

        private void Form1_Paint1(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Pen myPen = new Pen(Brushes.Red, 10);
            g.DrawLine(myPen, this.ClientRectangle.Right, this.ClientRectangle.Top, this.ClientRectangle.Left, this.ClientRectangle.Bottom);
        }

    }
}
