using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment5v3
{
    class University
    {

        //CREATE A SINGLETON
        static readonly University _instance = new University();
        
        //MASTER RECORD REPOSITORIES - BULK STUDENT AND PAPER STORAGE
        private Student[] StudentStorage = new Student[200];
        private Paper[] PaperStorage = new Paper[50];


        //REPOSITORIES TO MANAGE ENROLEMENTS AND OTHER VARIOUS THINGS
        private Dictionary<string, string[]> EnrolementsByStudent = new Dictionary<string, string[]>();
        private Dictionary<string, string[]> EnrolementsByPaper = new Dictionary<string, string[]>();

        //SWITH REPOSITORIES FOR A LOLS
        private SortedList<string, string> StudentIDForName = new SortedList<string, string>();
        private SortedList<string, string> PaperCodeForName = new SortedList<string, string>();


        //OTHER REQUIRED VARIABLES:
        int i = 0;
        int j = 0;
        int studentcount = 0;
        int papercount = 0;


        //FUNCTIONS THAT DO STUFF

        //SINGLETON FUNCTION

        public static University Instance
        {
            get { return _instance; }
        }

        //CHECK IF STUDENT EXISTS
        public bool CheckIfStudentExists (string input)
        {
            bool output = false;
            if (StudentIDForName.ContainsKey(input))
            {
                output = true;
            }
            else
            {
                output = false;
            }
            return output;
        }

        //CHECK IF A PAPER ALREADY EXISTS
        public bool CheckIfPaperExists (string input)
        {
            bool output = false;
            if (PaperCodeForName.ContainsKey(input))
            {
                output = true;
            }
            else
            {
                output = false;
            }
            return output;
        }

        //ADD A STUDENT
        public void AddAStudent (string id, string name, Student student)
        {
            StudentIDForName.Add(id, name);
            StudentStorage[i] = student;
            i++;
            studentcount++;

        }

        //ADD A PAPER 
        public void AddAPaper (string code, string name, Paper paper)
        {
            PaperCodeForName.Add(code, name);
            PaperStorage[j] = paper;
            j++;
            papercount++;
        }


        //PROVIDE INFO FOR STUDENT AND PAPER COUNTS:
        public string StudentCount()
        {
            string output = studentcount.ToString();
            return output;
        }
        public string PaperCount()
        {
            string output = papercount.ToString();
            return output;
        }


        //SEARCH FUNCTIONS - SEACH BY ID OR CODE AND RETURN DETAILS
        public string[] SearchInStudentStorage(string input)
        {
            string[] outputdetails = null;
            for (int i = 0; i > StudentStorage.Length; i++)
            {
                if (StudentStorage[i].StudentSearchByID(input))
                {
                    outputdetails = StudentStorage[i].GetStudentDetails();
                }
            }
            return outputdetails;
        }

        public string[] SearchInPaperStorage(string input)
        {
            string[] outputdetails = null;
            for (int i = 0; i > PaperStorage.Length; i++)
            {
                if (PaperStorage[i].PaperSearchByCode(input))
                {
                    outputdetails = StudentStorage[i].GetStudentDetails();
                }
            }
            return outputdetails;
        }


        //CHECK PAPER ENROLEMENTS
    }
}
