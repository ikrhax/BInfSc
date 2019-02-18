namespace Assignment4Final
{
    partial class TextSearcher
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(TextSearcher));
            this.mnuStrpTextSearcher = new System.Windows.Forms.MenuStrip();
            this.mnuFile = new System.Windows.Forms.ToolStripMenuItem();
            this.menuFileOpen = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuFileExit = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuMetrics = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuMetricsDisplayRequired = new System.Windows.Forms.ToolStripMenuItem();
            this.grpBoxFilePrep = new System.Windows.Forms.GroupBox();
            this.btnExit = new System.Windows.Forms.Button();
            this.lstbxMetrics = new System.Windows.Forms.ListBox();
            this.btnOpenFile = new System.Windows.Forms.Button();
            this.btnDisplayMetrics = new System.Windows.Forms.Button();
            this.lblInstructionText = new System.Windows.Forms.Label();
            this.grpBoxSearch = new System.Windows.Forms.GroupBox();
            this.lblSearchEntry = new System.Windows.Forms.Label();
            this.lstboxSearchResults = new System.Windows.Forms.ListBox();
            this.btnSearchGo = new System.Windows.Forms.Button();
            this.txtBxSearch = new System.Windows.Forms.TextBox();
            this.grpBoxSearchMode = new System.Windows.Forms.GroupBox();
            this.rdbtnSearchByInt = new System.Windows.Forms.RadioButton();
            this.rdbtnSearchString = new System.Windows.Forms.RadioButton();
            this.mnuStrpTextSearcher.SuspendLayout();
            this.grpBoxFilePrep.SuspendLayout();
            this.grpBoxSearch.SuspendLayout();
            this.grpBoxSearchMode.SuspendLayout();
            this.SuspendLayout();
            // 
            // mnuStrpTextSearcher
            // 
            this.mnuStrpTextSearcher.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnuFile,
            this.mnuMetrics});
            this.mnuStrpTextSearcher.Location = new System.Drawing.Point(0, 0);
            this.mnuStrpTextSearcher.Name = "mnuStrpTextSearcher";
            this.mnuStrpTextSearcher.Size = new System.Drawing.Size(1103, 24);
            this.mnuStrpTextSearcher.TabIndex = 15;
            this.mnuStrpTextSearcher.Text = "menuStrip1";
            // 
            // mnuFile
            // 
            this.mnuFile.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuFileOpen,
            this.mnuFileExit});
            this.mnuFile.Name = "mnuFile";
            this.mnuFile.Size = new System.Drawing.Size(37, 20);
            this.mnuFile.Text = "File";
            // 
            // menuFileOpen
            // 
            this.menuFileOpen.Name = "menuFileOpen";
            this.menuFileOpen.Size = new System.Drawing.Size(152, 22);
            this.menuFileOpen.Text = "Open";
            this.menuFileOpen.Click += new System.EventHandler(this.MenuFileOpenClick);
            // 
            // mnuFileExit
            // 
            this.mnuFileExit.Name = "mnuFileExit";
            this.mnuFileExit.Size = new System.Drawing.Size(152, 22);
            this.mnuFileExit.Text = "Exit";
            this.mnuFileExit.Click += new System.EventHandler(this.MnuFileExitClick);
            // 
            // mnuMetrics
            // 
            this.mnuMetrics.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnuMetricsDisplayRequired});
            this.mnuMetrics.Enabled = false;
            this.mnuMetrics.Name = "mnuMetrics";
            this.mnuMetrics.Size = new System.Drawing.Size(58, 20);
            this.mnuMetrics.Text = "Metrics";
            // 
            // mnuMetricsDisplayRequired
            // 
            this.mnuMetricsDisplayRequired.Name = "mnuMetricsDisplayRequired";
            this.mnuMetricsDisplayRequired.Size = new System.Drawing.Size(162, 22);
            this.mnuMetricsDisplayRequired.Text = "Display Required";
            this.mnuMetricsDisplayRequired.Click += new System.EventHandler(this.MnuMetricsDisplayRequiredClick);
            // 
            // grpBoxFilePrep
            // 
            this.grpBoxFilePrep.Controls.Add(this.btnExit);
            this.grpBoxFilePrep.Controls.Add(this.lstbxMetrics);
            this.grpBoxFilePrep.Controls.Add(this.btnOpenFile);
            this.grpBoxFilePrep.Controls.Add(this.btnDisplayMetrics);
            this.grpBoxFilePrep.Location = new System.Drawing.Point(12, 43);
            this.grpBoxFilePrep.Name = "grpBoxFilePrep";
            this.grpBoxFilePrep.Size = new System.Drawing.Size(538, 524);
            this.grpBoxFilePrep.TabIndex = 17;
            this.grpBoxFilePrep.TabStop = false;
            this.grpBoxFilePrep.Text = "Management Area";
            // 
            // btnExit
            // 
            this.btnExit.Location = new System.Drawing.Point(423, 29);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(100, 125);
            this.btnExit.TabIndex = 6;
            this.btnExit.Text = "Exit";
            this.btnExit.UseCompatibleTextRendering = true;
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.BtnExitClick);
            // 
            // lstbxMetrics
            // 
            this.lstbxMetrics.Enabled = false;
            this.lstbxMetrics.FormattingEnabled = true;
            this.lstbxMetrics.Location = new System.Drawing.Point(14, 165);
            this.lstbxMetrics.Name = "lstbxMetrics";
            this.lstbxMetrics.Size = new System.Drawing.Size(509, 342);
            this.lstbxMetrics.TabIndex = 5;
            // 
            // btnOpenFile
            // 
            this.btnOpenFile.Location = new System.Drawing.Point(14, 29);
            this.btnOpenFile.Name = "btnOpenFile";
            this.btnOpenFile.Size = new System.Drawing.Size(101, 124);
            this.btnOpenFile.TabIndex = 3;
            this.btnOpenFile.Text = "Open File";
            this.btnOpenFile.UseVisualStyleBackColor = true;
            this.btnOpenFile.Click += new System.EventHandler(this.BtnOpenFileClick);
            // 
            // btnDisplayMetrics
            // 
            this.btnDisplayMetrics.Enabled = false;
            this.btnDisplayMetrics.Location = new System.Drawing.Point(121, 29);
            this.btnDisplayMetrics.Name = "btnDisplayMetrics";
            this.btnDisplayMetrics.Size = new System.Drawing.Size(296, 125);
            this.btnDisplayMetrics.TabIndex = 4;
            this.btnDisplayMetrics.Text = "Display Metrics";
            this.btnDisplayMetrics.UseVisualStyleBackColor = true;
            this.btnDisplayMetrics.Click += new System.EventHandler(this.BtnDisplayMetricsClick);
            // 
            // lblInstructionText
            // 
            this.lblInstructionText.AutoSize = true;
            this.lblInstructionText.Location = new System.Drawing.Point(369, 22);
            this.lblInstructionText.Name = "lblInstructionText";
            this.lblInstructionText.Size = new System.Drawing.Size(329, 13);
            this.lblInstructionText.TabIndex = 16;
            this.lblInstructionText.Text = "Hello! Welcome to my Text Searcher. Please open a file to continue.";
            // 
            // grpBoxSearch
            // 
            this.grpBoxSearch.Controls.Add(this.lblSearchEntry);
            this.grpBoxSearch.Controls.Add(this.lstboxSearchResults);
            this.grpBoxSearch.Controls.Add(this.btnSearchGo);
            this.grpBoxSearch.Controls.Add(this.txtBxSearch);
            this.grpBoxSearch.Controls.Add(this.grpBoxSearchMode);
            this.grpBoxSearch.Location = new System.Drawing.Point(556, 43);
            this.grpBoxSearch.Name = "grpBoxSearch";
            this.grpBoxSearch.Size = new System.Drawing.Size(536, 524);
            this.grpBoxSearch.TabIndex = 18;
            this.grpBoxSearch.TabStop = false;
            this.grpBoxSearch.Text = "Search Area";
            // 
            // lblSearchEntry
            // 
            this.lblSearchEntry.AutoSize = true;
            this.lblSearchEntry.Enabled = false;
            this.lblSearchEntry.Location = new System.Drawing.Point(15, 116);
            this.lblSearchEntry.Name = "lblSearchEntry";
            this.lblSearchEntry.Size = new System.Drawing.Size(155, 13);
            this.lblSearchEntry.TabIndex = 4;
            this.lblSearchEntry.Text = "Please enter data to search for:";
            // 
            // lstboxSearchResults
            // 
            this.lstboxSearchResults.Enabled = false;
            this.lstboxSearchResults.FormattingEnabled = true;
            this.lstboxSearchResults.Location = new System.Drawing.Point(12, 165);
            this.lstboxSearchResults.Name = "lstboxSearchResults";
            this.lstboxSearchResults.Size = new System.Drawing.Size(506, 342);
            this.lstboxSearchResults.TabIndex = 3;
            // 
            // btnSearchGo
            // 
            this.btnSearchGo.Enabled = false;
            this.btnSearchGo.Location = new System.Drawing.Point(354, 129);
            this.btnSearchGo.Name = "btnSearchGo";
            this.btnSearchGo.Size = new System.Drawing.Size(164, 25);
            this.btnSearchGo.TabIndex = 2;
            this.btnSearchGo.Text = "Search";
            this.btnSearchGo.UseVisualStyleBackColor = true;
            this.btnSearchGo.Click += new System.EventHandler(this.BtnSearchGoClick);
            // 
            // txtBxSearch
            // 
            this.txtBxSearch.Enabled = false;
            this.txtBxSearch.Location = new System.Drawing.Point(12, 132);
            this.txtBxSearch.Name = "txtBxSearch";
            this.txtBxSearch.Size = new System.Drawing.Size(336, 20);
            this.txtBxSearch.TabIndex = 1;
            // 
            // grpBoxSearchMode
            // 
            this.grpBoxSearchMode.Controls.Add(this.rdbtnSearchByInt);
            this.grpBoxSearchMode.Controls.Add(this.rdbtnSearchString);
            this.grpBoxSearchMode.Enabled = false;
            this.grpBoxSearchMode.Location = new System.Drawing.Point(12, 29);
            this.grpBoxSearchMode.Name = "grpBoxSearchMode";
            this.grpBoxSearchMode.Size = new System.Drawing.Size(506, 70);
            this.grpBoxSearchMode.TabIndex = 0;
            this.grpBoxSearchMode.TabStop = false;
            this.grpBoxSearchMode.Text = "Please select your search mode:";
            // 
            // rdbtnSearchByInt
            // 
            this.rdbtnSearchByInt.AutoSize = true;
            this.rdbtnSearchByInt.Enabled = false;
            this.rdbtnSearchByInt.Location = new System.Drawing.Point(6, 42);
            this.rdbtnSearchByInt.Name = "rdbtnSearchByInt";
            this.rdbtnSearchByInt.Size = new System.Drawing.Size(213, 17);
            this.rdbtnSearchByInt.TabIndex = 1;
            this.rdbtnSearchByInt.Text = "Search for a Word by Number of Letters";
            this.rdbtnSearchByInt.UseVisualStyleBackColor = true;
            this.rdbtnSearchByInt.CheckedChanged += new System.EventHandler(this.RdbtnSearchByIntCheckedChanged);
            // 
            // rdbtnSearchString
            // 
            this.rdbtnSearchString.AutoSize = true;
            this.rdbtnSearchString.Checked = true;
            this.rdbtnSearchString.Enabled = false;
            this.rdbtnSearchString.Location = new System.Drawing.Point(6, 19);
            this.rdbtnSearchString.Name = "rdbtnSearchString";
            this.rdbtnSearchString.Size = new System.Drawing.Size(150, 17);
            this.rdbtnSearchString.TabIndex = 0;
            this.rdbtnSearchString.TabStop = true;
            this.rdbtnSearchString.Text = "Search for a Word by Text";
            this.rdbtnSearchString.UseVisualStyleBackColor = true;
            this.rdbtnSearchString.CheckedChanged += new System.EventHandler(this.RdbtnSearchStringCheckedChanged);
            // 
            // TextSearcher
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1103, 579);
            this.Controls.Add(this.mnuStrpTextSearcher);
            this.Controls.Add(this.grpBoxFilePrep);
            this.Controls.Add(this.lblInstructionText);
            this.Controls.Add(this.grpBoxSearch);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "TextSearcher";
            this.Text = "Text Searcher 9000";
            this.mnuStrpTextSearcher.ResumeLayout(false);
            this.mnuStrpTextSearcher.PerformLayout();
            this.grpBoxFilePrep.ResumeLayout(false);
            this.grpBoxSearch.ResumeLayout(false);
            this.grpBoxSearch.PerformLayout();
            this.grpBoxSearchMode.ResumeLayout(false);
            this.grpBoxSearchMode.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip mnuStrpTextSearcher;
        private System.Windows.Forms.ToolStripMenuItem mnuFile;
        private System.Windows.Forms.ToolStripMenuItem menuFileOpen;
        private System.Windows.Forms.ToolStripMenuItem mnuFileExit;
        private System.Windows.Forms.ToolStripMenuItem mnuMetrics;
        private System.Windows.Forms.ToolStripMenuItem mnuMetricsDisplayRequired;
        private System.Windows.Forms.GroupBox grpBoxFilePrep;
        private System.Windows.Forms.Button btnExit;
        private System.Windows.Forms.ListBox lstbxMetrics;
        private System.Windows.Forms.Button btnOpenFile;
        private System.Windows.Forms.Button btnDisplayMetrics;
        private System.Windows.Forms.Label lblInstructionText;
        private System.Windows.Forms.GroupBox grpBoxSearch;
        private System.Windows.Forms.Label lblSearchEntry;
        private System.Windows.Forms.ListBox lstboxSearchResults;
        private System.Windows.Forms.Button btnSearchGo;
        private System.Windows.Forms.TextBox txtBxSearch;
        private System.Windows.Forms.GroupBox grpBoxSearchMode;
        private System.Windows.Forms.RadioButton rdbtnSearchByInt;
        private System.Windows.Forms.RadioButton rdbtnSearchString;
    }
}

