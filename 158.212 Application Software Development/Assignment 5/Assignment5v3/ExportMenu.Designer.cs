namespace Assignment5v3
{
    partial class ExportMenu
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ExportMenu));
            this.btnExport = new System.Windows.Forms.Button();
            this.grpbxStudentPaperSearch = new System.Windows.Forms.GroupBox();
            this.lblDetailsStudent = new System.Windows.Forms.Label();
            this.rchtxtbxStudentDetails = new System.Windows.Forms.RichTextBox();
            this.txtbxSearchString = new System.Windows.Forms.TextBox();
            this.lblSearchStringStudent = new System.Windows.Forms.Label();
            this.btnStudentSearch = new System.Windows.Forms.Button();
            this.grpbxStudentPaperSearch.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnExport
            // 
            this.btnExport.Enabled = false;
            this.btnExport.Location = new System.Drawing.Point(12, 436);
            this.btnExport.Name = "btnExport";
            this.btnExport.Size = new System.Drawing.Size(262, 58);
            this.btnExport.TabIndex = 24;
            this.btnExport.Text = "Export this Student or this Paper";
            this.btnExport.UseVisualStyleBackColor = true;
            // 
            // grpbxStudentPaperSearch
            // 
            this.grpbxStudentPaperSearch.Controls.Add(this.lblDetailsStudent);
            this.grpbxStudentPaperSearch.Controls.Add(this.rchtxtbxStudentDetails);
            this.grpbxStudentPaperSearch.Controls.Add(this.txtbxSearchString);
            this.grpbxStudentPaperSearch.Controls.Add(this.lblSearchStringStudent);
            this.grpbxStudentPaperSearch.Controls.Add(this.btnStudentSearch);
            this.grpbxStudentPaperSearch.Location = new System.Drawing.Point(12, 12);
            this.grpbxStudentPaperSearch.Name = "grpbxStudentPaperSearch";
            this.grpbxStudentPaperSearch.Size = new System.Drawing.Size(262, 407);
            this.grpbxStudentPaperSearch.TabIndex = 23;
            this.grpbxStudentPaperSearch.TabStop = false;
            this.grpbxStudentPaperSearch.Text = "Search for a Student or Paper";
            // 
            // lblDetailsStudent
            // 
            this.lblDetailsStudent.AutoSize = true;
            this.lblDetailsStudent.Location = new System.Drawing.Point(7, 174);
            this.lblDetailsStudent.Name = "lblDetailsStudent";
            this.lblDetailsStudent.Size = new System.Drawing.Size(42, 13);
            this.lblDetailsStudent.TabIndex = 16;
            this.lblDetailsStudent.Text = "Details:";
            // 
            // rchtxtbxStudentDetails
            // 
            this.rchtxtbxStudentDetails.Enabled = false;
            this.rchtxtbxStudentDetails.Location = new System.Drawing.Point(6, 190);
            this.rchtxtbxStudentDetails.Name = "rchtxtbxStudentDetails";
            this.rchtxtbxStudentDetails.Size = new System.Drawing.Size(246, 203);
            this.rchtxtbxStudentDetails.TabIndex = 15;
            this.rchtxtbxStudentDetails.Text = "";
            // 
            // txtbxSearchString
            // 
            this.txtbxSearchString.Location = new System.Drawing.Point(13, 54);
            this.txtbxSearchString.Name = "txtbxSearchString";
            this.txtbxSearchString.Size = new System.Drawing.Size(243, 20);
            this.txtbxSearchString.TabIndex = 7;
            // 
            // lblSearchStringStudent
            // 
            this.lblSearchStringStudent.AutoSize = true;
            this.lblSearchStringStudent.Location = new System.Drawing.Point(6, 38);
            this.lblSearchStringStudent.Name = "lblSearchStringStudent";
            this.lblSearchStringStudent.Size = new System.Drawing.Size(72, 13);
            this.lblSearchStringStudent.TabIndex = 2;
            this.lblSearchStringStudent.Text = "Enter Search:";
            // 
            // btnStudentSearch
            // 
            this.btnStudentSearch.Location = new System.Drawing.Point(10, 97);
            this.btnStudentSearch.Name = "btnStudentSearch";
            this.btnStudentSearch.Size = new System.Drawing.Size(246, 58);
            this.btnStudentSearch.TabIndex = 0;
            this.btnStudentSearch.Text = "Search";
            this.btnStudentSearch.UseVisualStyleBackColor = true;
            // 
            // Export
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(286, 515);
            this.Controls.Add(this.btnExport);
            this.Controls.Add(this.grpbxStudentPaperSearch);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Export";
            this.Text = "Export";
            this.grpbxStudentPaperSearch.ResumeLayout(false);
            this.grpbxStudentPaperSearch.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnExport;
        private System.Windows.Forms.GroupBox grpbxStudentPaperSearch;
        private System.Windows.Forms.Label lblDetailsStudent;
        private System.Windows.Forms.RichTextBox rchtxtbxStudentDetails;
        private System.Windows.Forms.TextBox txtbxSearchString;
        private System.Windows.Forms.Label lblSearchStringStudent;
        private System.Windows.Forms.Button btnStudentSearch;
    }
}