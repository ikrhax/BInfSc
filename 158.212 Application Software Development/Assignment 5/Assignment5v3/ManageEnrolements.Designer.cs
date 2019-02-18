namespace Assignment5v3
{
    partial class ManageEnrolements
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ManageEnrolements));
            this.grpbxSearchForAPaper = new System.Windows.Forms.GroupBox();
            this.radbtnSearchByPaperCode = new System.Windows.Forms.RadioButton();
            this.radbtnSearchByPaperName = new System.Windows.Forms.RadioButton();
            this.lstbxPaperDetails = new System.Windows.Forms.ListBox();
            this.lblPaperDetails = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.lblSearchStringPaper = new System.Windows.Forms.Label();
            this.btnPaperSearch = new System.Windows.Forms.Button();
            this.btnEnroleStudent = new System.Windows.Forms.Button();
            this.grpbxStudentSearch = new System.Windows.Forms.GroupBox();
            this.radbtnSearchByStudentID = new System.Windows.Forms.RadioButton();
            this.radbtnSearchByStudentName = new System.Windows.Forms.RadioButton();
            this.lstbxStudentDetails = new System.Windows.Forms.ListBox();
            this.lblDetailsStudent = new System.Windows.Forms.Label();
            this.txtbxSearchString = new System.Windows.Forms.TextBox();
            this.lblSearchStringStudent = new System.Windows.Forms.Label();
            this.btnStudentSearch = new System.Windows.Forms.Button();
            this.grpbxSearchForAPaper.SuspendLayout();
            this.grpbxStudentSearch.SuspendLayout();
            this.SuspendLayout();
            // 
            // grpbxSearchForAPaper
            // 
            this.grpbxSearchForAPaper.Controls.Add(this.radbtnSearchByPaperCode);
            this.grpbxSearchForAPaper.Controls.Add(this.radbtnSearchByPaperName);
            this.grpbxSearchForAPaper.Controls.Add(this.lstbxPaperDetails);
            this.grpbxSearchForAPaper.Controls.Add(this.lblPaperDetails);
            this.grpbxSearchForAPaper.Controls.Add(this.textBox1);
            this.grpbxSearchForAPaper.Controls.Add(this.lblSearchStringPaper);
            this.grpbxSearchForAPaper.Controls.Add(this.btnPaperSearch);
            this.grpbxSearchForAPaper.Location = new System.Drawing.Point(296, 13);
            this.grpbxSearchForAPaper.Name = "grpbxSearchForAPaper";
            this.grpbxSearchForAPaper.Size = new System.Drawing.Size(262, 556);
            this.grpbxSearchForAPaper.TabIndex = 22;
            this.grpbxSearchForAPaper.TabStop = false;
            this.grpbxSearchForAPaper.Text = "Search for a Paper";
            // 
            // radbtnSearchByPaperCode
            // 
            this.radbtnSearchByPaperCode.AutoSize = true;
            this.radbtnSearchByPaperCode.Location = new System.Drawing.Point(133, 44);
            this.radbtnSearchByPaperCode.Name = "radbtnSearchByPaperCode";
            this.radbtnSearchByPaperCode.Size = new System.Drawing.Size(102, 17);
            this.radbtnSearchByPaperCode.TabIndex = 21;
            this.radbtnSearchByPaperCode.TabStop = true;
            this.radbtnSearchByPaperCode.Text = "Search By Code";
            this.radbtnSearchByPaperCode.UseVisualStyleBackColor = true;
            // 
            // radbtnSearchByPaperName
            // 
            this.radbtnSearchByPaperName.AutoSize = true;
            this.radbtnSearchByPaperName.Location = new System.Drawing.Point(22, 44);
            this.radbtnSearchByPaperName.Name = "radbtnSearchByPaperName";
            this.radbtnSearchByPaperName.Size = new System.Drawing.Size(105, 17);
            this.radbtnSearchByPaperName.TabIndex = 20;
            this.radbtnSearchByPaperName.TabStop = true;
            this.radbtnSearchByPaperName.Text = "Search By Name";
            this.radbtnSearchByPaperName.UseVisualStyleBackColor = true;
            // 
            // lstbxPaperDetails
            // 
            this.lstbxPaperDetails.FormattingEnabled = true;
            this.lstbxPaperDetails.Location = new System.Drawing.Point(6, 244);
            this.lstbxPaperDetails.Name = "lstbxPaperDetails";
            this.lstbxPaperDetails.Size = new System.Drawing.Size(246, 303);
            this.lstbxPaperDetails.TabIndex = 18;
            // 
            // lblPaperDetails
            // 
            this.lblPaperDetails.AutoSize = true;
            this.lblPaperDetails.Location = new System.Drawing.Point(10, 266);
            this.lblPaperDetails.Name = "lblPaperDetails";
            this.lblPaperDetails.Size = new System.Drawing.Size(42, 13);
            this.lblPaperDetails.TabIndex = 16;
            this.lblPaperDetails.Text = "Details:";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(4, 125);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(248, 20);
            this.textBox1.TabIndex = 7;
            // 
            // lblSearchStringPaper
            // 
            this.lblSearchStringPaper.AutoSize = true;
            this.lblSearchStringPaper.Location = new System.Drawing.Point(6, 109);
            this.lblSearchStringPaper.Name = "lblSearchStringPaper";
            this.lblSearchStringPaper.Size = new System.Drawing.Size(72, 13);
            this.lblSearchStringPaper.TabIndex = 2;
            this.lblSearchStringPaper.Text = "Enter Search:";
            // 
            // btnPaperSearch
            // 
            this.btnPaperSearch.Location = new System.Drawing.Point(4, 169);
            this.btnPaperSearch.Name = "btnPaperSearch";
            this.btnPaperSearch.Size = new System.Drawing.Size(246, 58);
            this.btnPaperSearch.TabIndex = 0;
            this.btnPaperSearch.Text = "Search";
            this.btnPaperSearch.UseVisualStyleBackColor = true;
            // 
            // btnEnroleStudent
            // 
            this.btnEnroleStudent.Enabled = false;
            this.btnEnroleStudent.Location = new System.Drawing.Point(12, 575);
            this.btnEnroleStudent.Name = "btnEnroleStudent";
            this.btnEnroleStudent.Size = new System.Drawing.Size(546, 58);
            this.btnEnroleStudent.TabIndex = 23;
            this.btnEnroleStudent.Text = "Enrole this Student in This Paper";
            this.btnEnroleStudent.UseVisualStyleBackColor = true;
            // 
            // grpbxStudentSearch
            // 
            this.grpbxStudentSearch.Controls.Add(this.radbtnSearchByStudentID);
            this.grpbxStudentSearch.Controls.Add(this.radbtnSearchByStudentName);
            this.grpbxStudentSearch.Controls.Add(this.lstbxStudentDetails);
            this.grpbxStudentSearch.Controls.Add(this.lblDetailsStudent);
            this.grpbxStudentSearch.Controls.Add(this.txtbxSearchString);
            this.grpbxStudentSearch.Controls.Add(this.lblSearchStringStudent);
            this.grpbxStudentSearch.Controls.Add(this.btnStudentSearch);
            this.grpbxStudentSearch.Location = new System.Drawing.Point(12, 12);
            this.grpbxStudentSearch.Name = "grpbxStudentSearch";
            this.grpbxStudentSearch.Size = new System.Drawing.Size(262, 557);
            this.grpbxStudentSearch.TabIndex = 21;
            this.grpbxStudentSearch.TabStop = false;
            this.grpbxStudentSearch.Text = "Search for a Student";
            // 
            // radbtnSearchByStudentID
            // 
            this.radbtnSearchByStudentID.AutoSize = true;
            this.radbtnSearchByStudentID.Location = new System.Drawing.Point(140, 45);
            this.radbtnSearchByStudentID.Name = "radbtnSearchByStudentID";
            this.radbtnSearchByStudentID.Size = new System.Drawing.Size(88, 17);
            this.radbtnSearchByStudentID.TabIndex = 19;
            this.radbtnSearchByStudentID.TabStop = true;
            this.radbtnSearchByStudentID.Text = "Search By ID";
            this.radbtnSearchByStudentID.UseVisualStyleBackColor = true;
            // 
            // radbtnSearchByStudentName
            // 
            this.radbtnSearchByStudentName.AutoSize = true;
            this.radbtnSearchByStudentName.Location = new System.Drawing.Point(29, 45);
            this.radbtnSearchByStudentName.Name = "radbtnSearchByStudentName";
            this.radbtnSearchByStudentName.Size = new System.Drawing.Size(105, 17);
            this.radbtnSearchByStudentName.TabIndex = 18;
            this.radbtnSearchByStudentName.TabStop = true;
            this.radbtnSearchByStudentName.Text = "Search By Name";
            this.radbtnSearchByStudentName.UseVisualStyleBackColor = true;
            // 
            // lstbxStudentDetails
            // 
            this.lstbxStudentDetails.FormattingEnabled = true;
            this.lstbxStudentDetails.Location = new System.Drawing.Point(9, 245);
            this.lstbxStudentDetails.Name = "lstbxStudentDetails";
            this.lstbxStudentDetails.Size = new System.Drawing.Size(246, 303);
            this.lstbxStudentDetails.TabIndex = 17;
            // 
            // lblDetailsStudent
            // 
            this.lblDetailsStudent.AutoSize = true;
            this.lblDetailsStudent.Location = new System.Drawing.Point(10, 267);
            this.lblDetailsStudent.Name = "lblDetailsStudent";
            this.lblDetailsStudent.Size = new System.Drawing.Size(42, 13);
            this.lblDetailsStudent.TabIndex = 16;
            this.lblDetailsStudent.Text = "Details:";
            // 
            // txtbxSearchString
            // 
            this.txtbxSearchString.Location = new System.Drawing.Point(13, 126);
            this.txtbxSearchString.Name = "txtbxSearchString";
            this.txtbxSearchString.Size = new System.Drawing.Size(243, 20);
            this.txtbxSearchString.TabIndex = 7;
            // 
            // lblSearchStringStudent
            // 
            this.lblSearchStringStudent.AutoSize = true;
            this.lblSearchStringStudent.Location = new System.Drawing.Point(6, 110);
            this.lblSearchStringStudent.Name = "lblSearchStringStudent";
            this.lblSearchStringStudent.Size = new System.Drawing.Size(72, 13);
            this.lblSearchStringStudent.TabIndex = 2;
            this.lblSearchStringStudent.Text = "Enter Search:";
            // 
            // btnStudentSearch
            // 
            this.btnStudentSearch.Location = new System.Drawing.Point(10, 170);
            this.btnStudentSearch.Name = "btnStudentSearch";
            this.btnStudentSearch.Size = new System.Drawing.Size(246, 58);
            this.btnStudentSearch.TabIndex = 0;
            this.btnStudentSearch.Text = "Search";
            this.btnStudentSearch.UseVisualStyleBackColor = true;
            // 
            // ManageEnrolements
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(574, 645);
            this.Controls.Add(this.grpbxSearchForAPaper);
            this.Controls.Add(this.btnEnroleStudent);
            this.Controls.Add(this.grpbxStudentSearch);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "ManageEnrolements";
            this.Text = "Manage Enrolements";
            this.grpbxSearchForAPaper.ResumeLayout(false);
            this.grpbxSearchForAPaper.PerformLayout();
            this.grpbxStudentSearch.ResumeLayout(false);
            this.grpbxStudentSearch.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox grpbxSearchForAPaper;
        private System.Windows.Forms.RadioButton radbtnSearchByPaperCode;
        private System.Windows.Forms.RadioButton radbtnSearchByPaperName;
        private System.Windows.Forms.ListBox lstbxPaperDetails;
        private System.Windows.Forms.Label lblPaperDetails;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label lblSearchStringPaper;
        private System.Windows.Forms.Button btnPaperSearch;
        private System.Windows.Forms.Button btnEnroleStudent;
        private System.Windows.Forms.GroupBox grpbxStudentSearch;
        private System.Windows.Forms.RadioButton radbtnSearchByStudentID;
        private System.Windows.Forms.RadioButton radbtnSearchByStudentName;
        private System.Windows.Forms.ListBox lstbxStudentDetails;
        private System.Windows.Forms.Label lblDetailsStudent;
        private System.Windows.Forms.TextBox txtbxSearchString;
        private System.Windows.Forms.Label lblSearchStringStudent;
        private System.Windows.Forms.Button btnStudentSearch;
    }
}