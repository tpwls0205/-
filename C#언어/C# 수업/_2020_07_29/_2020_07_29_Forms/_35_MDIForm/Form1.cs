using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _35_MDIForm
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.IsMdiContainer = true; // 자식 창들을 내꺼 안에 포함할 수 있느냐
        }

        private void 새파일ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ChildForm childForm = new ChildForm();
            childForm.MdiParent = this;
            childForm.Show();
        }

        private void 닫기ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form childForm = this.ActiveMdiChild;   // 현재활성화된 자식 창을 객체(래퍼런스)를 받아온다.
            if(childForm != null)
            {
                childForm.Close();
            }
        }

        private void 계단식정렬ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.LayoutMdi(MdiLayout.Cascade);
        }

        private void 수평바둑판정렬ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileHorizontal);    // 수평정렬
        }

        private void 수직바둑판정렬ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileVertical);      // 수직정렬
        }
    }
}
