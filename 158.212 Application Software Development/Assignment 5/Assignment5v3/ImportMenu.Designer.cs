namespace Assignment5v3
{
    partial class ImportMenu
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ImportMenu));
            this.btnExport = new System.Windows.Forms.Button();
            this.grpbxImportASomething = new System.Windows.Forms.GroupBox();
            this.btnTextExampleShow = new System.Windows.Forms.Button();
            this.lblImportInstructions = new System.Windows.Forms.Label();
            this.lblDetailsStudent = new System.Windows.Forms.Label();
            this.rchtxtbxStudentDetails = new System.Windows.Forms.RichTextBox();
            this.btnOpenFile = new System.Windows.Forms.Button();
            this.grpbxImportASomething.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnExport
            // 
            this.btnExport.Enabled = false;
            this.btnExport.Location = new System.Drawing.Point(12, 436);
            this.btnExport.Name = "btnExport";
            this.btnExport.Size = new System.Drawing.Size(262, 58);
            this.btnExport.TabIndex = 26;
            this.btnExport.Text = "Export this Student in This Paper";
            this.btnExport.UseVisualStyleBackColor = true;
            // 
            // grpbxImportASomething
            // 
            this.grpbxImportASomething.Controls.Add(this.btnTextExampleShow);
            this.grpbxImportASomething.Controls.Add(this.lblImportInstructions);
            this.grpbxImportASomething.Controls.Add(this.lblDetailsStudent);
            this.grpbxImportASomething.Controls.Add(this.rchtxtbxStudentDetails);
            this.grpbxImportASomething.Controls.Add(this.btnOpenFile);
            this.grpbxImportASomething.Location = new System.Drawing.Point(12, 12);
            this.grpbxImportASomething.Name = "grpbxImportASomething";
            this.grpbxImportASomething.Size = new System.Drawing.Size(262, 407);
            this.grpbxImportASomething.TabIndex = 25;
            this.grpbxImportASomething.TabStop = false;
            this.grpbxImportASomething.Text = "Import From File";
            // 
            // btnTextExampleShow
            // 
            this.btnTextExampleShow.Location = new System.Drawing.Point(6, 58);
            this.btnTextExampleShow.Name = "btnTextExampleShow";
            this.btnTextExampleShow.Size = new System.Drawing.Size(246, 34);
            this.btnTextExampleShow.TabIndex = 18;
            this.btnTextExampleShow.Text = "See an Example of Format";
            this.btnTextExampleShow.UseVisualStyleBackColor = true;
            // 
            // lblImportInstructions
            // 
            this.lblImportInstructions.AutoSize = true;
            this.lblImportInstructions.Location = new System.Drawing.Point(51, 42);
            this.lblImportInstructions.Name = "lblImportInstructions";
            this.lblImportInstructions.Size = new System.Drawing.Size(148, 13);
            this.lblImportInstructions.TabIndex = 17;
            this.lblImportInstructions.Text = "This is a TEXT FILE imported.";
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
            // btnOpenFile
            // 
            this.btnOpenFile.Location = new System.Drawing.Point(6, 117);
            this.btnOpenFile.Name = "btnOpenFile";
            this.btnOpenFile.Size = new System.Drawing.Size(246, 34);
            this.btnOpenFile.TabIndex = 0;
            this.btnOpenFile.Text = "Open a File";
            this.btnOpenFile.UseVisualStyleBackColor = true;
            // 
            // ImportMenu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(287, 512);
            this.Controls.Add(this.btnExport);
            this.Controls.Add(this.grpbxImportASomething);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "ImportMenu";
            this.Text = "Import ";
            this.grpbxImportASomething.ResumeLayout(false);
            this.grpbxImportASomething.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnExport;
        private System.Windows.Forms.GroupBox grpbxImportASomething;
        private System.Windows.Forms.Button btnTextExampleShow;
        private System.Windows.Forms.Label lblImportInstructions;
        private System.Windows.Forms.Label lblDetailsStudent;
        private System.Windows.Forms.RichTextBox rchtxtbxStudentDetails;
        private System.Windows.Forms.Button btnOpenFile;
    }
}