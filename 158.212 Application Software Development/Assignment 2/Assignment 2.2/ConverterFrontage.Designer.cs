namespace Assignment_2._2
{
    partial class currencyconverter
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
            this.txtboxResult = new System.Windows.Forms.TextBox();
            this.txtboxAmount = new System.Windows.Forms.TextBox();
            this.btnCovert = new System.Windows.Forms.Button();
            this.lblAmount = new System.Windows.Forms.Label();
            this.btnReset = new System.Windows.Forms.Button();
            this.convertFrom = new System.Windows.Forms.ComboBox();
            this.convertTo = new System.Windows.Forms.ComboBox();
            this.lblResult = new System.Windows.Forms.Label();
            this.lblFrom = new System.Windows.Forms.Label();
            this.lblTo = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // txtboxResult
            // 
            this.txtboxResult.AllowDrop = true;
            this.txtboxResult.BackColor = System.Drawing.Color.Gainsboro;
            this.txtboxResult.Location = new System.Drawing.Point(45, 312);
            this.txtboxResult.Name = "txtboxResult";
            this.txtboxResult.Size = new System.Drawing.Size(215, 20);
            this.txtboxResult.TabIndex = 29;
            // 
            // txtboxAmount
            // 
            this.txtboxAmount.AcceptsReturn = true;
            this.txtboxAmount.BackColor = System.Drawing.Color.Gainsboro;
            this.txtboxAmount.Location = new System.Drawing.Point(45, 43);
            this.txtboxAmount.Name = "txtboxAmount";
            this.txtboxAmount.Size = new System.Drawing.Size(215, 20);
            this.txtboxAmount.TabIndex = 28;
            // 
            // btnCovert
            // 
            this.btnCovert.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnCovert.Location = new System.Drawing.Point(45, 222);
            this.btnCovert.Name = "btnCovert";
            this.btnCovert.Size = new System.Drawing.Size(215, 43);
            this.btnCovert.TabIndex = 27;
            this.btnCovert.Text = "Convert";
            this.btnCovert.UseVisualStyleBackColor = true;
            this.btnCovert.Click += new System.EventHandler(this.convertbutton_Click);
            // 
            // lblAmount
            // 
            this.lblAmount.AutoSize = true;
            this.lblAmount.BackColor = System.Drawing.Color.Transparent;
            this.lblAmount.Location = new System.Drawing.Point(50, 27);
            this.lblAmount.Name = "lblAmount";
            this.lblAmount.Size = new System.Drawing.Size(76, 13);
            this.lblAmount.TabIndex = 25;
            this.lblAmount.Text = "Input Amount: ";
            // 
            // btnReset
            // 
            this.btnReset.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnReset.Location = new System.Drawing.Point(45, 394);
            this.btnReset.Name = "btnReset";
            this.btnReset.Size = new System.Drawing.Size(215, 43);
            this.btnReset.TabIndex = 32;
            this.btnReset.Text = "Reset";
            this.btnReset.UseVisualStyleBackColor = true;
            this.btnReset.Click += new System.EventHandler(this.resetbutton_Click);
            // 
            // convertFrom
            // 
            this.convertFrom.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.convertFrom.FormattingEnabled = true;
            this.convertFrom.Items.AddRange(new object[] {
            "USD",
            "EUR",
            "NZD",
            "CAD",
            "GBP",
            "AUD"});
            this.convertFrom.Location = new System.Drawing.Point(45, 109);
            this.convertFrom.Margin = new System.Windows.Forms.Padding(2);
            this.convertFrom.Name = "convertFrom";
            this.convertFrom.Size = new System.Drawing.Size(215, 21);
            this.convertFrom.TabIndex = 33;
            // 
            // convertTo
            // 
            this.convertTo.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.convertTo.FormattingEnabled = true;
            this.convertTo.Items.AddRange(new object[] {
            "USD",
            "EUR",
            "NZD",
            "CAD",
            "GBP",
            "AUD"});
            this.convertTo.Location = new System.Drawing.Point(45, 164);
            this.convertTo.Margin = new System.Windows.Forms.Padding(2);
            this.convertTo.Name = "convertTo";
            this.convertTo.Size = new System.Drawing.Size(215, 21);
            this.convertTo.TabIndex = 34;
            // 
            // lblResult
            // 
            this.lblResult.AllowDrop = true;
            this.lblResult.AutoSize = true;
            this.lblResult.Location = new System.Drawing.Point(45, 293);
            this.lblResult.Name = "lblResult";
            this.lblResult.Size = new System.Drawing.Size(95, 13);
            this.lblResult.TabIndex = 35;
            this.lblResult.Text = "Converted Result: ";
            // 
            // lblFrom
            // 
            this.lblFrom.AutoSize = true;
            this.lblFrom.Location = new System.Drawing.Point(50, 94);
            this.lblFrom.Name = "lblFrom";
            this.lblFrom.Size = new System.Drawing.Size(126, 13);
            this.lblFrom.TabIndex = 36;
            this.lblFrom.Text = "Currency to convert from:";
            // 
            // lblTo
            // 
            this.lblTo.AutoSize = true;
            this.lblTo.Location = new System.Drawing.Point(50, 149);
            this.lblTo.Name = "lblTo";
            this.lblTo.Size = new System.Drawing.Size(115, 13);
            this.lblTo.TabIndex = 37;
            this.lblTo.Text = "Currency to convert to:";
            // 
            // currencyconverter
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(299, 505);
            this.Controls.Add(this.lblTo);
            this.Controls.Add(this.lblFrom);
            this.Controls.Add(this.lblResult);
            this.Controls.Add(this.convertTo);
            this.Controls.Add(this.convertFrom);
            this.Controls.Add(this.btnReset);
            this.Controls.Add(this.txtboxResult);
            this.Controls.Add(this.txtboxAmount);
            this.Controls.Add(this.btnCovert);
            this.Controls.Add(this.lblAmount);
            this.Name = "currencyconverter";
            this.Text = "Currency Converter 9000";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtboxResult;
        private System.Windows.Forms.TextBox txtboxAmount;
        private System.Windows.Forms.Button btnCovert;
        private System.Windows.Forms.Label lblAmount;
        private System.Windows.Forms.Button btnReset;
        private System.Windows.Forms.ComboBox convertFrom;
        private System.Windows.Forms.ComboBox convertTo;
        private System.Windows.Forms.Label lblResult;
        private System.Windows.Forms.Label lblFrom;
        private System.Windows.Forms.Label lblTo;
    }
}

