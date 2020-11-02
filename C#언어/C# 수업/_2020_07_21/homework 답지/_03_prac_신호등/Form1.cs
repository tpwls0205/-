using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _03_prac_신호등 {
    public partial class Form1 : Form {
        const float WIDTH = 100, HEIGHT = 300;
        int cnt = 0;
        Random r = new Random();
        Timer timer = new Timer();
        public Form1() {
            InitializeComponent();

            this.Paint += Form1_Paint;

            timer.Interval = 500;
            timer.Tick += Timer_Tick;
        }

        private void Timer_Tick(object sender, EventArgs e) {
            cnt = r.Next(3);
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            timer.Start();

            e.Graphics.FillRectangle(Brushes.Black, 0, 0, WIDTH, HEIGHT);

            Brush[] br = {
                Brushes.Blue,
                Brushes.Yellow,
                Brushes.Red
            };

            e.Graphics.FillEllipse(br[cnt], 0, WIDTH * cnt, WIDTH, WIDTH);
        }
    }
}
