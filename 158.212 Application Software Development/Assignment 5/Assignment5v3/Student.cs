using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment5v3
{
    class Student
    {
        private readonly string _id;
        private readonly string _name;
        private readonly string _dob;
        private readonly string _address;


        //CUSTOM CONSTRUCTOR
        public Student (string id, string name, string dob, string address)
        {
            id = _id;
            name = _name;
            dob = _dob;
            address = _address;
        }


        //FUNCTION FOR GETTING STUDET ID VALUE
        public string GetStudentIDValue()
        {
            string output = _id;
            return output;
        }

        //FUNCTION FOR GETTING STUDENT DETAILS
        public string[] GetStudentDetails()
        {
            string[] studentdetails = { _id, _name, _dob, _address };
            return studentdetails;
        }

        
        //FUNCTIONS TO AID IN SEARCHES
        public bool StudentSearchByID(string input)
        {
            bool output = false;
            if (input == _id)
            {
                output = true;
            }
            else
            {
                output = false;
            }
            return output;
        }
        public bool StudentSearchByName(string input)
        {
            bool output = false;
            if (input == _name)
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
