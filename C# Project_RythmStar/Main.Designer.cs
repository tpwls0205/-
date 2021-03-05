namespace _RythmStar
{
    partial class Main
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.startGame = new System.Windows.Forms.Button();
            this.endGame = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // startGame
            // 
            this.startGame.BackColor = System.Drawing.Color.DarkOrchid;
            this.startGame.FlatAppearance.BorderSize = 0;
            this.startGame.Font = new System.Drawing.Font("휴먼편지체", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.startGame.ForeColor = System.Drawing.Color.RosyBrown;
            this.startGame.Location = new System.Drawing.Point(283, 559);
            this.startGame.Name = "startGame";
            this.startGame.Size = new System.Drawing.Size(146, 69);
            this.startGame.TabIndex = 0;
            this.startGame.Text = "Game Start";
            this.startGame.UseVisualStyleBackColor = false;
            this.startGame.Click += new System.EventHandler(this.startGame_Click);
            // 
            // endGame
            // 
            this.endGame.BackColor = System.Drawing.Color.DarkOrchid;
            this.endGame.FlatAppearance.BorderSize = 0;
            this.endGame.Font = new System.Drawing.Font("휴먼편지체", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.endGame.ForeColor = System.Drawing.Color.RosyBrown;
            this.endGame.Location = new System.Drawing.Point(514, 559);
            this.endGame.Name = "endGame";
            this.endGame.Size = new System.Drawing.Size(146, 69);
            this.endGame.TabIndex = 0;
            this.endGame.Text = "End Game";
            this.endGame.UseVisualStyleBackColor = false;
            this.endGame.Click += new System.EventHandler(this.endGame_Click);
            // 
            // Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::_RythmStar.Properties.Resources.maindj;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(871, 662);
            this.Controls.Add(this.endGame);
            this.Controls.Add(this.startGame);
            this.Name = "Main";
            this.Text = "Main";
            this.Load += new System.EventHandler(this.Main_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button startGame;
        private System.Windows.Forms.Button endGame;
    }
}