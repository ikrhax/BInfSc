namespace Assignment5v3
{
    partial class CreatePaper
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CreatePaper));
            this.grpBoxPaperInformation = new System.Windows.Forms.GroupBox();
            this.lblPaperDescription = new System.Windows.Forms.Label();
            this.rchtxtbxPaperDescription = new System.Windows.Forms.RichTextBox();
            this.lblPaperCoordinator = new System.Windows.Forms.Label();
            this.btnCreatePaper = new System.Windows.Forms.Button();
            this.lblPaperCode = new System.Windows.Forms.Label();
            this.txtbxPaperName = new System.Windows.Forms.TextBox();
            this.lblPaperName = new System.Windows.Forms.Label();
            this.txtbxPaperCoordinator = new System.Windows.Forms.TextBox();
            this.txtbxPaperCode = new System.Windows.Forms.TextBox();
            this.grpBoxPaperInformation.SuspendLayout();
            this.SuspendLayout();
            // 
            // grpBoxPaperInformation
            // 
            this.grpBoxPaperInformation.Controls.Add(this.lblPaperDescription);
            this.grpBoxPaperInformation.Controls.Add(this.rchtxtbxPaperDescription);
            this.grpBoxPaperInformation.Controls.Add(this.lblPaperCoordinator);
            this.grpBoxPaperInformation.Controls.Add(this.btnCreatePaper);
            this.grpBoxPaperInformation.Controls.Add(this.lblPaperCode);
            this.grpBoxPaperInformation.Controls.Add(this.txtbxPaperName);
            this.grpBoxPaperInformation.Controls.Add(this.lblPaperName);
            this.grpBoxPaperInformation.Controls.Add(this.txtbxPaperCoordinator);
            this.grpBoxPaperInformation.Controls.Add(this.txtbxPaperCode);
            this.grpBoxPaperInformation.Location = new System.Drawing.Point(12, 12);
            this.grpBoxPaperInformation.Name = "grpBoxPaperInformation";
            this.grpBoxPaperInformation.Size = new System.Drawing.Size(342, 519);
            this.grpBoxPaperInformation.TabIndex = 11;
            this.grpBoxPaperInformation.TabStop = false;
            this.grpBoxPaperInformation.Text = "Paper Information";
            // 
            // lblPaperDescription
            // 
            this.lblPaperDescription.AutoSize = true;
            this.lblPaperDescription.Location = new System.Drawing.Point(12, 224);
            this.lblPaperDescription.Name = "lblPaperDescription";
            this.lblPaperDescription.Size = new System.Drawing.Size(94, 13);
            this.lblPaperDescription.TabIndex = 9;
            this.lblPaperDescription.Text = "Paper Description:";
            // 
            // rchtxtbxPaperDescription
            // 
            this.rchtxtbxPaperDescription.Location = new System.Drawing.Point(9, 243);
            this.rchtxtbxPaperDescription.Name = "rchtxtbxPaperDescription";
            this.rchtxtbxPaperDescription.Size = new System.Drawing.Size(327, 186);
            this.rchtxtbxPaperDescription.TabIndex = 5;
            this.rchtxtbxPaperDescription.Text = "";
            // 
            // lblPaperCoordinator
            // 
            this.lblPaperCoordinator.AutoSize = true;
            this.lblPaperCoordinator.Location = new System.Drawing.Point(12, 153);
            this.lblPaperCoordinator.Name = "lblPaperCoordinator";
            this.lblPaperCoordinator.Size = new System.Drawing.Size(95, 13);
            this.lblPaperCoordinator.TabIndex = 8;
            this.lblPaperCoordinator.Text = "Paper Coordinator:";
            // 
            // btnCreatePaper
            // 
            this.btnCreatePaper.Location = new System.Drawing.Point(9, 435);
            this.btnCreatePaper.Name = "btnCreatePaper";
            this.btnCreatePaper.Size = new System.Drawing.Size(327, 70);
            this.btnCreatePaper.TabIndex = 0;
            this.btnCreatePaper.Text = "Create a Paper";
            this.btnCreatePaper.UseVisualStyleBackColor = true;
            this.btnCreatePaper.Click += new System.EventHandler(this.btnCreatePaper_Click);
            // 
            // lblPaperCode
            // 
            this.lblPaperCode.AutoSize = true;
            this.lblPaperCode.Location = new System.Drawing.Point(12, 86);
            this.lblPaperCode.Name = "lblPaperCode";
            this.lblPaperCode.Size = new System.Drawing.Size(66, 13);
            this.lblPaperCode.TabIndex = 7;
            this.lblPaperCode.Text = "Paper Code:";
            // 
            // txtbxPaperName
            // 
            this.txtbxPaperName.Location = new System.Drawing.Point(9, 48);
            this.txtbxPaperName.Name = "txtbxPaperName";
            this.txtbxPaperName.Size = new System.Drawing.Size(327, 20);
            this.txtbxPaperName.TabIndex = 1;
            // 
            // lblPaperName
            // 
            this.lblPaperName.AutoSize = true;
            this.lblPaperName.Location = new System.Drawing.Point(9, 29);
            this.lblPaperName.Name = "lblPaperName";
            this.lblPaperName.Size = new System.Drawing.Size(69, 13);
            this.lblPaperName.TabIndex = 6;
            this.lblPaperName.Text = "Paper Name:";
            // 
            // txtbxPaperCoordinator
            // 
            this.txtbxPaperCoordinator.Location = new System.Drawing.Point(9, 172);
            this.txtbxPaperCoordinator.Name = "txtbxPaperCoordinator";
            this.txtbxPaperCoordinator.Size = new System.Drawing.Size(327, 20);
            this.txtbxPaperCoordinator.TabIndex = 3;
            // 
            // txtbxPaperCode
            // 
            this.txtbxPaperCode.Location = new System.Drawing.Point(9, 105);
            this.txtbxPaperCode.Name = "txtbxPaperCode";
            this.txtbxPaperCode.Size = new System.Drawing.Size(327, 20);
            this.txtbxPaperCode.TabIndex = 4;
            // 
            // CreatePaper
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(365, 539);
            this.Controls.Add(this.grpBoxPaperInformation);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "CreatePaper";
            this.Text = "Create a Paper";
            this.grpBoxPaperInformation.ResumeLayout(false);
            this.grpBoxPaperInformation.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox grpBoxPaperInformation;
        private System.Windows.Forms.Label lblPaperDescription;
        private System.Windows.Forms.RichTextBox rchtxtbxPaperDescription;
        private System.Windows.Forms.Label lblPaperCoordinator;
        private System.Windows.Forms.Button btnCreatePaper;
        private System.Windows.Forms.Label lblPaperCode;
        private System.Windows.Forms.TextBox txtbxPaperName;
        private System.Windows.Forms.Label lblPaperName;
        private System.Windows.Forms.TextBox txtbxPaperCoordinator;
        private System.Windows.Forms.TextBox txtbxPaperCode;
    }
}