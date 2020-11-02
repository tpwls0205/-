using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ImageForm;

namespace ViewForm
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        // ViewForm -> 참조 -> 참조추가 -> 찾아보기 -> debug -> ImageForm.exe 추가(exe 파일은 dll역할을 하기도 한다)
        // dll은 기능제공(직접실행 못함), exe는 기능제공, 직접실행 가능
        // 참조추가 -> using 네임스페이스 적어줘야함

        // Unity에 연동하려면 dll 파일로 저장해서 유니티 폴더에 저장
        private void btnDog_Click(object sender, EventArgs e)
        {
            ImageForm.Dog dfrm = new ImageForm.Dog();
            dfrm.Show();
        }

        private void btnJang_Click(object sender, EventArgs e)
        {
            ImageForm.Form1 frm = new ImageForm.Form1();
            frm.Show();
        }
    }
}
