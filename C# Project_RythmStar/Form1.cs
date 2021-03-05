using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _RythmStar
{
    public partial class Form1 : Form
    {
        Timer timer = new Timer();
        Random rand = new Random();
     
        const int ROWS = 800;
        const int COLS = 800;

        const int OBJ_SIZE = 100;
        int objectX = 200;

        List<ButtonBox> btnBox = new List<ButtonBox>();
        Image[] img = new Image[8]; // 버튼 및 리듬박스 이미지 모음

        List<Rythmbox> rcList = new List<Rythmbox>();
        List<int> randNum = new List<int>();
        int objCnt = 0;
        int clickNum = 0;

        // 점수 관련 변수들
        int userPoint = 0;
        int comboCnt = 0;
        int setHp = 250;
        int userHp = 0;
        public int maxCombo = 0;
        public int speed = 5;
        string feedBack = "";
        Brush[] br = { Brushes.Blue, Brushes.Green, Brushes.Yellow, Brushes.Brown };
        Font fontP = new Font("맑은 고딕", 50);
        Font fontPView = new Font("궁서체", 25);

        SoundPlayer sp1 = new SoundPlayer();
        SoundPlayer sp2 = new SoundPlayer();
        SoundPlayer sp3 = new SoundPlayer();

        public Form1()
        {         
            this.DoubleBuffered = true;
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.KeyDown += Form1_KeyDown;
            this.KeyUp += Form1_KeyUp;
            timer.Interval = 15;
            timer.Tick += Timer_Tick;
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            objCnt++;
            if (objCnt % 28 == 0){
                int x = rand.Next(4);
                randNum.Add(x);
                rcList.Add(new Rythmbox(objectX + x * OBJ_SIZE, -50, x));
            }

            if (objCnt > 500 && objCnt < 1000) speed = 7;
            if (objCnt > 1000 && objCnt < 2000) speed = 9;
            if (objCnt > 2000 && objCnt < 3200) speed = 12;
            if (objCnt > 3200 && objCnt < 5000) speed = 13;
            if(objCnt > 5000) speed = 16;

            Invalidate();
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Left:                                
                    break;
                case Keys.Right:                            
                    break;
                case Keys.Up:                                  
                    break;
                case Keys.Down:                                  
                    break;
            }
            Invalidate();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            Graphics g = CreateGraphics();
            switch (e.KeyCode)
            {
                case Keys.Enter:
                    int mNum = rand.Next(3);
                    timer.Start();
                    if (mNum == 0)
                        sp1.PlayLooping();
                    if (mNum == 1)
                        sp2.PlayLooping();
                    if (mNum == 2)
                        sp3.PlayLooping();
                    break;
                case Keys.Left:
                    checkPoint(0);
                    g.DrawImage(img[4], btnBox[0].Bx, btnBox[0].By, OBJ_SIZE, 50);
                    break;
                case Keys.Up:
                    checkPoint(1);
                    g.DrawImage(img[5], btnBox[1].Bx, btnBox[1].By, OBJ_SIZE, 50);
                    break;
                case Keys.Right:
                    checkPoint(2);
                    g.DrawImage(img[6], btnBox[2].Bx, btnBox[2].By, OBJ_SIZE, 50);
                    break;
                case Keys.Down:
                    checkPoint(3);
                    g.DrawImage(img[7], btnBox[3].Bx, btnBox[3].By, OBJ_SIZE, 50);
                    break;
            }
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Console.WriteLine("Count : " + rcList.Count);
            for (int i = 0; i < rcList.Count; i++)
            {
                if (userHp < 250)
                {
                    // 버튼 그리기
                    for (int b = 0; b < 4; b++)
                    {
                        g.DrawImage(img[b], btnBox[b].Bx, btnBox[b].By, OBJ_SIZE, 50);
                    }

                    // 체통
                    g.FillRectangle(Brushes.Red, btnBox[4].Bx, btnBox[4].By, OBJ_SIZE / 2, setHp);
                    g.FillRectangle(Brushes.Black, btnBox[4].Bx, btnBox[4].By, OBJ_SIZE / 2, userHp);

                    // 점수, 문구, 콤보 띄우기
                    string score = userPoint.ToString();
                    string combo = comboCnt.ToString() + "  Combo !";
                    g.DrawString(score, fontP, Brushes.Gold, ROWS / 2 - 75, 650);
                    g.DrawString(combo, fontPView, br[rand.Next(4)], ROWS - objectX + 20, objectX / 2 + 50);
                    g.DrawString(feedBack, fontPView, br[rand.Next(4)], ROWS - objectX, objectX);

                    // 리듬박스 생성 및 삭제
                    
                    rcList[i] = new Rythmbox(rcList[i].Rx, rcList[i].Ry + speed, 
                                            rcList[i].Imgnum);

                    g.DrawImage(img[rcList[i].Imgnum], rcList[i].Rx, rcList[i].Ry, OBJ_SIZE, 50);

                    // 리듬박스가 바닥에 떨어지면 삭제

                    if (rcList[i].Ry >= 600)
                    {
                        if(clickNum == 0)
                        {
                            userHp += 25;
                            userPoint -= 30;
                        }
                        rcList.RemoveAt(i);
                        randNum.RemoveAt(i);                       
                        clickNum = 0;
                    }
                }

                if (userHp >= 250)
                {
                    sp1.Stop();
                    sp2.Stop();
                    sp3.Stop();
                    string score = userPoint.ToString();
                    string mCombo = maxCombo.ToString();
                    g.DrawString("You Lose~!", fontP, br[rand.Next(4)], ROWS / 2 - OBJ_SIZE * 2 + 30, COLS / 2 - 80);
                    g.DrawString("Point : " + score, fontP, br[rand.Next(4)], ROWS / 2 - OBJ_SIZE * 2 + 30, COLS / 2 - 20);
                    g.DrawString("MaxCombo : " + mCombo, fontP, br[rand.Next(4)], ROWS / 2 - OBJ_SIZE * 2 + 30, COLS / 2 + 40);               
                    break;
                }
            }
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            this.Width = 800 + 20;
            this.Height = 800;
            sp3.SoundLocation = "../../music3.wav";
            sp1.SoundLocation = "../../music1.wav";
            sp2.SoundLocation = "../../music2.wav";
            setButton();
            setImage();
        }

        void setButton()
        {
            for (int i = 0; i < 4; i++)
            {
                btnBox.Add(new ButtonBox(objectX + i * OBJ_SIZE, 600));
            }
            btnBox.Add(new ButtonBox(ROWS - OBJ_SIZE / 2, COLS / 2));
        }

        class ButtonBox
        {
            int bx;
            int by;

            public ButtonBox(int bx, int by)
            {
                this.Bx = bx;
                this.By = by;
            }

            public int Bx { get => bx; set => bx = value; }
            public int By { get => by; set => by = value; }
        }

        class Rythmbox
        {
            int rx;
            int ry;
            int imgnum;

            public Rythmbox(int rx, int ry, int imgnum)
            {
                this.Rx = rx;
                this.Ry = ry;
                this.Imgnum = imgnum;
            }

            public int Rx { get => rx; set => rx = value; }
            public int Ry { get => ry; set => ry = value; }
            public int Imgnum { get => imgnum; set => imgnum = value; }
        }

        void setImage()
        {
            img[0] = Image.FromFile("../../LEFT.png");
            img[1] = Image.FromFile("../../UP.png");
            img[2] = Image.FromFile("../../RIGHT.png");
            img[3] = Image.FromFile("../../DOWN.png");

            img[4] = Image.FromFile("../../E_LEFT.png");
            img[5] = Image.FromFile("../../E_UP.png");
            img[6] = Image.FromFile("../../E_RIGHT.png");
            img[7] = Image.FromFile("../../E_DOWN.png");

            Image imgb = Image.FromFile("../../dj.jpg");
        }

        void checkPoint(int num)
        {
            for (int i = 0; i < rcList.Count; i++)
            {
                if (rcList[i].Ry >= btnBox[num].By - 30 ||
                    rcList[i].Ry == btnBox[num].By)
                {
                    feedBack = " Good !";
                    userPoint += 100;
                    comboCnt++;
                    if (comboCnt > maxCombo)
                        maxCombo = comboCnt; Console.WriteLine("잘했어");
                    clickNum = 1; break;
                }

                if (rcList[i].Ry > btnBox[num].By - 50 &&
                        rcList[i].Ry <= btnBox[num].By)
                {
                    feedBack = " Not bad !";
                    userPoint += 50;
                    comboCnt++;
                    if (comboCnt > maxCombo)
                        maxCombo = comboCnt; Console.WriteLine("쏘쏘");
                    clickNum = 1; break;
                }
                if (rcList[i].Ry < btnBox[num].By - 50)
                {
                    feedBack = " plz focus \n on Game ~! ";
                    userPoint -= 30;
                    comboCnt = 0;
                    Console.WriteLine("바보"); break;
                }
            }
        }
    }
}
