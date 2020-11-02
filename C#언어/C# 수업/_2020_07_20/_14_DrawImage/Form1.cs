using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _14_DrawImage
{
    public partial class Form1 : Form
    {
        Image image = null;
        public Form1()
        {
            InitializeComponent();
            this.DoubleBuffered = true;                 // 깜빡임 제거
            this.Paint += Form1_Paint;                  // 그리기
            this.Layout += Form1_Layout;                // 폼 크기 변경
            this.Load += Form1_Load;                    // 초기화 셋팅
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            image = Image.FromFile("../../장.jpg");
        }

        private void Form1_Layout(object sender, LayoutEventArgs e)
        {
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            //e.Graphics.DrawImage(image, 0, 0);  // 원본크기
            //e.Graphics.DrawImage(image, this.ClientRectangle);  // 화면에 맞추는 크기
            //e.Graphics.DrawImage(image, this.ClientRectangle.Right / 4, this.ClientRectangle.Bottom / 4
            //    , this.ClientRectangle.Width / 2, this.ClientRectangle.Height / 2);
            e.Graphics.DrawImage(image, 50, 50, new Rectangle(70, 10, 130, 140), GraphicsUnit.Pixel);
            // new Rectangle : 이미지의 추출범위
        }
    }
}
