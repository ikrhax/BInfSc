namespace Assignment5v3
{
    partial class CreateStudent
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CreateStudent));
            this.grpbxCreateaStudent = new System.Windows.Forms.GroupBox();
            this.lblStudentAddress = new System.Windows.Forms.Label();
            this.txtbxrchStudentAddress = new System.Windows.Forms.RichTextBox();
            this.msktxtbxStudentDOB = new System.Windows.Forms.MaskedTextBox();
            this.txtbxStudentName = new System.Windows.Forms.TextBox();
            this.lblStudentDOB = new System.Windows.Forms.Label();
            this.lblStudentName = new System.Windows.Forms.Label();
            this.btnCreateStudent = new System.Windows.Forms.Button();
            this.grpbxCreateaStudent.SuspendLayout();
            this.SuspendLayout();
            // 
            // grpbxCreateaStudent
            // 
            this.grpbxCreateaStudent.Controls.Add(this.lblStudentAddress);
            this.grpbxCreateaStudent.Controls.Add(this.txtbxrchStudentAddress);
            this.grpbxCreateaStudent.Controls.Add(this.msktxtbxStudentDOB);
            this.grpbxCreateaStudent.Controls.Add(this.txtbxStudentName);
            this.grpbxCreateaStudent.Controls.Add(this.lblStudentDOB);
            this.grpbxCreateaStudent.Controls.Add(this.lblStudentName);
            this.grpbxCreateaStudent.Controls.Add(this.btnCreateStudent);
            this.grpbxCreateaStudent.Location = new System.Drawing.Point(12, 12);
            this.grpbxCreateaStudent.Name = "grpbxCreateaStudent";
            this.grpbxCreateaStudent.Size = new System.Drawing.Size(250, 484);
            this.grpbxCreateaStudent.TabIndex = 1;
            this.grpbxCreateaStudent.TabStop = false;
            this.grpbxCreateaStudent.Text = "Create a Student";
            // 
            // lblStudentAddress
            // 
            this.lblStudentAddress.AutoSize = true;
            this.lblStudentAddress.Location = new System.Drawing.Point(7, 179);
            this.lblStudentAddress.Name = "lblStudentAddress";
            this.lblStudentAddress.Size = new System.Drawing.Size(88, 13);
            this.lblStudentAddress.TabIndex = 16;
            this.lblStudentAddress.Text = "Student Address:";
            // 
            // txtbxrchStudentAddress
            // 
            this.txtbxrchStudentAddress.Location = new System.Drawing.Point(6, 195);
            this.txtbxrchStudentAddress.Name = "txtbxrchStudentAddress";
            this.txtbxrchStudentAddress.Size = new System.Drawing.Size(234, 202);
            this.txtbxrchStudentAddress.TabIndex = 15;
            this.txtbxrchStudentAddress.Text = "";
            // 
            // msktxtbxStudentDOB
            // 
            this.msktxtbxStudentDOB.Location = new System.Drawing.Point(10, 117);
            this.msktxtbxStudentDOB.Mask = "00/00/0000";
            this.msktxtbxStudentDOB.Name = "msktxtbxStudentDOB";
            this.msktxtbxStudentDOB.Size = new System.Drawing.Size(230, 20);
            this.msktxtbxStudentDOB.TabIndex = 14;
            this.msktxtbxStudentDOB.ValidatingType = typeof(System.DateTime);
            // 
            // txtbxStudentName
            // 
            this.txtbxStudentName.Location = new System.Drawing.Point(10, 66);
            this.txtbxStudentName.Name = "txtbxStudentName";
            this.txtbxStudentName.Size = new System.Drawing.Size(230, 20);
            this.txtbxStudentName.TabIndex = 7;
            // 
            // lblStudentDOB
            // 
            this.lblStudentDOB.AutoSize = true;
            this.lblStudentDOB.Location = new System.Drawing.Point(7, 101);
            this.lblStudentDOB.Name = "lblStudentDOB";
            this.lblStudentDOB.Size = new System.Drawing.Size(69, 13);
            this.lblStudentDOB.TabIndex = 4;
            this.lblStudentDOB.Text = "Date of Birth:";
            // 
            // lblStudentName
            // 
            this.lblStudentName.AutoSize = true;
            this.lblStudentName.Location = new System.Drawing.Point(7, 41);
            this.lblStudentName.Name = "lblStudentName";
            this.lblStudentName.Size = new System.Drawing.Size(38, 13);
            this.lblStudentName.TabIndex = 2;
            this.lblStudentName.Text = "Name:";
            // 
            // btnCreateStudent
            // 
            this.btnCreateStudent.Location = new System.Drawing.Point(6, 413);
            this.btnCreateStudent.Name = "btnCreateStudent";
            this.btnCreateStudent.Size = new System.Drawing.Size(234, 58);
            this.btnCreateStudent.TabIndex = 0;
            this.btnCreateStudent.Text = "Create a Student";
            this.btnCreateStudent.UseVisualStyleBackColor = true;
            this.btnCreateStudent.Click += new System.EventHandler(this.btnCreateStudent_Click);
            // 
            // CreateStudent
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(274, 507);
            this.Controls.Add(this.grpbxCreateaStudent);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "CreateStudent";
            this.Text = "Create a Student";
            this.grpbxCreateaStudent.ResumeLayout(false);
            this.grpbxCreateaStudent.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox grpbxCreateaStudent;
        private System.Windows.Forms.Label lblStudentAddress;
        private System.Windows.Forms.RichTextBox txtbxrchStudentAddress;
        private System.Windows.Forms.MaskedTextBox msktxtbxStudentDOB;
        private System.Windows.Forms.TextBox txtbxStudentName;
        private System.Windows.Forms.Label lblStudentDOB;
        private System.Windows.Forms.Label lblStudentName;
        private System.Windows.Forms.Button btnCreateStudent;
    }
}