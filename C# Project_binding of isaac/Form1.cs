using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Media;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace game {
   
    public partial class Form1 : Form{
       
        Character MyCharacter = new Character(300, 300, 30, 20, 30, 50, 50);
        int attack_dir = 0;
        int attack_x = -50, attack_y = -50;
        Timer timer = new Timer();
        Timer timer2 = new Timer();
        System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();

        List<Attack> attackList = new List<Attack>();  //공격 (눈물) 리스트
        List<Monster> monsterList = new List<Monster>(); // 몬스터 리스트
        List<Item> itemList = new List<Item>();
        Random r = new Random();
        SoundPlayer sp = new SoundPlayer();
        Image character_img = null;
        Image monster1_img = null;
        Image monster2_img = null;
        Image monster3_img = null;
        Image monster4_img = null;
        Image bomb_img = null;
        Image item1_img = null;
        Image item2_img = null;
        Image item3_img = null;
        Image item4_img = null;

        int stage;         //스테이지
        int cnt;
        bool stageChangeEnable = false;
        bool stageChange = false;

        // 케릭터 클래스
        public class Character {
            private int x;
            private int y;
            private int dmg;
            private int speed;
            private int shotspeed;
            private int hp;
            private int now_hp;

            public Character(int x, int y, int dmg, int speed, int shotspeed, int hp, int now_hp) {
                this.X = x;
                this.Y = y;
                this.Dmg = dmg;
                this.Speed = speed;
                this.Shotspeed = shotspeed;
                this.Hp = hp;
                this.Now_hp = now_hp;
            }

            public int X { get => x; set => x = value; }
            public int Y { get => y; set => y = value; }
            public int Dmg { get => dmg; set => dmg = value; }
            public int Speed { get => speed; set => speed = value; }
            public int Shotspeed { get => shotspeed; set => shotspeed = value; }
            public int Hp { get => hp; set => hp = value; }
            public int Now_hp { get => now_hp; set => now_hp = value; }
        }

        // 아이템 클래스
        public class Item {
            private int x;
            private int y;
            private int item_num;

            public Item(int x, int y, int item_num) {
                this.x = x;
                this.y = y;
                this.item_num = item_num;
            }

            public int X { get => x; set => x = value; }
            public int Y { get => y; set => y = value; }
            public int Item_num { get => item_num; set => item_num = value; }
        }

        // 공격(눈물) 클래스
        public class Attack {
            int dir;
            int attack_x;
            int attack_y;

            public Attack(int dir, int attack_x, int attack_y) {
                this.Dir = dir;
                this.Attack_x = attack_x;
                this.Attack_y = attack_y;
            }

            public int Dir { get => dir; set => dir = value; }
            public int Attack_x { get => attack_x; set => attack_x = value; }
            public int Attack_y { get => attack_y; set => attack_y = value; }
        }

        // 몬스터 클래스
        public class Monster {
            int monster_x;
            int monster_y;
            int monster_hp;
            int monster_speed_x;
            int monster_speed_y;
            int monster_kind;

            public int Monster_x { get => monster_x; set => monster_x = value; }
            public int Monster_y { get => monster_y; set => monster_y = value; }
            public int Monster_hp { get => monster_hp; set => monster_hp = value; }

            public int Monster_kind { get => monster_kind; set => monster_kind = value; }
            public int Monster_speed_x { get => monster_speed_x; set => monster_speed_x = value; }
            public int Monster_speed_y { get => monster_speed_y; set => monster_speed_y = value; }
        }

        public Form1() {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.KeyDown += Form1_KeyDown;
            this.Load += Form1_Load;
            timer.Interval = 20;
            timer.Tick += Timer_Tick;
            timer2.Interval = 50;
            timer2.Tick += Timer2_Tick;
        }

        // 케릭터 공격 메서드
        public void Arrow_Move() {
            for (int i = 0; i < attackList.Count; i++) {
                if (attackList[i].Dir == 9) {
                    attackList[i].Attack_x -= MyCharacter.Shotspeed;
                }
                if (attackList[i].Dir == 12) {
                    attackList[i].Attack_y -= MyCharacter.Shotspeed;
                }
                if (attackList[i].Dir == 3) {
                    attackList[i].Attack_x += MyCharacter.Shotspeed;
                }
                if (attackList[i].Dir == 6) {
                    attackList[i].Attack_y += MyCharacter.Shotspeed;
                }
            }
        }

        // 케릭터 공격이 몬스터에 맞췄는지 판단 메서드
        public void Hit_Monster()
        {
            Graphics g = CreateGraphics();
            for (int i = 0; i < attackList.Count; i++)
            {
                if (attackList[i].Attack_x == 0
                              || attackList[i].Attack_y == 0
                              || attackList[i].Attack_x > this.ClientRectangle.Right
                              || attackList[i].Attack_y > this.ClientRectangle.Bottom)
                {
                    attackList.RemoveAt(i);
                    break;
                }
                for (int j = 0; j < monsterList.Count; j++)
                {
                    if (attackList.Count <= 0) break;
                    if (stage == 1 || stage == 2)
                    {
                        if (attackList[i].Attack_x + 20 >= monsterList[j].Monster_x &&
                            attackList[i].Attack_x <= monsterList[j].Monster_x + 60 &&
                            attackList[i].Attack_y + 20 >= monsterList[j].Monster_y &&
                            attackList[i].Attack_y <= monsterList[j].Monster_y + 60)
                        {
                            monsterList[j].Monster_hp -= MyCharacter.Dmg;

                            attackList.RemoveAt(i);
                            if (monsterList[j].Monster_hp <= 0)
                            {
                                monsterList.RemoveAt(j);
                            }
                            break;
                        }

                    }
                    if (stage == 3)
                    {
                        if (attackList[i].Attack_x + 20 >= monsterList[j].Monster_x &&
                            attackList[i].Attack_x <= monsterList[j].Monster_x + 120 &&
                            attackList[i].Attack_y + 20 >= monsterList[j].Monster_y &&
                            attackList[i].Attack_y <= monsterList[j].Monster_y + 120)
                        {
                            monsterList[j].Monster_hp -= MyCharacter.Dmg;

                            attackList.RemoveAt(i);
                            if (monsterList[j].Monster_hp <= 0)
                            {
                                int a = MyCharacter.X - monsterList[j].Monster_x;
                                int b = MyCharacter.Y - monsterList[j].Monster_y;
                                g.DrawImage(bomb_img, monsterList[j].Monster_x - 120, monsterList[j].Monster_y - 120, 400, 400);
                                if (a <= -250) { a *= -1; }
                                if (b <= -250) { b *= -1; }
                                if ((a <= 250) && (b <= 250)) { MyCharacter.Now_hp -= 10; }
                                monsterList.RemoveAt(j);
                            }
                            break;
                        }
                    }
                    if (stage == 4)
                    {
                        if (attackList[i].Attack_x + 20 >= monsterList[j].Monster_x &&
                            attackList[i].Attack_x <= monsterList[j].Monster_x + 60 &&
                            attackList[i].Attack_y + 20 >= monsterList[j].Monster_y &&
                            attackList[i].Attack_y <= monsterList[j].Monster_y + 60)
                        {
                            monsterList[j].Monster_hp -= MyCharacter.Dmg;

                            attackList.RemoveAt(i);
                            if (monsterList[j].Monster_hp <= 0)
                            {
                                monsterList.RemoveAt(j);
                            }
                            break;
                        }
                    }
                }
            }
            if (monsterList.Count == 0 && itemList.Count == 0)
            {
                Item_Create();
                stageChangeEnable = true;
            }
            if (Victory())
            {
                sw.Stop();
                timer.Stop();
                if (MessageBox.Show("VICTORY!!!!!" +
                    "\n기록을 남기시겠습니까??", "YesOrNo",
                    MessageBoxButtons.YesNo) == DialogResult.Yes)
                {
                    Form4 SQL_Form = new Form4();
                    SQL_Form.Passvalue = sw.Elapsed.ToString();
                    SQL_Form.ShowDialog();
                }
            }
        }

        bool Victory() {
            if (monsterList.Count == 0 && stage == 4) return true;
            else return false;
        }
        bool Game_Over()
        {
            if (MyCharacter.Now_hp <= 0)
            {
                return true;
            }
            else return false;
        }

        public void Item_Create() {
            itemList.Add(new Item(ClientRectangle.Right / 2, ClientRectangle.Bottom / 2, r.Next(4)));
        }

        public bool Item_Get() {
            for (int i = 0; i < itemList.Count; i++) {
                if ((MyCharacter.X <= itemList[i].X && itemList[i].X <= MyCharacter.X + 100) && 
                    (MyCharacter.Y <= itemList[i].Y && itemList[i].Y <= MyCharacter.Y + 100)) {
                    if (itemList[i].Item_num == 0) {
                        MyCharacter.Dmg += 50;
                    }
                    if (itemList[i].Item_num == 1) {
                        MyCharacter.Now_hp += 50;
                    }
                    if (itemList[i].Item_num == 2) {
                        MyCharacter.Shotspeed += 20;
                    }
                    if (itemList[i].Item_num == 3) {
                        MyCharacter.Speed += 10;
                    }
                    itemList.RemoveAt(i);
                    return true;
                }
            }
            return false;
        }

    // 공격판단 , 맞는판단 타이머 인터벌 20
    private void Timer_Tick(object sender, EventArgs e) {
            if (stageChange == true) {
                stageChange = false;
                NewMonster(stage + 1);
            }
            Arrow_Move();
            Character_Attacked();
            Hit_Monster();
            if (Game_Over()) {
                sw.Stop();
                timer.Stop();
                if (MessageBox.Show("Game Over"+"\n다시 시작하시겠습니까?",
                    "YesOrNo", MessageBoxButtons.YesNo) == DialogResult.Yes) {
                    Form1 fr = new Form1();
                    fr.ShowDialog();
                }
                else {
                    this.Close();
                }
            }
            Invalidate();
        }
       
        // 몬스터 움직이는 타이머 인터벌 50
        private void Timer2_Tick(object sender, EventArgs e) {
            cnt++;
            if (MyCharacter.Now_hp <= 0) {
                this.Hide();
            }
            Monster_Move();
        }

        // 캐릭터가 몬스터공격에 맞았는지 판단하는 메서드
        public void Character_Attacked() {
            for (int i = 0; i < monsterList.Count; i++) {
                if (MyCharacter.X + 70 >= monsterList[i].Monster_x &&
                    MyCharacter.X <= monsterList[i].Monster_x &&
                    MyCharacter.Y + 70 >= monsterList[i].Monster_y &&
                    MyCharacter.Y <= monsterList[i].Monster_y) {
                    MyCharacter.Now_hp -= 1;
                }
            }
        }

        // 몬스터 움직이는 메서드
        public void Monster_Move() {
            for (int j = 0; j < monsterList.Count; j++) {
                if (monsterList[j].Monster_kind == 1) {
                    monsterList[j].Monster_x += monsterList[j].Monster_speed_x;
                    monsterList[j].Monster_y += monsterList[j].Monster_speed_y;
                    if (monsterList[j].Monster_x <= 0 + 40) monsterList[j].Monster_speed_x *= -1;
                    if (monsterList[j].Monster_x >= this.ClientRectangle.Width - 40) monsterList[j].Monster_speed_x *= -1;
                    if (monsterList[j].Monster_y <= 0 + 40) monsterList[j].Monster_speed_y *= -1;
                    if (monsterList[j].Monster_y >= this.ClientRectangle.Height - 40) monsterList[j].Monster_speed_y *= -1;
                }
                if (monsterList[j].Monster_kind == 2) {
                    int a = MyCharacter.X - monsterList[j].Monster_x;
                    int b = MyCharacter.Y - monsterList[j].Monster_y;
                    monsterList[j].Monster_x += a / 15;
                    monsterList[j].Monster_y += b / 15;
                }
                if (monsterList[j].Monster_kind == 3) {
                    int a = MyCharacter.X - monsterList[j].Monster_x;
                    int b = MyCharacter.Y - monsterList[j].Monster_y;
                    monsterList[j].Monster_x += a / 80;
                    monsterList[j].Monster_y += b / 80;
                }
                if (monsterList[j].Monster_kind == 4) {
                    if (cnt % 40 == 0) {
                        monsterList[j].Monster_x = r.Next(40, this.ClientRectangle.Width - 40);
                        monsterList[j].Monster_y = r.Next(40, this.ClientRectangle.Height - 40);
                    }
                }
            }

        }

        // 공격(눈물) 리스트 Add 메서드
        public void Attack_Monster() {
            this.attack_x = (MyCharacter.X + 10);
            this.attack_y = (MyCharacter.Y + 20);
            attackList.Add(new Attack(attack_dir, this.attack_x, this.attack_y));
        }
        // 로드
        private void Form1_Load(object sender, EventArgs e) {

            timer.Start();
            timer2.Start();
            sw.Start();
            sp.SoundLocation = "../../배경음악.wav";
            sp.Play();
            character_img = Image.FromFile("../../케릭터.png");
            monster1_img = Image.FromFile("../../몬스터_1.png");
            monster2_img = Image.FromFile("../../몬스터_2.png");
            monster3_img = Image.FromFile("../../몬스터_3.png");
            monster4_img = Image.FromFile("../../몬스터_4.png");
            item1_img = Image.FromFile("../../아이템1.png");
            item2_img = Image.FromFile("../../아이템2.png");
            item3_img = Image.FromFile("../../아이템3.png");
            item4_img = Image.FromFile("../../아이템4.png");
            bomb_img = Image.FromFile("../../폭발.png");
            NewMonster(1);
            DoubleBuffered = true;
          
        }
        // 몬스터 새롭게 생성 메서드
        public void NewMonster(int kind) {
           
            if (kind == 1) {
                for (int i = 0; i < 1; i++) {

                    monsterList.Add(new Monster());
                    monsterList[i].Monster_x = r.Next(40, this.ClientRectangle.Width - 40);
                    monsterList[i].Monster_y = r.Next(40, this.ClientRectangle.Height - 40);
                    monsterList[i].Monster_speed_x = r.Next(-10, 10);
                    monsterList[i].Monster_speed_y = r.Next(-10, 10);
                    if (monsterList[i].Monster_speed_x == 0)
                        monsterList[i].Monster_speed_x = 1;
                    else if (monsterList[i].Monster_speed_y == 0)
                        monsterList[i].Monster_speed_y = 1;
                    monsterList[i].Monster_hp = 120;
                    monsterList[i].Monster_kind = 1;
                }
                stage = 1;
            }
            if (kind == 2) {
                for (int i = 0; i < 1; i++) {

                    monsterList.Add(new Monster());
                    monsterList[i].Monster_x = r.Next(40, this.ClientRectangle.Width - 40);
                    monsterList[i].Monster_y = r.Next(40, this.ClientRectangle.Height - 40);
                    monsterList[i].Monster_speed_x = r.Next(-10, 10);
                    monsterList[i].Monster_speed_y = r.Next(-10, 10);
                    if (monsterList[i].Monster_speed_x == 0)
                        monsterList[i].Monster_speed_x = 1;
                    else if (monsterList[i].Monster_speed_y == 0)
                        monsterList[i].Monster_speed_y = 1;
                    monsterList[i].Monster_hp = 60;
                    monsterList[i].Monster_kind = 2;
                 
                }
                stage = 2;
            }
            if (kind == 3) {
                for (int i = 0; i < 1; i++) {
                    monsterList.Add(new Monster());
                    monsterList[i].Monster_x = r.Next(40, this.ClientRectangle.Width - 40);
                    monsterList[i].Monster_y = r.Next(40, this.ClientRectangle.Height - 40);
                    monsterList[i].Monster_speed_x = r.Next(-10, 10);
                    monsterList[i].Monster_speed_y = r.Next(-10, 10);
                    if (monsterList[i].Monster_speed_x == 0)
                        monsterList[i].Monster_speed_x = 1;
                    else if (monsterList[i].Monster_speed_y == 0)
                        monsterList[i].Monster_speed_y = 1;
                    monsterList[i].Monster_hp = 240;
                    monsterList[i].Monster_kind = 3;
                   
                }
                stage = 3;
            }
            if (kind == 4) {
                for (int i = 0; i < 1; i++) {
                    monsterList.Add(new Monster());
                    monsterList[i].Monster_x = r.Next(40, this.ClientRectangle.Width - 40);
                    monsterList[i].Monster_y = r.Next(40, this.ClientRectangle.Height - 40);
                    monsterList[i].Monster_hp = 120;
                    monsterList[i].Monster_kind = 4;
                    
                }
                stage = 4;
            }
        }
        // 키보드 입력 메서드
        private void Form1_KeyDown(object sender, KeyEventArgs e) {
            switch (e.KeyCode) {
                case Keys.Left:
                    attack_dir = 9;
                    Attack_Monster();
                    break;
                case Keys.Up:
                    attack_dir = 12;
                    Attack_Monster();
                    break;
                case Keys.Right:
                    attack_dir = 3;
                    Attack_Monster();
                    break;
                case Keys.Down:
                    attack_dir = 6;
                    Attack_Monster();
                    break;
                case Keys.A:
                    MyCharacter.X -= MyCharacter.Speed;
                    break;
                case Keys.W:
                    MyCharacter.Y -= MyCharacter.Speed;
                    break;
                case Keys.D:
                    MyCharacter.X += MyCharacter.Speed;
                    break;
                case Keys.S:
                    MyCharacter.Y += MyCharacter.Speed;
                    break;
            }
                    if (stageChangeEnable == true) {
                        if (Item_Get()) {
                            stageChangeEnable = false;
                            stageChange = true;
                        }
                    }
                    Invalidate();

        }
        // 페인트 메서드
        private void Form1_Paint(object sender, PaintEventArgs e) {
            string str = "체력:" + MyCharacter.Now_hp.ToString() + "\n"
                        + "데미지 : " + MyCharacter.Dmg.ToString() + "\n"
                        + "총알 속도 : " + MyCharacter.Shotspeed.ToString() + "\n"
                        + "스테이지 : " + stage.ToString();
            Rectangle myCharacter = new Rectangle(MyCharacter.X, MyCharacter.Y, 70, 70);
            e.Graphics.DrawImage(character_img, myCharacter);
            e.Graphics.DrawString(str,new Font("",15), Brushes.White, 20, 20);
            e.Graphics.DrawString(sw.Elapsed.ToString(), new Font("", 20), Brushes.White, 200, 20);
            for (int i = 0; i < attackList.Count; i++) {

                Rectangle attack = new Rectangle(attackList[i].Attack_x, attackList[i].Attack_y, 20, 20);
                e.Graphics.FillEllipse(Brushes.Red, attack);
            }

            for (int i = 0; i < monsterList.Count; i++) {

                if (stage == 1) {
                    e.Graphics.DrawImage(monster1_img, monsterList[i].Monster_x, monsterList[i].Monster_y, 60, 60);
                }
                if (stage == 2) {
                    e.Graphics.DrawImage(monster2_img, monsterList[i].Monster_x, monsterList[i].Monster_y, 60, 60);
                }
                if (stage == 3) {
                    e.Graphics.DrawImage(monster3_img, monsterList[i].Monster_x, monsterList[i].Monster_y, 120, 120);
                }
                if (stage == 4) {
                    e.Graphics.DrawImage(monster4_img, monsterList[i].Monster_x, monsterList[i].Monster_y, 60, 60);
                }
            }
            for (int i = 0; i < itemList.Count; i++) {
                if (itemList[i].Item_num == 0) {
                    e.Graphics.DrawImage(item1_img, itemList[i].X, itemList[i].Y, 70, 70);
                }
                if (itemList[i].Item_num == 1) {
                    e.Graphics.DrawImage(item2_img, itemList[i].X, itemList[i].Y, 70, 70);
                }
                if (itemList[i].Item_num == 2) {
                    e.Graphics.DrawImage(item3_img, itemList[i].X, itemList[i].Y, 70, 70);
                }
                if (itemList[i].Item_num == 3) {
                    e.Graphics.DrawImage(item4_img, itemList[i].X, itemList[i].Y, 70, 70);
                }
            }


        }
    }
}


