using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment5v3
{
    class Paper
    {


        private readonly string _code;
        private readonly string _name;
        private readonly string _coordinator;
        private readonly string _description;

        //CUSTOM CONSTRUCTOR
        public Paper (string code, string name, string coordinator, string description)
        {
            code = _code;
            name = _name;
            coordinator = _coordinator;
            description = _description;
        }

        //FUNCTION TO RETURN CODE VALUE
        private string GetPaperCodeValue()
        {
            string output = _code;
            return output;
        }


        //FUNCTION FOR GETTING PAPER DETAILS
        public string[] GetPaperDetails()
        {
            string[] paperdetails = {_code,_name,_coordinator,_description};
            return paperdetails;
        }


        //FUNCTIONS TO AID IN SEARCHES
        public bool PaperSearchByCode(string input)
        {
            bool output = false;
            if (input == _code)
            {
                output = true;
            }
            else
            {
                output = false;
            }
            return output;
        }
        public bool PaperSearchByName(string input)
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
