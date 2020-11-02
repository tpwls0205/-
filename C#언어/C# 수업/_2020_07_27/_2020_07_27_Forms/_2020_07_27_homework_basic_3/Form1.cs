using System;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_27_homework_basic_3
{
    public partial class Form1 : Form
    {
        const int DIA = 300;
        Timer timer = new Timer();
        Image[] image = new Image[5];
        int imageCnt = 0;

        public Form1()
        {
            InitializeComponent();
            this.Paint += Form1_Paint1;
            this.Load += Form1_Load1;
            timer.Interval = 1000;
            timer.Tick += Timer_Tick1;
        }

        private void Form1_Load1(object sender, EventArgs e)
        {
            for (int i = 0; i < 5; i++)
            {
                string str = "../../";
                str += (i + ".jpg");
                image[i] = Image.FromFile(str);
            }
            timer.Start();
        }

        private void Timer_Tick1(object sender, EventArgs e)
        {
            if (imageCnt == 5)
            {
                imageCnt = 0;
            }
            Invalidate();
        }

        private void Form1_Paint1(object sender, PaintEventArgs e)
        {
            TextureBrush tbrush = new TextureBrush(image[imageCnt]);
            e.Graphics.FillEllipse(tbrush, 10, 10, DIA, DIA);
            Pen pen = new Pen(Brushes.DarkBlue, 5);
            e.Graphics.DrawEllipse(pen, 10, 10, DIA, DIA);
            imageCnt++;
        }
    }
}