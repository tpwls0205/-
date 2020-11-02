namespace _23_radio_checkbox
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.chkForce = new System.Windows.Forms.CheckBox();
            this.chkHonor = new System.Windows.Forms.CheckBox();
            this.chkMoney = new System.Windows.Forms.CheckBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.radioDestroyer = new System.Windows.Forms.RadioButton();
            this.radiohum = new System.Windows.Forms.RadioButton();
            this.btnSelect = new System.Windows.Forms.Button();
            this.chkPower = new System.Windows.Forms.CheckBox();
            this.chkJustice = new System.Windows.Forms.CheckBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.chkJustice);
            this.groupBox1.Controls.Add(this.chkPower);
            this.groupBox1.Controls.Add(this.chkForce);
            this.groupBox1.Controls.Add(this.chkHonor);
            this.groupBox1.Controls.Add(this.chkMoney);
            this.groupBox1.Font = new System.Drawing.Font("굴림", 24F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.groupBox1.Location = new System.Drawing.Point(9, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(779, 185);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "갖고 싶은 것(2개만 가능)";
            // 
            // chkForce
            // 
            this.chkForce.AutoSize = true;
            this.chkForce.Font = new System.Drawing.Font("굴림", 20F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.chkForce.Location = new System.Drawing.Point(293, 63);
            this.chkForce.Name = "chkForce";
            this.chkForce.Size = new System.Drawing.Size(59, 31);
            this.chkForce.TabIndex = 2;
            this.chkForce.Text = "힘";
            this.chkForce.UseVisualStyleBackColor = true;
            // 
            // chkHonor
            // 
            this.chkHonor.AutoSize = true;
            this.chkHonor.Font = new System.Drawing.Font("굴림", 20F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.chkHonor.Location = new System.Drawing.Point(134, 63);
            this.chkHonor.Name = "chkHonor";
            this.chkHonor.Size = new System.Drawing.Size(87, 31);
            this.chkHonor.TabIndex = 2;
            this.chkHonor.Text = "명예";
            this.chkHonor.UseVisualStyleBackColor = true;
            // 
            // chkMoney
            // 
            this.chkMoney.AutoSize = true;
            this.chkMoney.Font = new System.Drawing.Font("굴림", 20F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.chkMoney.Location = new System.Drawing.Point(17, 63);
            this.chkMoney.Name = "chkMoney";
            this.chkMoney.Size = new System.Drawing.Size(59, 31);
            this.chkMoney.TabIndex = 2;
            this.chkMoney.Text = "돈";
            this.chkMoney.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.radioDestroyer);
            this.groupBox2.Controls.Add(this.radiohum);
            this.groupBox2.Font = new System.Drawing.Font("굴림", 24F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.groupBox2.Location = new System.Drawing.Point(9, 203);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(779, 185);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "되고 싶은 사람";
            // 
            // radioDestroyer
            // 
            this.radioDestroyer.AutoSize = true;
            this.radioDestroyer.Font = new System.Drawing.Font("굴림", 20F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.radioDestroyer.Location = new System.Drawing.Point(17, 70);
            this.radioDestroyer.Name = "radioDestroyer";
            this.radioDestroyer.Size = new System.Drawing.Size(508, 31);
            this.radioDestroyer.TabIndex = 0;
            this.radioDestroyer.TabStop = true;
            this.radioDestroyer.Text = "카리스마 무소불위 파괴자(재산 20조)";
            this.radioDestroyer.UseVisualStyleBackColor = true;
            // 
            // radiohum
            // 
            this.radiohum.AutoSize = true;
            this.radiohum.Font = new System.Drawing.Font("굴림", 20F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.radiohum.Location = new System.Drawing.Point(17, 119);
            this.radiohum.Name = "radiohum";
            this.radiohum.Size = new System.Drawing.Size(542, 31);
            this.radiohum.TabIndex = 0;
            this.radiohum.TabStop = true;
            this.radiohum.Text = "평범하고 가정적인 사람(연봉 5000만원)";
            this.radiohum.UseVisualStyleBackColor = true;
            // 
            // btnSelect
            // 
            this.btnSelect.Location = new System.Drawing.Point(302, 399);
            this.btnSelect.Name = "btnSelect";
            this.btnSelect.Size = new System.Drawing.Size(183, 41);
            this.btnSelect.TabIndex = 2;
            this.btnSelect.Text = "당신의 선택은?";
            this.btnSelect.UseVisualStyleBackColor = true;
            this.btnSelect.Click += new System.EventHandler(this.button1_Click);
            // 
            // chkPower
            // 
            this.chkPower.AutoSize = true;
            this.chkPower.Font = new System.Drawing.Font("굴림", 20F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.chkPower.Location = new System.Drawing.Point(418, 63);
            this.chkPower.Name = "chkPower";
            this.chkPower.Size = new System.Drawing.Size(87, 31);
            this.chkPower.TabIndex = 3;
            this.chkPower.Text = "권력";
            this.chkPower.UseVisualStyleBackColor = true;
            // 
            // chkJustice
            // 
            this.chkJustice.AutoSize = true;
            this.chkJustice.Font = new System.Drawing.Font("굴림", 20F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.chkJustice.Location = new System.Drawing.Point(558, 63);
            this.chkJustice.Name = "chkJustice";
            this.chkJustice.Size = new System.Drawing.Size(87, 31);
            this.chkJustice.TabIndex = 3;
            this.chkJustice.Text = "정의";
            this.chkJustice.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnSelect);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.CheckBox chkMoney;
        private System.Windows.Forms.CheckBox chkHonor;
        private System.Windows.Forms.RadioButton radiohum;
        private System.Windows.Forms.RadioButton radioDestroyer;
        private System.Windows.Forms.Button btnSelect;
        private System.Windows.Forms.CheckBox chkForce;
        private System.Windows.Forms.CheckBox chkJustice;
        private System.Windows.Forms.CheckBox chkPower;
    }
}

