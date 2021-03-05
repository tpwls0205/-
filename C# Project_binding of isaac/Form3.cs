using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace game {
    public partial class Form3 : Form {

        public Form3() {
            InitializeComponent();
            this.Load += Form3_Load;
            this.Paint += Form3_Paint;
        }

        private void Form3_Paint(object sender, PaintEventArgs e) {
             e.Graphics.DrawString("GAME OVER", new Font("", 50), Brushes.White, 180, 140);
        }

        private void Form3_Load(object sender, EventArgs e) {
            Graphics g = CreateGraphics();
            g.DrawString("GAME OVER", new Font("", 30),Brushes.White, 200, 50);

        }

        private void button1_Click(object sender, EventArgs e) {
            Form4 DB_form = new Form4();
            this.Hide();
            DB_form.ShowDialog();
            
        }
    }
}
