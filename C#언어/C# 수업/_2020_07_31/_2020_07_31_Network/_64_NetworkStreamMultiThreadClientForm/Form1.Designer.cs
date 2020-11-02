namespace _64_NetworkStreamMultiThreadClientForm
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.tbIp = new System.Windows.Forms.TextBox();
            this.tbPort = new System.Windows.Forms.TextBox();
            this.btnConnect = new System.Windows.Forms.Button();
            this.btnDisConnect = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.lbLog = new System.Windows.Forms.ListBox();
            this.tbChat = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("돋움", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label1.Location = new System.Drawing.Point(31, 48);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(155, 32);
            this.label1.TabIndex = 0;
            this.label1.Text = "Server IP";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("돋움", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label2.Location = new System.Drawing.Point(31, 113);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(188, 32);
            this.label2.TabIndex = 0;
            this.label2.Text = "Server Port";
            // 
            // tbIp
            // 
            this.tbIp.Font = new System.Drawing.Font("돋움", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.tbIp.Location = new System.Drawing.Point(259, 45);
            this.tbIp.Name = "tbIp";
            this.tbIp.Size = new System.Drawing.Size(229, 44);
            this.tbIp.TabIndex = 1;
            this.tbIp.Text = "127.0.0.1";
            this.tbIp.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // tbPort
            // 
            this.tbPort.Font = new System.Drawing.Font("돋움", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.tbPort.Location = new System.Drawing.Point(259, 110);
            this.tbPort.Name = "tbPort";
            this.tbPort.Size = new System.Drawing.Size(229, 44);
            this.tbPort.TabIndex = 1;
            this.tbPort.Text = "9000";
            this.tbPort.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // btnConnect
            // 
            this.btnConnect.Font = new System.Drawing.Font("돋움", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btnConnect.Location = new System.Drawing.Point(550, 40);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(111, 58);
            this.btnConnect.TabIndex = 2;
            this.btnConnect.Text = "Connect";
            this.btnConnect.UseVisualStyleBackColor = true;
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // btnDisConnect
            // 
            this.btnDisConnect.Font = new System.Drawing.Font("돋움", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btnDisConnect.Location = new System.Drawing.Point(550, 105);
            this.btnDisConnect.Name = "btnDisConnect";
            this.btnDisConnect.Size = new System.Drawing.Size(111, 58);
            this.btnDisConnect.TabIndex = 2;
            this.btnDisConnect.Text = "DisConnect";
            this.btnDisConnect.UseVisualStyleBackColor = true;
            this.btnDisConnect.Click += new System.EventHandler(this.btnDisConnect_Click);
            // 
            // btnClear
            // 
            this.btnClear.Font = new System.Drawing.Font("돋움", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btnClear.Location = new System.Drawing.Point(667, 105);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(111, 58);
            this.btnClear.TabIndex = 2;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // lbLog
            // 
            this.lbLog.Font = new System.Drawing.Font("돋움", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.lbLog.FormattingEnabled = true;
            this.lbLog.ItemHeight = 27;
            this.lbLog.Location = new System.Drawing.Point(37, 181);
            this.lbLog.Name = "lbLog";
            this.lbLog.Size = new System.Drawing.Size(741, 328);
            this.lbLog.TabIndex = 3;
            // 
            // tbChat
            // 
            this.tbChat.Font = new System.Drawing.Font("돋움", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.tbChat.Location = new System.Drawing.Point(37, 526);
            this.tbChat.Name = "tbChat";
            this.tbChat.Size = new System.Drawing.Size(741, 39);
            this.tbChat.TabIndex = 4;
            this.tbChat.KeyDown += new System.Windows.Forms.KeyEventHandler(this.tbChat_KeyDown);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(809, 589);
            this.Controls.Add(this.tbChat);
            this.Controls.Add(this.lbLog);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.btnDisConnect);
            this.Controls.Add(this.btnConnect);
            this.Controls.Add(this.tbPort);
            this.Controls.Add(this.tbIp);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "z";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox tbIp;
        private System.Windows.Forms.TextBox tbPort;
        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.Button btnDisConnect;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.ListBox lbLog;
        private System.Windows.Forms.TextBox tbChat;
    }
}

