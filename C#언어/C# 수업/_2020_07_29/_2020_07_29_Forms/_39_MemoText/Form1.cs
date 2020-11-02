using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _39_MemoText
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnWriteMemo_Click(object sender, EventArgs e)
        {
            StreamWriter sw = new StreamWriter("memo.txt");
            sw.Write(tbMemo.Text);          // tbMemo 내용을 저장(Write)
            sw.Close();
        }

        private void btnReadMemo_Click(object sender, EventArgs e)
        {
            char[] buf = new char[1024];
            int ret = 0;
            StreamReader sr = new StreamReader("memo.txt");     // 파일을 연다
            tbMemo.Clear();
            while(true)
            {
                // ret은 실제 읽어들인 크기
                ret = sr.Read(buf, 0, buf.Length);      // buf의 인덱스 0부터 buf의 길이까지
                tbMemo.Text += new string(buf, 0, ret);
                // 1024씩 나눠씩 읽어들이고 실제 읽어들이는 ret가 1024보다 작으면 더이상 뒤가 존재하지 않기때문에 break;
                if (ret < 1024)                          
                {
                    break;
                }
                sr.Close();
            }
        }

        private void btnClearMemo_Click(object sender, EventArgs e)
        {
            tbMemo.Clear();
        }
    }
}
