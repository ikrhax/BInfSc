namespace Assignment5v3
{
    partial class MainMenu
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainMenu));
            this.grpbxStudentPaperManagement = new System.Windows.Forms.GroupBox();
            this.btnStudentCreation = new System.Windows.Forms.Button();
            this.btnCreatePaper = new System.Windows.Forms.Button();
            this.grpbxEnrolementManagement = new System.Windows.Forms.GroupBox();
            this.btnEnrolementManagement = new System.Windows.Forms.Button();
            this.grpbxFileManagement = new System.Windows.Forms.GroupBox();
            this.btnImport = new System.Windows.Forms.Button();
            this.btnExport = new System.Windows.Forms.Button();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusStudents = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusPapers = new System.Windows.Forms.ToolStripStatusLabel();
            this.timerMain = new System.Windows.Forms.Timer(this.components);
            this.btnDisplayEnrolements = new System.Windows.Forms.Button();
            this.grpbxStudentPaperManagement.SuspendLayout();
            this.grpbxEnrolementManagement.SuspendLayout();
            this.grpbxFileManagement.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // grpbxStudentPaperManagement
            // 
            this.grpbxStudentPaperManagement.Controls.Add(this.btnStudentCreation);
            this.grpbxStudentPaperManagement.Controls.Add(this.btnCreatePaper);
            this.grpbxStudentPaperManagement.Location = new System.Drawing.Point(334, 12);
            this.grpbxStudentPaperManagement.Name = "grpbxStudentPaperManagement";
            this.grpbxStudentPaperManagement.Size = new System.Drawing.Size(316, 227);
            this.grpbxStudentPaperManagement.TabIndex = 7;
            this.grpbxStudentPaperManagement.TabStop = false;
            this.grpbxStudentPaperManagement.Text = "Create a Student or Paper";
            // 
            // btnStudentCreation
            // 
            this.btnStudentCreation.Location = new System.Drawing.Point(6, 52);
            this.btnStudentCreation.Name = "btnStudentCreation";
            this.btnStudentCreation.Size = new System.Drawing.Size(304, 75);
            this.btnStudentCreation.TabIndex = 5;
            this.btnStudentCreation.Text = "Create a Student";
            this.btnStudentCreation.UseVisualStyleBackColor = true;
            this.btnStudentCreation.Click += new System.EventHandler(this.btnStudentCreation_Click);
            // 
            // btnCreatePaper
            // 
            this.btnCreatePaper.Location = new System.Drawing.Point(6, 138);
            this.btnCreatePaper.Name = "btnCreatePaper";
            this.btnCreatePaper.Size = new System.Drawing.Size(304, 75);
            this.btnCreatePaper.TabIndex = 8;
            this.btnCreatePaper.Text = "Create a Paper";
            this.btnCreatePaper.UseVisualStyleBackColor = true;
            this.btnCreatePaper.Click += new System.EventHandler(this.btnCreatePaper_Click);
            // 
            // grpbxEnrolementManagement
            // 
            this.grpbxEnrolementManagement.Controls.Add(this.btnDisplayEnrolements);
            this.grpbxEnrolementManagement.Controls.Add(this.btnEnrolementManagement);
            this.grpbxEnrolementManagement.Location = new System.Drawing.Point(656, 12);
            this.grpbxEnrolementManagement.Name = "grpbxEnrolementManagement";
            this.grpbxEnrolementManagement.Size = new System.Drawing.Size(316, 227);
            this.grpbxEnrolementManagement.TabIndex = 6;
            this.grpbxEnrolementManagement.TabStop = false;
            this.grpbxEnrolementManagement.Text = "Manage Enrolements";
            // 
            // btnEnrolementManagement
            // 
            this.btnEnrolementManagement.Location = new System.Drawing.Point(6, 52);
            this.btnEnrolementManagement.Name = "btnEnrolementManagement";
            this.btnEnrolementManagement.Size = new System.Drawing.Size(304, 71);
            this.btnEnrolementManagement.TabIndex = 7;
            this.btnEnrolementManagement.Text = "Enrole a Student in a Paper";
            this.btnEnrolementManagement.UseVisualStyleBackColor = true;
            this.btnEnrolementManagement.Click += new System.EventHandler(this.btnEnrolementManagement_Click);
            // 
            // grpbxFileManagement
            // 
            this.grpbxFileManagement.Controls.Add(this.btnImport);
            this.grpbxFileManagement.Controls.Add(this.btnExport);
            this.grpbxFileManagement.Location = new System.Drawing.Point(12, 12);
            this.grpbxFileManagement.Name = "grpbxFileManagement";
            this.grpbxFileManagement.Size = new System.Drawing.Size(316, 227);
            this.grpbxFileManagement.TabIndex = 5;
            this.grpbxFileManagement.TabStop = false;
            this.grpbxFileManagement.Text = "File Management";
            // 
            // btnImport
            // 
            this.btnImport.Location = new System.Drawing.Point(7, 52);
            this.btnImport.Name = "btnImport";
            this.btnImport.Size = new System.Drawing.Size(304, 71);
            this.btnImport.TabIndex = 3;
            this.btnImport.Text = "Import a Student or Paper";
            this.btnImport.UseVisualStyleBackColor = true;
            this.btnImport.Click += new System.EventHandler(this.btnImport_Click);
            // 
            // btnExport
            // 
            this.btnExport.Location = new System.Drawing.Point(7, 138);
            this.btnExport.Name = "btnExport";
            this.btnExport.Size = new System.Drawing.Size(304, 75);
            this.btnExport.TabIndex = 0;
            this.btnExport.Text = "Export a Student or Paper";
            this.btnExport.UseVisualStyleBackColor = true;
            this.btnExport.Click += new System.EventHandler(this.btnExport_Click);
            // 
            // statusStrip1
            // 
            this.statusStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusStudents,
            this.toolStripStatusPapers});
            this.statusStrip1.Location = new System.Drawing.Point(0, 249);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Padding = new System.Windows.Forms.Padding(1, 0, 9, 0);
            this.statusStrip1.Size = new System.Drawing.Size(984, 22);
            this.statusStrip1.TabIndex = 8;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolStripStatusStudents
            // 
            this.toolStripStatusStudents.Name = "toolStripStatusStudents";
            this.toolStripStatusStudents.Size = new System.Drawing.Size(65, 17);
            this.toolStripStatusStudents.Text = "Students: 0";
            // 
            // toolStripStatusPapers
            // 
            this.toolStripStatusPapers.Name = "toolStripStatusPapers";
            this.toolStripStatusPapers.Size = new System.Drawing.Size(54, 17);
            this.toolStripStatusPapers.Text = "Papers: 0";
            // 
            // timerMain
            // 
            this.timerMain.Enabled = true;
            this.timerMain.Interval = 1000;
            this.timerMain.Tick += new System.EventHandler(this.timerMain_Tick);
            // 
            // btnDisplayEnrolements
            // 
            this.btnDisplayEnrolements.Location = new System.Drawing.Point(6, 140);
            this.btnDisplayEnrolements.Name = "btnDisplayEnrolements";
            this.btnDisplayEnrolements.Size = new System.Drawing.Size(304, 71);
            this.btnDisplayEnrolements.TabIndex = 8;
            this.btnDisplayEnrolements.Text = "Display Current Enrolements";
            this.btnDisplayEnrolements.UseVisualStyleBackColor = true;
            // 
            // MainMenu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(984, 271);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.grpbxStudentPaperManagement);
            this.Controls.Add(this.grpbxEnrolementManagement);
            this.Controls.Add(this.grpbxFileManagement);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "MainMenu";
            this.Text = "Main Menu";
            this.grpbxStudentPaperManagement.ResumeLayout(false);
            this.grpbxEnrolementManagement.ResumeLayout(false);
            this.grpbxFileManagement.ResumeLayout(false);
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox grpbxStudentPaperManagement;
        private System.Windows.Forms.Button btnStudentCreation;
        private System.Windows.Forms.Button btnCreatePaper;
        private System.Windows.Forms.GroupBox grpbxEnrolementManagement;
        private System.Windows.Forms.Button btnEnrolementManagement;
        private System.Windows.Forms.GroupBox grpbxFileManagement;
        private System.Windows.Forms.Button btnImport;
        private System.Windows.Forms.Button btnExport;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusStudents;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusPapers;
        private System.Windows.Forms.Timer timerMain;
        private System.Windows.Forms.Button btnDisplayEnrolements;
    }
}

