namespace _24_ListBox
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
            this.lbView = new System.Windows.Forms.ListBox();
            this.tbWord = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // lbView
            // 
            this.lbView.Font = new System.Drawing.Font("휴먼편지체", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.lbView.FormattingEnabled = true;
            this.lbView.ItemHeight = 24;
            this.lbView.Location = new System.Drawing.Point(12, 12);
            this.lbView.Name = "lbView";
            this.lbView.Size = new System.Drawing.Size(766, 460);
            this.lbView.TabIndex = 1;
            this.lbView.DoubleClick += new System.EventHandler(this.lbView_DoubleClick);
            // 
            // tbWord
            // 
            this.tbWord.Font = new System.Drawing.Font("휴먼옛체", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.tbWord.Location = new System.Drawing.Point(12, 494);
            this.tbWord.Name = "tbWord";
            this.tbWord.Size = new System.Drawing.Size(766, 32);
            this.tbWord.TabIndex = 0;
            this.tbWord.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.tbWord_KeyPress);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(790, 588);
            this.Controls.Add(this.tbWord);
            this.Controls.Add(this.lbView);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox lbView;
        private System.Windows.Forms.TextBox tbWord;
    }
}

