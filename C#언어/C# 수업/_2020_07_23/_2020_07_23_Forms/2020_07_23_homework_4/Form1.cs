using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_23_homework_4
{
    public partial class Form1 : Form
    {
        const int FORM_WIDTH = 1000;
        const int FORM_HEIGHT = 1000;
        const int BUTTON_SIZE = 100;
        int rows, cols;
        int cnt = 0;
        Image image = null;
        public Form1()
        {
            InitializeComponent();
            this.Load += Form1_Load;

        }
        private void Form1_Load(object sender, EventArgs e)
        {
            this.Width = FORM_WIDTH + 18;
            this.Height = FORM_HEIGHT + 18;
            this.rows = FORM_WIDTH / BUTTON_SIZE;
            this.cols = FORM_WIDTH / BUTTON_SIZE;
            MakeButtons();

        }
        private void MakeButtons()
        {
            Random random = new Random();
            
            for (int i = 0; i < this.rows; i++) //세로행
            {
                for (int j = 0; j < this.cols; j++) //가로행
                { 
                    Button btn = new Button();
                    btn.Left = j * BUTTON_SIZE;
                    btn.Top = i * BUTTON_SIZE;
                    btn.Width = BUTTON_SIZE;
                    btn.Height = BUTTON_SIZE;
                    btn.Margin = new Padding(0); //여백없애기
                    btn.Text = cnt++.ToString(); //숫자가 문자로

                    btn.BackColor = Color.FromArgb(255,
                                        random.Next(256), random.Next(256), random.Next(256));  //(불투명,색상설정)


                    btn.Font = new Font("맑은 고딕", 12, FontStyle.Bold);
                    btn.Click += Btn_Click; // 이벤트핸들러인데 함수를 넘겨준다. ?

                    this.Controls.Add(btn); // 리스트비슷한 무언가. ?
                }
            }
        }
        //버튼클릭시 폭탄이미지 설정후
        //1초안에 사라지게 하기
        //뒷배경이 나올 수 있게
        private void Btn_Click(object sender, EventArgs e)
        {
            Button btn = sender as Button;  // as = 샌더를 버튼처럼 쓰겠다. is = 샌더가 버튼이냐?
            if (btn != null)                // 버튼이 아니면 null이 나온다
            {
                image = Image.FromFile("../../bomb.jpg");
                btn.Image = image.GetThumbnailImage(BUTTON_SIZE, BUTTON_SIZE, null, IntPtr.Zero);
                this.Refresh();         // ?
                Thread.Sleep(1000);
                btn.Visible = false;    // 버튼을 안보이게한다.
            }
        }
    }
}