using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _16_MoviePlayer
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.Load += Form1_Load;
            this.Layout += Form1_Layout;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.axWindowsMediaPlayer1.URL = "https://www.youtube.com/watch?v=EgNcIW4t4Z8&t=562s";
        }

        private void Form1_Layout(object sender, LayoutEventArgs e)
        {
            this.axWindowsMediaPlayer1.Size = this.ClientSize;
        }
    }
}
