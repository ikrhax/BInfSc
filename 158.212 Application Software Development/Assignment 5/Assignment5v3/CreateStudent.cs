using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Security.Cryptography;

namespace Assignment5v3
{
    public partial class CreateStudent : Form
    {
        public CreateStudent()
        {
            InitializeComponent();
        }



        //RANDOM TEMP VARIABLES
        string id = null;   
        string name = null;
        string dob = null;
        string address = null;



        //THE REAL BUSINESS:
        private void btnCreateStudent_Click(object sender, EventArgs e)
        {
            if ((!string.IsNullOrEmpty(txtbxStudentName.Text)) && (!string.IsNullOrEmpty(msktxtbxStudentDOB.Text)))
            {
                University tmpUni = University.Instance;
                PopulateStudentDetails();
                string bibstring = CreateStringBibString();
                id = CreateMD5Hash(bibstring);
                if (!tmpUni.CheckIfStudentExists(id))
                {
                    Student currentstudent = new Student(id, name, dob, address);
                    tmpUni.AddAStudent(id, name, currentstudent);
                    MessageBox.Show(name + " was created and issued the ID number " + id);
                    ClearAllTextBoxes();
                    this.Hide();
                }
                else
                {
                    Error("A Student Like this Already Exists", "Student Exists");
                    ClearAllTextBoxes();
                }
            }
            else
            {
                Error("I can't create a Student from nothing", "Input Empty");
                ClearAllTextBoxes();
            }
        }


        //FUNCTION TO CLEAR ALL THE TEXT BOXES

        public void ClearAllTextBoxes()
        {
            txtbxStudentName.Text = null;
            msktxtbxStudentDOB.Text = null;
            txtbxrchStudentAddress.Text = null;
        }
    

        //  CREATE A COMBINED STRING FROM STUDENTS BIBLIOGRAPHIC DETAILS. 
        public string CreateStringBibString()
        {
            string output = txtbxStudentName.Text + msktxtbxStudentDOB.Text;
            return output;
        }


        //  CREATE A MD5 HASH - GIVES ME A UNIQUE HASH THAT I WILL USE AS MY STUDENT ID
        public string CreateMD5Hash(string input)
        {
            MD5CryptoServiceProvider hasher = new MD5CryptoServiceProvider();
            byte[] inputbytes = System.Text.Encoding.ASCII.GetBytes(input);
            byte[] hash = hasher.ComputeHash(inputbytes);

            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < hash.Length; i++)
            {
                builder.Append(hash[i].ToString());
            }
            return builder.ToString();
        }
        //POPULATE VARIABLES
        public void PopulateStudentDetails()
        {
            name = txtbxStudentName.Text;
            dob = msktxtbxStudentDOB.Text;
            address = txtbxrchStudentAddress.Text;
        }

        // MY STANDARD ERROR FUNCTION
        public void Error(string error, string thinking)
        {
            MessageBox.Show(error, thinking, MessageBoxButtons.OK, MessageBoxIcon.Error);
        }
    }
}
