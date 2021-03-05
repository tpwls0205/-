using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _RythmStar
{
    public partial class Main : Form
    {

        
        public Main()
        {
            InitializeComponent();          
        }

        private void Main_Load(object sender, EventArgs e)
        {
            this.Width = 800 + 20;
            this.Height = 800;
        }

        private void startGame_Click(object sender, EventArgs e)
        {
            Form1 form = new Form1();
            form.ShowDialog();         
        }

        private void endGame_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
