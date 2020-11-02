using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2020_07_21_homework_1_1
{
    class saveImage
    {
        public int click { get; set; }
        public int mX { get; set; }
        public int mY { get; set; }
        public saveImage(int _c, int _x, int _y) { click = _c; mX = _x; mY = _y; }
    }

    public partial class Form1 : Form
    {
        //List<saveImage> SaveI = new List<saveImage>(10);  //배열선언 저장공간
        saveImage[] SaveI = new saveImage[20];
        Image image = null;
        Image image1 = null;
        int MouseX = 0;
        int MouseY = 0;
        int idx = 0; //  배열 안 요소 번호

        //public override System.Drawing.Color BackColor { get; set; }

        public Form1()
        {
            InitializeComponent();
            BackColor = Color.Black;
            this.DoubleBuffered = true;
            this.Load += Form1_Load;
            this.Paint += Form1_Paint;
            this.MouseDown += Form1_MouseDown;
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            int type = 0;
            if (e.Button == MouseButtons.Left) type = 0;
            else if (e.Button == MouseButtons.Right) type = 1;
            MouseX = e.X; MouseY = e.Y;
            //SaveI.Add(new saveImage(type, MouseX, MouseY));
            SaveI[idx++] = new saveImage(type, MouseX, MouseY);
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            //Console.WriteLine(SaveI.Count);
            //for (int j = 0; j < SaveI.Count; j++)
            //{
            //    if (0 == SaveI[j].click)
            //        e.Graphics.DrawImage(image, SaveI[j].mX, SaveI[j].mY);
            //    else
            //        e.Graphics.DrawImage(image1, SaveI[j].mX, SaveI[j].mY);
            //}
            Console.WriteLine(idx);
            for (int j = 0; j < idx; j++)
            {
                if (0 == SaveI[j].click)
                    e.Graphics.DrawImage(image, SaveI[j].mX, SaveI[j].mY);
                else
                    e.Graphics.DrawImage(image1, SaveI[j].mX, SaveI[j].mY);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.image = Image.FromFile("../../cat.jpg");
            this.image1 = Image.FromFile("../../puppy.jpg");
        }
    }
}
