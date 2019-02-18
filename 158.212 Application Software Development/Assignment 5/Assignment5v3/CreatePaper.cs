using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Assignment5v3
{
    public partial class CreatePaper : Form
    {
        public CreatePaper()
        {
            InitializeComponent();
        }

        //RANDOM TEMP VARIABLES
        string code = null;
        string name = null;
        string coordinator = null;
        string description = null;


        //THE ACTUAL BEANS:
        private void btnCreatePaper_Click(object sender, EventArgs e)
        {
            if ((!string.IsNullOrEmpty(txtbxPaperCode.Text))&&(!string.IsNullOrEmpty(txtbxPaperName.Text)))
            {
                University tmpuni = University.Instance;
                PopulatePaperDetails();
                if (!tmpuni.CheckIfPaperExists(code))
                {
                    Paper currentpaper = new Paper(code, name, coordinator, description);
                    tmpuni.AddAPaper(code, name, currentpaper);
                    MessageBox.Show(code + " " + name + " was created");
                    ClearAllTextBoxes();
                    this.Hide();
                }
                else
                {
                    Error("A Paper like this already exists", "Paper Exists");
                }
            }
            else
            {
                Error("I can't create a Paper from nothing", "Input Empty");
                ClearAllTextBoxes();
            }
        }



        //FUCNTION TO POPULATE TEMP VARIABLES
        private void PopulatePaperDetails ()
        {
            code = txtbxPaperCode.Text;
            name = txtbxPaperName.Text;
            coordinator = txtbxPaperCoordinator.Text;
            description = rchtxtbxPaperDescription.Text;
        }


        //FUNCTION TO CLEAR ALL TEXT BOXES
        public void ClearAllTextBoxes()
        {
            txtbxPaperCode.Text = null;
            txtbxPaperCoordinator.Text = null;
            txtbxPaperName.Text = null;
            rchtxtbxPaperDescription.Text = null;
        }


        // MY STANDARD ERROR FUNCTION
        public void Error(string error, string thinking)
        {
            MessageBox.Show(error, thinking, MessageBoxButtons.OK, MessageBoxIcon.Error);
        }
    }
}
