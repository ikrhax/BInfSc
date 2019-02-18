using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Globalization;

namespace Assignment4Final
{
    public partial class TextSearcher : Form
    {
        public TextSearcher()
        {
            InitializeComponent();
        }

        //Simon Parr - Assignment 4 - 158.212 - Student ID 09233113

        //INSTANTIATE MY SINGLE CLASS

        TextHelper documentsearch = new TextHelper();


        //OPEN FILE CONTROLS:
        private void MenuFileOpenClick(object sender, EventArgs e)
        {
            string filename = GoOpenFile();
            string[] SuperString = GoPrepareFile(filename);
            EnabelGui();
            documentsearch.PopulateDictionary(SuperString);
            documentsearch.PopulateArray(SuperString);
            documentsearch.PopulateLengths();
        }
        private void BtnOpenFileClick(object sender, EventArgs e)
        {
            string filename = GoOpenFile();
            string[] SuperString = GoPrepareFile(filename);
            EnabelGui();
            documentsearch.PopulateDictionary(SuperString);
            documentsearch.PopulateArray(SuperString);
            documentsearch.PopulateLengths();
        }


        //EXIT APPLICATION:
        private void BtnExitClick(object sender, EventArgs e)
        {
            Application.Exit();
        }
        private void MnuFileExitClick(object sender, EventArgs e)
        {
            Application.Exit();
        }


        //DISPLAY METRICS
        private void BtnDisplayMetricsClick(object sender, EventArgs e)
        {
            string[] maximum = documentsearch.MaximumLength();
            string[] average = documentsearch.AverageLength();
            string[] minimum = documentsearch.MinimumLength();
            string[] mostcommon = documentsearch.MostCommon();
            lstbxMetrics.Items.Add("Required Metrics are as follows: ");
            lstbxMetrics.Items.Add("\n");
            lstbxMetrics.Items.Add("The most common Word or Words with " + documentsearch.common + " appearances are: ");
            publishmetrics(mostcommon);
            lstbxMetrics.Items.Add("\n");
            lstbxMetrics.Items.Add("The largest number of letters was " + documentsearch.max + " found in: \n");
            publishmetrics(maximum);
            lstbxMetrics.Items.Add("\n");
            lstbxMetrics.Items.Add("The average letter count was " + documentsearch.average + " found in: \n");
            publishmetrics(average);
            lstbxMetrics.Items.Add("\n");
            lstbxMetrics.Items.Add("The smallest number of letters was " + documentsearch.min + " found in: \n");
            publishmetrics(minimum);
        }
        private void MnuMetricsDisplayRequiredClick(object sender, EventArgs e)
        {
            string[] maximum = documentsearch.MaximumLength();
            string[] average = documentsearch.AverageLength();
            string[] minimum = documentsearch.MinimumLength();
            string[] mostcommon = documentsearch.MostCommon();
            lstbxMetrics.Items.Add("Required Metrics are as follows: ");
            lstbxMetrics.Items.Add("\n");
            lstbxMetrics.Items.Add("The most common Word or Words with " + documentsearch.common + " appearances are: ");
            publishmetrics(mostcommon);
            lstbxMetrics.Items.Add("\n");
            lstbxMetrics.Items.Add("The largest number of letters was " + documentsearch.max + " found in: \n");
            publishmetrics(maximum);
            lstbxMetrics.Items.Add("\n");
            lstbxMetrics.Items.Add("The average letter count was " + documentsearch.average + " found in: \n");
            publishmetrics(average);
            lstbxMetrics.Items.Add("\n");
            lstbxMetrics.Items.Add("The smallest number of letters was " + documentsearch.min + " found in: \n");
            publishmetrics(minimum);
        }


        //SEARCH BOX LABEL TEXT CONTROL:
        private void RdbtnSearchStringCheckedChanged(object sender, EventArgs e)
        {
            lblSearchEntry.Text = "Searching by Word - Enter Text";
        }
        private void RdbtnSearchByIntCheckedChanged(object sender, EventArgs e)
        {
            lblSearchEntry.Text = "Searching by Length of Word - Enter a number:";
        }


        // SEARCH SEQUENCE:
        private void BtnSearchGoClick(object sender, EventArgs e)
        {
            TextInfo textchanger = new CultureInfo("en-US", false).TextInfo;
            bool isnumber = SearchInputCheck();

            if ((rdbtnSearchString.Checked) && (!isnumber))
            {
                string input = txtBxSearch.Text;
                input = textchanger.ToTitleCase(input);
                int output = documentsearch.SearchByWord(input);
                lstboxSearchResults.Items.Add("The appearance count for " + input + " is " + output);
            }
            else if ((rdbtnSearchByInt.Checked) && (isnumber))
            {
                int input = Convert.ToInt32(txtBxSearch.Text);
                string[] output = documentsearch.SearchByLength(input);
                lstboxSearchResults.Items.Add("The words with a length of " + input + " are: \n");
                publishsearch(output);
            }
            else
            {
                Error("Please check Search Settings and Input.", "Conflicting Settings");
            }

        }
        


        // FUNCTIONS AND SUBROUTINES


        //GENERIC ERROR FUNCTION:
        //BECUASE THEY ARE SUPER HANDY AND ACTUALLY CHANGE THE WAY YOU WRITE TRY CATCH

        public void Error(string error, string thinking)
        {
            MessageBox.Show(error, thinking, MessageBoxButtons.OK, MessageBoxIcon.Error);
        }



        //OPEN FILE FUNCTION: 
        //GET THE FILE PATH THROUGH A DIALOGUE OPTION
        public string GoOpenFile()
        {
            OpenFileDialog openfile = new OpenFileDialog();
            openfile.Filter = "Text Files (*.txt)|*.txt";
            openfile.Multiselect = false;
            DialogResult temporary = openfile.ShowDialog();
            string filename = "";
            if (temporary == DialogResult.OK)
            {
                filename = openfile.FileName;
                openfile.OpenFile();
                lblInstructionText.Text = ("I have opened " + filename);
            }
            else if (temporary == DialogResult.Cancel)
            {
                Error("I can't do much if you don't open a file", "File Open Failed");
                Application.Exit();
            }
            return filename;
        }



        // PREPARE FILE FUNCTION:
        // A FUNCTION THAT TAKE ALL THE TEXT IN THE FILE, JAMS IT INTO A SINGLE STRING, THE CREATES AN ARRAY OF THE STRINGS. 
        public string[] GoPrepareFile(string filename)
        {
            string input = null;
            string[] output = null;
            TextInfo textchanger = new CultureInfo("en-US", false).TextInfo;
            try
            {
                using (StreamReader reader = new StreamReader(filename))
                {
                    input = File.ReadAllText(filename);
                    input = textchanger.ToTitleCase(input);
                    textchanger.ToTitleCase(input);
                    output = input.Split(' ', '.', '!', ',', '"', '?', ';', ':', '(', ')', '{', '}', '\r', '\n', '\0');
                    return output;
                }
            }
            catch
            {
                Error("There was an error preparing the file", "File Preparation Failed");
                return output;
            }
        }


        // VALIDATION CHECK FOR SEARCH INPUT:
        public bool SearchInputCheck()
        {
            int temp = 0;
            bool number = false;
            if (!String.IsNullOrEmpty(txtBxSearch.Text))
            {
                if (int.TryParse(txtBxSearch.Text, out temp))
                {
                    if (temp >= 0 && temp <= 100)
                    {
                        number = true;
                    }
                }
            }
            return number;
        }



        // FUCNTIONS TO ENABLE AND DISABLE THE GUI:
        // GOOD UNDER CERTAIN CONDITIONS 
        private void EnabelGui()
        {
            btnDisplayMetrics.Enabled = true;
            btnExit.Enabled = true;
            grpBoxSearchMode.Enabled = true;
            lstbxMetrics.Enabled = true;
            lblSearchEntry.Enabled = true;
            btnSearchGo.Enabled = true;
            grpBoxSearch.Enabled = true;
            rdbtnSearchByInt.Enabled = true;
            rdbtnSearchString.Enabled = true;
            txtBxSearch.Enabled = true;
            lstboxSearchResults.Enabled = true;
            mnuMetrics.Enabled = true;

        }
        private void DisableGui()
        {
            btnDisplayMetrics.Enabled = false;
            btnExit.Enabled = false;
            lstbxMetrics.Enabled = false;
            lblSearchEntry.Enabled = false;
            grpBoxSearch.Enabled = false;
            rdbtnSearchByInt.Enabled = false;
            rdbtnSearchString.Enabled = false;
            txtBxSearch.Enabled = false;
            lstboxSearchResults.Enabled = false;
            mnuMetrics.Enabled = false;
            mnuMetrics.Enabled = false;
        }



        //PUBLISHING FUNCTIONS:
        //THESE FUNCTIONS HELP ME PUBLISH TO THE LISTBOXES
        public void publishmetrics(string[] input)
        {
            foreach (string word in input)
            {
                lstbxMetrics.Items.Add(word + "\n");
            }
        }
        public void publishsearch(string[] input)
        {
            foreach (string word in input)
            {
                lstboxSearchResults.Items.Add(word + "\n");
            }
        }
    }
}
