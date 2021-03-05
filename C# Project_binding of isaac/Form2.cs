using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace game {
    public partial class Form2 : Form {
      
        public Form2() {
            InitializeComponent();
            this.Load += Form2_Load;
        }

        private void Form2_Load(object sender, EventArgs e) {
            
        }

        private void button1_Click(object sender, EventArgs e) {
            Form1 main_form = new Form1();
            this.Hide();            // 폼2를 숨겨라
            main_form.ShowDialog(); // 폼1을 띄워라
        }
    }
}
