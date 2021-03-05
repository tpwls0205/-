namespace game {
    partial class Form4 {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) {
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            this.listView1 = new System.Windows.Forms.ListView();
            this.btn_ResetListView = new System.Windows.Forms.Button();
            this.btn_SQLRun = new System.Windows.Forms.Button();
            this.tb_SQL = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // listView1
            // 
            this.listView1.FullRowSelect = true;
            this.listView1.GridLines = true;
            this.listView1.HideSelection = false;
            this.listView1.Location = new System.Drawing.Point(22, 12);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(751, 421);
            this.listView1.TabIndex = 0;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.View = System.Windows.Forms.View.Details;
            // 
            // btn_ResetListView
            // 
            this.btn_ResetListView.Location = new System.Drawing.Point(319, 439);
            this.btn_ResetListView.Name = "btn_ResetListView";
            this.btn_ResetListView.Size = new System.Drawing.Size(104, 43);
            this.btn_ResetListView.TabIndex = 2;
            this.btn_ResetListView.Text = "모두 삭제";
            this.btn_ResetListView.UseVisualStyleBackColor = true;
            this.btn_ResetListView.Click += new System.EventHandler(this.btn_ResetListView_Click);
            // 
            // btn_SQLRun
            // 
            this.btn_SQLRun.Location = new System.Drawing.Point(934, 603);
            this.btn_SQLRun.Name = "btn_SQLRun";
            this.btn_SQLRun.Size = new System.Drawing.Size(108, 34);
            this.btn_SQLRun.TabIndex = 3;
            this.btn_SQLRun.Text = "SQL 실행";
            this.btn_SQLRun.UseVisualStyleBackColor = true;
            this.btn_SQLRun.Click += new System.EventHandler(this.btn_SQLRun_Click);
            // 
            // tb_SQL
            // 
            this.tb_SQL.Location = new System.Drawing.Point(22, 610);
            this.tb_SQL.Name = "tb_SQL";
            this.tb_SQL.Size = new System.Drawing.Size(883, 21);
            this.tb_SQL.TabIndex = 4;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(22, 574);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(135, 21);
            this.textBox1.TabIndex = 5;
            this.textBox1.Text = "숫자 4개 입력";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(304, 572);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 6;
            this.button1.Text = "기록 저장";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(163, 574);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(135, 21);
            this.textBox2.TabIndex = 5;
            this.textBox2.Text = "이름 입력";
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 12;
            this.listBox1.Location = new System.Drawing.Point(780, 13);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(262, 412);
            this.listBox1.TabIndex = 1;
            // 
            // Form4
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::game.Properties.Resources.로딩화면;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(1059, 649);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.tb_SQL);
            this.Controls.Add(this.btn_SQLRun);
            this.Controls.Add(this.btn_ResetListView);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.listView1);
            this.DoubleBuffered = true;
            this.Name = "Form4";
            this.Text = "Form4";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.Button btn_ResetListView;
        private System.Windows.Forms.Button btn_SQLRun;
        private System.Windows.Forms.TextBox tb_SQL;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.ListBox listBox1;
    }
}