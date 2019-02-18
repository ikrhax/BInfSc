using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Assignment_2._2
{
    public partial class currencyconverter : Form
    {

        // 158.212 - Simon Parr - 09233113 - Assignment 2 - Version 2.2
        // comboBox > Radiobutton > Textbox
        // Error Funciton Added
        // Coverter Class Added
        // Currency Dicitonary Added

        public void Error(string error)
        {
            // Function created to allow for repitious calls of Messagebox

            MessageBox.Show(error, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        public currencyconverter()
        {
            // Initialise!

            InitializeComponent();
            convertFrom.SelectedIndex = 0;
            convertTo.SelectedIndex = 0;
        }

        private void convertbutton_Click(object sender, EventArgs e)
        {
            
            //Amount input validation - checking for nums - convert string to doubles. Validation of input/output currency is not required as combobox

            try
            {
                double.Parse(txtboxAmount.Text);
                lblAmount.Text = ("Amount to convert:");
                lblAmount.ForeColor = Color.Black;
            }
            catch
            {
                Error("Input Invalid");
                txtboxAmount.Clear();
                lblAmount.Text = ("Please enter a valid amount:");
                lblAmount.ForeColor = Color.Red;
                return;
            }

            // Creating an instance of my coverter class!

            Converter x = new Converter();
            
            // I wanted to tell the user what work was being carried out

            lblResult.Text = txtboxAmount.Text + " " + convertFrom.Text + " converted to " + convertTo.Text + " is:";
            
            //I am going to drop the result straight into the result textbox

            txtboxResult.Text = "$" + x.Convert(double.Parse(txtboxAmount.Text), convertFrom.SelectedItem.ToString(), convertTo.SelectedItem.ToString()).ToString();
          
        }


        private void resetbutton_Click(object sender, EventArgs e)
        {
            //Threw errors with repititous testing so created reset button to reduce them

            txtboxAmount.Clear();
            txtboxResult.Clear();
            lblAmount.Text = ("Amount to convert:");
            lblResult.Text = ("Converted Result:");
        }
    }
}
