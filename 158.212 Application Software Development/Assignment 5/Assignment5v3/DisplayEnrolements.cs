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
    public partial class DisplayEnrolements : Form
    {
        public DisplayEnrolements()
        {
            InitializeComponent();
        }

        University tmpuni = University.Instance;

        private void btnStudentSearch_Click(object sender, EventArgs e)
        {
            string search = txtbxSearchString.Text;
            if (IsInputNumber())
            {

            }
                

        }

        //FUNCTION TO CHECK IF INPUT IS AN NUMBER OR A NAME
        public bool IsInputNumber()
        {
            int result = 0;
            string input = txtbxSearchString.Text;
            bool output = false;
            bool isnum = int.TryParse(input, out result);
            if (isnum)
            {
                output = true;
            }
            else
            {
                output = false;
            }
            return output;
        }
    }
}
