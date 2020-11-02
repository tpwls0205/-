namespace SQLApp
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
            this.lbResultLog = new System.Windows.Forms.ListBox();
            this.btnDBConnect = new System.Windows.Forms.Button();
            this.btnDBDisconnect = new System.Windows.Forms.Button();
            this.btnSelectSQL = new System.Windows.Forms.Button();
            this.btnInsertSQL = new System.Windows.Forms.Button();
            this.btnUpdataSQL = new System.Windows.Forms.Button();
            this.btnDeleteSQL = new System.Windows.Forms.Button();
            this.tbConnectInfo = new System.Windows.Forms.TextBox();
            this.btnErase = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lbResultLog
            // 
            this.lbResultLog.Font = new System.Drawing.Font("돋움체", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.lbResultLog.FormattingEnabled = true;
            this.lbResultLog.ItemHeight = 32;
            this.lbResultLog.Location = new System.Drawing.Point(7, 73);
            this.lbResultLog.Name = "lbResultLog";
            this.lbResultLog.Size = new System.Drawing.Size(920, 388);
            this.lbResultLog.TabIndex = 0;
            // 
            // btnDBConnect
            // 
            this.btnDBConnect.Font = new System.Drawing.Font("돋움체", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btnDBConnect.Location = new System.Drawing.Point(942, 12);
            this.btnDBConnect.Name = "btnDBConnect";
            this.btnDBConnect.Size = new System.Drawing.Size(259, 55);
            this.btnDBConnect.TabIndex = 1;
            this.btnDBConnect.Text = "DB Connect";
            this.btnDBConnect.UseVisualStyleBackColor = true;
            this.btnDBConnect.Click += new System.EventHandler(this.btnDBConnect_Click);
            // 
            // btnDBDisconnect
            // 
            this.btnDBDisconnect.Font = new System.Drawing.Font("돋움체", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btnDBDisconnect.Location = new System.Drawing.Point(942, 73);
            this.btnDBDisconnect.Name = "btnDBDisconnect";
            this.btnDBDisconnect.Size = new System.Drawing.Size(259, 55);
            this.btnDBDisconnect.TabIndex = 1;
            this.btnDBDisconnect.Text = "DB Disconnect";
            this.btnDBDisconnect.UseVisualStyleBackColor = true;
            this.btnDBDisconnect.Click += new System.EventHandler(this.btnDBDisconnect_Click);
            // 
            // btnSelectSQL
            // 
            this.btnSelectSQL.Font = new System.Drawing.Font("돋움체", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btnSelectSQL.Location = new System.Drawing.Point(942, 186);
            this.btnSelectSQL.Name = "btnSelectSQL";
            this.btnSelectSQL.Size = new System.Drawing.Size(259, 55);
            this.btnSelectSQL.TabIndex = 1;
            this.btnSelectSQL.Text = "Select SQL";
            this.btnSelectSQL.UseVisualStyleBackColor = true;
            this.btnSelectSQL.Click += new System.EventHandler(this.btnSelectSQL_Click);
            // 
            // btnInsertSQL
            // 
            this.btnInsertSQL.Font = new System.Drawing.Font("돋움체", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btnInsertSQL.Location = new System.Drawing.Point(942, 247);
            this.btnInsertSQL.Name = "btnInsertSQL";
            this.btnInsertSQL.Size = new System.Drawing.Size(259, 55);
            this.btnInsertSQL.TabIndex = 1;
            this.btnInsertSQL.Text = "Insert SQL";
            this.btnInsertSQL.UseVisualStyleBackColor = true;
            this.btnInsertSQL.Click += new System.EventHandler(this.btnInsertSQL_Click);
            // 
            // btnUpdataSQL
            // 
            this.btnUpdataSQL.Font = new System.Drawing.Font("돋움체", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btnUpdataSQL.Location = new System.Drawing.Point(942, 308);
            this.btnUpdataSQL.Name = "btnUpdataSQL";
            this.btnUpdataSQL.Size = new System.Drawing.Size(259, 55);
            this.btnUpdataSQL.TabIndex = 1;
            this.btnUpdataSQL.Text = "Updata SQL";
            this.btnUpdataSQL.UseVisualStyleBackColor = true;
            this.btnUpdataSQL.Click += new System.EventHandler(this.btnUpdataSQL_Click);
            // 
            // btnDeleteSQL
            // 
            this.btnDeleteSQL.Font = new System.Drawing.Font("돋움체", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btnDeleteSQL.Location = new System.Drawing.Point(942, 369);
            this.btnDeleteSQL.Name = "btnDeleteSQL";
            this.btnDeleteSQL.Size = new System.Drawing.Size(259, 55);
            this.btnDeleteSQL.TabIndex = 1;
            this.btnDeleteSQL.Text = "Delete SQL";
            this.btnDeleteSQL.UseVisualStyleBackColor = true;
            this.btnDeleteSQL.Click += new System.EventHandler(this.btnDeleteSQL_Click);
            // 
            // tbConnectInfo
            // 
            this.tbConnectInfo.Font = new System.Drawing.Font("돋움체", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.tbConnectInfo.Location = new System.Drawing.Point(7, 12);
            this.tbConnectInfo.Name = "tbConnectInfo";
            this.tbConnectInfo.Size = new System.Drawing.Size(920, 44);
            this.tbConnectInfo.TabIndex = 2;
            // 
            // btnErase
            // 
            this.btnErase.Font = new System.Drawing.Font("돋움체", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btnErase.Location = new System.Drawing.Point(942, 430);
            this.btnErase.Name = "btnErase";
            this.btnErase.Size = new System.Drawing.Size(259, 55);
            this.btnErase.TabIndex = 1;
            this.btnErase.Text = "Erase";
            this.btnErase.UseVisualStyleBackColor = true;
            this.btnErase.Click += new System.EventHandler(this.btnErase_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1213, 557);
            this.Controls.Add(this.tbConnectInfo);
            this.Controls.Add(this.btnErase);
            this.Controls.Add(this.btnDeleteSQL);
            this.Controls.Add(this.btnUpdataSQL);
            this.Controls.Add(this.btnInsertSQL);
            this.Controls.Add(this.btnSelectSQL);
            this.Controls.Add(this.btnDBDisconnect);
            this.Controls.Add(this.btnDBConnect);
            this.Controls.Add(this.lbResultLog);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox lbResultLog;
        private System.Windows.Forms.Button btnDBConnect;
        private System.Windows.Forms.Button btnDBDisconnect;
        private System.Windows.Forms.Button btnSelectSQL;
        private System.Windows.Forms.Button btnInsertSQL;
        private System.Windows.Forms.Button btnUpdataSQL;
        private System.Windows.Forms.Button btnDeleteSQL;
        private System.Windows.Forms.TextBox tbConnectInfo;
        private System.Windows.Forms.Button btnErase;
    }
}

