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

namespace game
{

    public partial class Form4 : Form
    {
        // 연결 객체 변수

        SqlConnection conn;
        private string Form4_value;
        public string Passvalue
        {
            get { return this.Form4_value; }
            set { this.Form4_value = value; }
        }

        // 테이블의 컬럼명을 작성하는 함수
        void MakeListViewColumn(string[] sArr)
        {
            foreach (string s in sArr)
            {
                ColumnHeader cHeader = new ColumnHeader();   // 헤더 생성
                cHeader.Text = s;     // 헤더에 들어갈 텍스트
                cHeader.Width = 150;   // 헤더의 크기
                listView1.Columns.Add(cHeader);  //  ListView에 헤더컬럼 추가
            }
        }

        // 테이블 항목들을 ListView에 보여주는 함수
        void AddListView(string[] sArr)
        {
            listView1.Items.Add(new ListViewItem(sArr));
        }

        // 로그를 ListBox에 출력하는 함수
        void AddListBox(string str)
        {
            listBox1.Items.Add(str);
        }

        public Form4()
        {
            InitializeComponent();
            this.Load += new EventHandler(Form1_Load);
            this.FormClosed += new FormClosedEventHandler(Form1_FormClosed);
        }

        // 프로그램 종료시 처리하는 함수
        void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (conn != null)
            {
                conn.Close();
            }
        }


        // 프로그램 시작시 처리하는 함수
        void Form1_Load(object sender, EventArgs e)
        {
            string conStr = @"Server=localhost;database=Test_DB;uid=Test_Login;pwd=123456;";
            conn = new SqlConnection(conStr);
            try
            {
                conn.Open();
                AddListBox("연결 성공");
            }
            catch (Exception ex)
            {
                AddListBox(ex.Message);
            }
            tb_SQL.Text = @"select rank() over (order by len(time) asc,time asc) as 랭킹, * from dbo.BindingOfIsaac ";
        }

        // 데이터베이스 연결 해제 버튼
        private void btn_DBDisconnect_Click(object sender, EventArgs e)
        {
            conn.Close();
            AddListBox("연결 해제");
        }

        // SQL문 실행 버튼
        private void btn_SQLRun_Click(object sender, EventArgs e)
        {
            // Trim : 양끝 공백없애기, ToUpper() : 대문자
            string strSql = tb_SQL.Text.Trim().ToUpper();
            string strSql_ori = tb_SQL.Text.Trim();

            try
            {
                SqlCommand cmd = new SqlCommand("", conn);
                cmd.CommandText = strSql_ori;

                /*SELECT : 검색 결과가 존재*/
                if (strSql.StartsWith("SELECT"))
                {
                    SqlDataReader read = cmd.ExecuteReader();

                    /*Name, Phone, Age*/
                    string[] str = new string[read.FieldCount];
                    for (int i = 0; i < read.FieldCount; i++)
                        str[i] = read.GetName(i);

                    // ListView에 컬럼 헤더 생성
                    MakeListViewColumn(str);

                    /*테이블의 데이터 가져와서 ListView에 출력*/
                    while (read.Read())
                    {
                        string[] strValue = new string[read.FieldCount];
                        for (int i = 0; i < read.FieldCount; i++)
                        {
                            strValue[i] = read.GetValue(i).ToString();
                        }
                        AddListView(strValue);
                    }

                    read.Close();
                }
                else/*INSERT, DELETE, UPDATE : 처리만 확인*/
                {
                    cmd.CommandText = strSql_ori;
                    cmd.ExecuteNonQuery();
                    AddListBox("명령 실행 마침");
                }
            }
            catch (Exception ex)
            {
                AddListBox(ex.Message);
            }
        }

        // 테이블정보(ListView)를 삭제 초기화 버튼
        private void btn_ResetListView_Click(object sender, EventArgs e)
        {
            listView1.Items.Clear();
            listView1.Columns.Clear();
        }

        // 로그정보(ListBox)를 삭제 초기화 버튼
        private void btn_ResetListBox_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                /* using 절이 끝날 때 cmd.Dispose()가 자동 호출된다.
                 * cmd객체를 using에서만 사용하고 해제하겠다.
                 */
                using (SqlCommand cmd = new SqlCommand())
                {
                    string str = textBox1.Text;
                    string str2 = textBox2.Text;
                    string str3 = Passvalue;
                    cmd.Connection = conn;
                    cmd.CommandText = @"INSERT INTO dbo.BindingOfIsaac" + "\r\n" + @"VALUES(@번호, @이름, @타임)";
                    cmd.Parameters.AddWithValue("@번호", str);
                    cmd.Parameters.AddWithValue("@이름", str2);
                    cmd.Parameters.AddWithValue("@타임", str3);
                    int nRun = cmd.ExecuteNonQuery();
                    AddListBox(String.Format("Insert {0}행이 실행됨", nRun));
                }
            }
            catch (Exception ex)
            {
                AddListBox(ex.Message);
            }
        }


    }
}