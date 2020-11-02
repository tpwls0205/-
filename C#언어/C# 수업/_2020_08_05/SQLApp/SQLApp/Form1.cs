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

namespace SQLApp
{
    public partial class Form1 : Form
    {
        SqlConnection conn = null;
        string dbConnInfo = @"Server=localhost;" + @"database=Test_DB;" + @"uid=Test_Login;" + @"pwd=123456";
        public Form1()
        {
            InitializeComponent();
            this.Load += Form1_Load;
            this.FormClosed += Form1_FormClosed;
        }

        void AddResultLogListBox(string result)
        {
            lbResultLog.Items.Add(result);
        }

        void btnEnable(bool conn, bool disconn, bool select = false, bool insert = false, bool update = false, bool delete = false)
        {   // 초기 버튼 활성화 상태
            btnDBConnect.Enabled = conn;
            btnDBDisconnect.Enabled = disconn;
            btnSelectSQL.Enabled = select;
            btnInsertSQL.Enabled = insert;
            btnUpdataSQL.Enabled = update;
            btnDeleteSQL.Enabled = delete;
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            btnDBDisconnect_Click(sender, e);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            btnEnable(true, false); // 커넥트는 초기에 활성화, 누르면 dis커넥트가 활성화
            tbConnectInfo.Text = dbConnInfo;
        }

        private void btnDBConnect_Click(object sender, EventArgs e)
        {
            conn = new SqlConnection(tbConnectInfo.Text);
            try
            {
                conn.Open();
                if(conn.State == ConnectionState.Open)
                {
                    AddResultLogListBox("SQL-Server 연결 성공!");
                    btnEnable(false, true, true, true, true, true);
                }
                else
                {
                    conn = null;
                    AddResultLogListBox("상태 : " + conn.State.ToString());
                }
            }
            catch(Exception ex)
            {
                conn = null;
                AddResultLogListBox(ex.Message);    // 어떤 예외가 발생했는지 출력
            }
        }

        private void btnDBDisconnect_Click(object sender, EventArgs e)
        {
            if(conn != null && (conn.State == ConnectionState.Open || conn.State == ConnectionState.Connecting))
            {
                conn.Close();
                conn = null;
                AddResultLogListBox("SQL-Server 연결 해제");
                btnEnable(true, false);
            }
        }

        private void btnSelectSQL_Click(object sender, EventArgs e)
        {
            try
            {
                SqlCommand cmd = new SqlCommand();
                cmd.Connection = conn;
                cmd.CommandText = "SELECT * FROM dbo.Human";
                // 2) SELECT 문은 실행 후 결과를 받아온다
                SqlDataReader reader = cmd.ExecuteReader();

                // 3) dbo.Human테이블의 컬럼을 얻자
                string[] colNames = new string[reader.FieldCount];
                for(int i = 0; i< reader.FieldCount; i++)
                {
                    colNames[i] = reader.GetName(i);
                    AddResultLogListBox("컬럼명_" + i + ":" + colNames[i]);
                }
                AddResultLogListBox("");

                // 4) 행(레코드) 데이터를 가져오자
                while(reader.Read())    // read : 데이터가 있으면 true, 없으면 false가 리턴
                {
                    string[] datas = new string[reader.FieldCount];
                    for(int i =0; i<reader.FieldCount; i++)
                    {
                        datas[i] = reader.GetValue(i).ToString();
                    }
                    for(int i = 0; i<reader.FieldCount; i++)
                    {   
                        AddResultLogListBox(string.Format("{0} : {1}", colNames[i], datas[i]));
                    }
                    AddResultLogListBox("");
                }
                reader.Close();
                cmd.Dispose();  // cmd객체 리소스 해제
            }
            catch(Exception ex)
            {
                AddResultLogListBox(ex.Message);
            }
        }

        private void btnInsertSQL_Click(object sender, EventArgs e)
        {
            try
            {
                /* using 절이 끝날 때 cmd.Dispose()가 자동 호출된다.
                 * cmd객체를 using에서만 사용하고 해제하겠다.
                 */
                using (SqlCommand cmd = new SqlCommand())
                {
                    cmd.Connection = conn;
                    cmd.CommandText = @"INSERT INTO dbo.Human" + "\r\n" + @"VALUES(@번호, @이름, @전화, @주소)";
                    cmd.Parameters.AddWithValue("@번호", "2154");
                    cmd.Parameters.AddWithValue("@이름", "문채원");
                    cmd.Parameters.AddWithValue("@전화", "010-777-4485");
                    cmd.Parameters.AddWithValue("@주소", "강원도 강릉");
                    int nRun = cmd.ExecuteNonQuery();
                    AddResultLogListBox(String.Format("INSERT {0} 행이 실행됨", nRun));
                }
            }
            catch (Exception ex)
            {
                AddResultLogListBox(ex.Message);
            }
        }

        private void btnUpdataSQL_Click(object sender, EventArgs e)
        {
            try
            {
                using (SqlCommand cmd = new SqlCommand())
                {
                    cmd.Connection = conn;
                    cmd.CommandText = @"UPDATE dbo.Human SET" + "\r\n" + @"name=@이름0" + "\r\n" + @"WHERE name=@이름1";
                    cmd.Parameters.AddWithValue("@이름0", "문근영");
                    cmd.Parameters.AddWithValue("@이름1", "문채원");
                    int nRun = cmd.ExecuteNonQuery();
                    AddResultLogListBox(String.Format("UPDATE {0} 행이 실행됨", nRun));
                }
            }
            catch (Exception ex)
            {
                AddResultLogListBox(ex.Message);
            }
        }

        private void btnDeleteSQL_Click(object sender, EventArgs e)
        {
            try
            {
                using (SqlCommand cmd = new SqlCommand())
                {
                    cmd.Connection = conn;
                    cmd.CommandText = @"DELETE FROM dbo.Human" + "\r\n" + @"WHERE name=@이름";
                    cmd.Parameters.AddWithValue("@이름", "문근영");
                    int nRun = cmd.ExecuteNonQuery();
                    AddResultLogListBox(String.Format("DELETE {0} 행이 실행됨", nRun));
                }
            }
            catch (Exception ex)
            {
                AddResultLogListBox(ex.Message);
            }
        }

        private void btnErase_Click(object sender, EventArgs e)
        {
            lbResultLog.Items.Clear();
        }
    }
}
