﻿namespace _22_TextBox
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
            this.tbView = new System.Windows.Forms.TextBox();
            this.tbWord = new System.Windows.Forms.TextBox();
            this.btnInput = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // tbView
            // 
            this.tbView.AcceptsReturn = true;
            this.tbView.BackColor = System.Drawing.SystemColors.Info;
            this.tbView.Font = new System.Drawing.Font("Consolas", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.tbView.Location = new System.Drawing.Point(12, 12);
            this.tbView.Multiline = true;
            this.tbView.Name = "tbView";
            this.tbView.ReadOnly = true;
            this.tbView.Size = new System.Drawing.Size(783, 309);
            this.tbView.TabIndex = 0;
            // 
            // tbWord
            // 
            this.tbWord.Font = new System.Drawing.Font("Consolas", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.tbWord.Location = new System.Drawing.Point(12, 333);
            this.tbWord.Name = "tbWord";
            this.tbWord.Size = new System.Drawing.Size(702, 28);
            this.tbWord.TabIndex = 1;
            this.tbWord.KeyDown += new System.Windows.Forms.KeyEventHandler(this.tbWord_KeyDown);
            // 
            // btnInput
            // 
            this.btnInput.Location = new System.Drawing.Point(720, 333);
            this.btnInput.Name = "btnInput";
            this.btnInput.Size = new System.Drawing.Size(75, 63);
            this.btnInput.TabIndex = 2;
            this.btnInput.Text = "입력";
            this.btnInput.UseVisualStyleBackColor = true;
            this.btnInput.Click += new System.EventHandler(this.btnInput_Click);
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(720, 402);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(75, 38);
            this.btnClear.TabIndex = 3;
            this.btnClear.Text = "지우개";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(807, 452);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.btnInput);
            this.Controls.Add(this.tbWord);
            this.Controls.Add(this.tbView);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tbView;
        private System.Windows.Forms.TextBox tbWord;
        private System.Windows.Forms.Button btnInput;
        private System.Windows.Forms.Button btnClear;
    }
}

