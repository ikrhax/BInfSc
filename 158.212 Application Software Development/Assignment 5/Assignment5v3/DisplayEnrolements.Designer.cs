namespace Assignment5v3
{
    partial class DisplayEnrolements
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DisplayEnrolements));
            this.grpbxSearch = new System.Windows.Forms.GroupBox();
            this.radbtnSearchByStudentID = new System.Windows.Forms.RadioButton();
            this.radbtnSearchByStudentName = new System.Windows.Forms.RadioButton();
            this.lstbxDetails = new System.Windows.Forms.ListBox();
            this.lblDetailsStudent = new System.Windows.Forms.Label();
            this.txtbxSearchString = new System.Windows.Forms.TextBox();
            this.lblSearchStringStudent = new System.Windows.Forms.Label();
            this.btnStudentSearch = new System.Windows.Forms.Button();
            this.grpbxSearch.SuspendLayout();
            this.SuspendLayout();
            // 
            // grpbxSearch
            // 
            this.grpbxSearch.Controls.Add(this.radbtnSearchByStudentID);
            this.grpbxSearch.Controls.Add(this.radbtnSearchByStudentName);
            this.grpbxSearch.Controls.Add(this.lstbxDetails);
            this.grpbxSearch.Controls.Add(this.lblDetailsStudent);
            this.grpbxSearch.Controls.Add(this.txtbxSearchString);
            this.grpbxSearch.Controls.Add(this.lblSearchStringStudent);
            this.grpbxSearch.Controls.Add(this.btnStudentSearch);
            this.grpbxSearch.Location = new System.Drawing.Point(12, 12);
            this.grpbxSearch.Name = "grpbxSearch";
            this.grpbxSearch.Size = new System.Drawing.Size(262, 557);
            this.grpbxSearch.TabIndex = 22;
            this.grpbxSearch.TabStop = false;
            this.grpbxSearch.Text = "Search for a Student or Paper";
            // 
            // radbtnSearchByStudentID
            // 
            this.radbtnSearchByStudentID.AutoSize = true;
            this.radbtnSearchByStudentID.Location = new System.Drawing.Point(132, 45);
            this.radbtnSearchByStudentID.Name = "radbtnSearchByStudentID";
            this.radbtnSearchByStudentID.Size = new System.Drawing.Size(123, 17);
            this.radbtnSearchByStudentID.TabIndex = 19;
            this.radbtnSearchByStudentID.TabStop = true;
            this.radbtnSearchByStudentID.Text = "Search for a Student";
            this.radbtnSearchByStudentID.UseVisualStyleBackColor = true;
            // 
            // radbtnSearchByStudentName
            // 
            this.radbtnSearchByStudentName.AutoSize = true;
            this.radbtnSearchByStudentName.Location = new System.Drawing.Point(13, 45);
            this.radbtnSearchByStudentName.Name = "radbtnSearchByStudentName";
            this.radbtnSearchByStudentName.Size = new System.Drawing.Size(114, 17);
            this.radbtnSearchByStudentName.TabIndex = 18;
            this.radbtnSearchByStudentName.TabStop = true;
            this.radbtnSearchByStudentName.Text = "Search for a Paper";
            this.radbtnSearchByStudentName.UseVisualStyleBackColor = true;
            // 
            // lstbxDetails
            // 
            this.lstbxDetails.FormattingEnabled = true;
            this.lstbxDetails.Location = new System.Drawing.Point(10, 209);
            this.lstbxDetails.Name = "lstbxDetails";
            this.lstbxDetails.Size = new System.Drawing.Size(245, 329);
            this.lstbxDetails.TabIndex = 17;
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
            this.txtbxSearchString.Location = new System.Drawing.Point(12, 108);
            this.txtbxSearchString.Name = "txtbxSearchString";
            this.txtbxSearchString.Size = new System.Drawing.Size(243, 20);
            this.txtbxSearchString.TabIndex = 7;
            // 
            // lblSearchStringStudent
            // 
            this.lblSearchStringStudent.AutoSize = true;
            this.lblSearchStringStudent.Location = new System.Drawing.Point(5, 92);
            this.lblSearchStringStudent.Name = "lblSearchStringStudent";
            this.lblSearchStringStudent.Size = new System.Drawing.Size(72, 13);
            this.lblSearchStringStudent.TabIndex = 2;
            this.lblSearchStringStudent.Text = "Enter Search:";
            // 
            // btnStudentSearch
            // 
            this.btnStudentSearch.Location = new System.Drawing.Point(9, 134);
            this.btnStudentSearch.Name = "btnStudentSearch";
            this.btnStudentSearch.Size = new System.Drawing.Size(246, 58);
            this.btnStudentSearch.TabIndex = 0;
            this.btnStudentSearch.Text = "Search";
            this.btnStudentSearch.UseVisualStyleBackColor = true;
            this.btnStudentSearch.Click += new System.EventHandler(this.btnStudentSearch_Click);
            // 
            // DisplayEnrolements
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(285, 576);
            this.Controls.Add(this.grpbxSearch);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "DisplayEnrolements";
            this.Text = "Display Enrolements";
            this.grpbxSearch.ResumeLayout(false);
            this.grpbxSearch.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox grpbxSearch;
        private System.Windows.Forms.RadioButton radbtnSearchByStudentID;
        private System.Windows.Forms.RadioButton radbtnSearchByStudentName;
        private System.Windows.Forms.ListBox lstbxDetails;
        private System.Windows.Forms.Label lblDetailsStudent;
        private System.Windows.Forms.TextBox txtbxSearchString;
        private System.Windows.Forms.Label lblSearchStringStudent;
        private System.Windows.Forms.Button btnStudentSearch;
    }
}