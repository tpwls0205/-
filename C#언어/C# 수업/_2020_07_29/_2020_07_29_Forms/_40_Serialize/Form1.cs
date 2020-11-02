using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization.Formatters.Soap;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

/*  
 *  시리얼라이즈란? (직렬화)
 *  1. binary
 *  2. XML
 *  3. json
 */

namespace _40_Serialize
{
    public partial class Form1 : Form
    {
        Human human = new Human();

        public Form1()
        {
            InitializeComponent();
            this.Load += Form1_Load;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            human.Name = "홍길동";
            human.Age = 24;
            human.Height = 174.5f;
            human.Weight = 72.5f;
        }

        void SerializeBinary()
        {
            FileStream fs = new FileStream("Human.bin", FileMode.Create, FileAccess.Write);
            BinaryFormatter bf = new BinaryFormatter();     // 바이너리 형식으로 저장하기 위해
            bf.Serialize(fs, human);
            fs.Close();
        }
        void SerializeXML()
        {
            FileStream fs = new FileStream("Human.xml", FileMode.Create, FileAccess.Write);
            SoapFormatter sf = new SoapFormatter();
            sf.Serialize(fs, human);
            fs.Close();
        }
        void DeserializeBinary()
        {
            FileStream fs = new FileStream("Human.bin", FileMode.Open, FileAccess.Read);
            BinaryFormatter bf = new BinaryFormatter();
            Human hong = bf.Deserialize(fs) as Human;
            MessageBox.Show(hong.ToString());
            fs.Close();
        }
        void DeserializeXML()
        {
            FileStream fs = new FileStream("Human.xml", FileMode.Open, FileAccess.Read);
            SoapFormatter sf = new SoapFormatter();
            Human hong = sf.Deserialize(fs) as Human;
            MessageBox.Show(hong.ToString());
            fs.Close();
        }

        // 시리얼라이즈 : 객체자체를 저장하는 문법
        private void btnWriteSerialize_Click(object sender, EventArgs e)
        {
            //SerializeBinary();
            SerializeXML();
        }

        private void btnReadSerialize_Click(object sender, EventArgs e)
        {
            //DeserializeBinary();
            DeserializeXML();
        }
    }
}
