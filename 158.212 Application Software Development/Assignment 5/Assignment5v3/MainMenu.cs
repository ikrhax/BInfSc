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
    public partial class MainMenu : Form
    {
        public MainMenu()
        {
            InitializeComponent();
        }

        CreateStudent createstudent = new CreateStudent();
        CreatePaper createpaper = new CreatePaper();
        ExportMenu export = new ExportMenu();
        ImportMenu import = new ImportMenu();
        ManageEnrolements manageenrolements = new ManageEnrolements();

        private void btnStudentCreation_Click(object sender, EventArgs e)
        {
            createstudent.Show();
        }

        private void btnCreatePaper_Click(object sender, EventArgs e)
        {
            createpaper.Show();
        }

        private void btnImport_Click(object sender, EventArgs e)
        {
            export.Show();
        }

        private void btnExport_Click(object sender, EventArgs e)
        {
            import.Show();
        }

        private void btnEnrolementManagement_Click(object sender, EventArgs e)
        {
            manageenrolements.Show();
        }

        private void timerMain_Tick(object sender, EventArgs e)
        {
            University tmpUni = University.Instance;
            toolStripStatusStudents.Text = "Students: " + tmpUni.StudentCount();
            toolStripStatusPapers.Text = "Papers: " + tmpUni.PaperCount();
        }
    }
}
