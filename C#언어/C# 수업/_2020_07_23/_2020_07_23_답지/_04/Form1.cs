using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _04
{
    public partial class Form1 : Form
    {
        const int FORM_WIDTH = 1000;
        const int FORM_HEIGHT = 1000;
        const int BUTTON_SIZE = 50;
        int rows, cols;
        int cnt = 0;
        Bitmap image = new Bitmap("../../1.jpg");
        Bitmap resize = null;
        Timer timer = new Timer();
        List<chek> chekTime = new List<chek>();
        int i = 0;

        public Form1()
        {
            InitializeComponent();
            this.Load += Form1_Load;
            this.timer.Interval = 50;
            this.timer.Tick += Timer_Tick;
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            for (int j = 0; j < chekTime.Count; j++)
            {
                foreach (Control ii in Controls)
                    if (ii.Text == chekTime[j].Num1)
                    { chekTime[j].Num2 -= 50; if (chekTime[j].Num2 == 0) { ii.Dispose();/*chekTime.RemoveAt(j);*//*i--;*/ } }
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.Width = FORM_WIDTH + 18;
            this.Height = FORM_HEIGHT + 38;

            this.rows = FORM_WIDTH / BUTTON_SIZE;
            this.cols = FORM_HEIGHT / BUTTON_SIZE;
            resize = new Bitmap(image, 50, 50);
            MakeButtons();
        }

        private void MakeButtons()
        {
            Random r = new Random();
            for (int i = 0; i < this.rows; i++)  // 세로 행
            {
                for (int j = 0; j < this.cols; j++)  // 가로 열
                {
                    Button btn = new Button();
                    btn.Text = cnt++.ToString();
                    btn.Left = j * BUTTON_SIZE;
                    btn.Top = i * BUTTON_SIZE;
                    btn.Width = BUTTON_SIZE;
                    btn.Height = BUTTON_SIZE;
                    btn.Margin = new Padding(0);
                    btn.BackColor = Color.FromArgb(255, r.Next(256), r.Next(256), r.Next(256));
                    btn.Font = new Font("맑은 고딕", 10, FontStyle.Bold);
                    btn.Click += Btn_Click;
                    this.Controls.Add(btn);
                }
            }
        }
        // 버튼 클릭시 화면 이지미가 폭탄이미지로 변경
        // 1초 후 버튼이 사라지게
        private void Btn_Click(object sender, EventArgs e)
        {
            Button btn = sender as Button;
            if (btn != null)
            {
                Console.WriteLine(btn.Text);
                btn.Image = resize;
                chekTime.Add(new chek());
                chekTime[i].Num1 = btn.Text;
                chekTime[i].Num2 = 1000;
                i++;
                timer.Start();
                //foreach(Control A in )
            }
        }
    }
    public class chek
    {
        public string Num1
        { get; set; }
        public int Num2
        { get; set; }
    }
}
