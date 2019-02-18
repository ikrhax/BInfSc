using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;


namespace Assignment4Final
{
    public class TextHelper
    {   
        public SortedDictionary<string,int> AppearanceTally = new SortedDictionary<string,int>();
        ArrayList Words = new ArrayList();
        int[] WordLengths = null;
        public int max=0;
        public int average=0;
        public int min=0;
        public int common = 0;


        // MEMBERS TO POPULATE THE ARRAY AND THE DICTIONARY:
 
        // POPULATING THE DICTIONARY HERE: 
        public void PopulateDictionary(string[] input)
        {
            if (input != null)
            {
                foreach (string word in input)
                {
                    if (!string.IsNullOrWhiteSpace(word))
                    {
                        if (AppearanceTally.ContainsKey(word))
                        {
                            AppearanceTally[word] = AppearanceTally[word] + 1;
                        }
                        else
                        {
                            AppearanceTally.Add(word, 1);
                        }
                    }
                }
            }
        }


        //POPULATING AND SORTING THE ARRAYLIST:
        public void PopulateArray(string[] input)
        {
            if (input != null)
            {
                foreach (string word in input)
                {
                    if (!Words.Contains(word))
                    {
                        Words.Add(word);
                    }
                }
                Words.Sort();
            }
        }


        //POPULATE LENGTHS ARRAY:
        public void PopulateLengths()
        {
            string[] output = (string[])Words.ToArray(typeof(string));
            ArrayList templist = new ArrayList();
            foreach (string word in output)
            {
                int temp = word.Length;
                templist.Add(temp);
            }
            WordLengths = (int[])templist.ToArray(typeof(int));
            if (WordLengths.Count() != 0)
            {
                max = WordLengths.Max();
                min = WordLengths.Min();
                if (min == 0)
                {
                    min = min + 1;
                }
                average = Convert.ToInt32(WordLengths.Average());
            }
        }


        
        
        //FUNCTIONAL MEMBERS - ONES THAT PROVIDE A CRUCIAL FUNCTION:

        
        //MEMBERS ASSOCIATED WITH THE DICTIONARY:
        
        //SEARCH FOR A WORD, RETURN NUMBER OF APPEARANCES: 
        public int SearchByWord(string input)
        {
            int output = 0;
            if (AppearanceTally.ContainsKey(input)) 
            {
                output = AppearanceTally[input];
                return output;
            }
            else
            {
                output = 0;
                return output;
            }
        }

        public string[] MostCommon()
        {
            ArrayList templist = new ArrayList();
            int max = AppearanceTally.Values.Max();
            foreach (KeyValuePair<string, int> values in AppearanceTally)
            {
                if (values.Value==max)
                {
                    templist.Add(values.Key);                                
                }
            }
            common = max;
            string[] output = (string[])templist.ToArray(typeof(string));
            return output;
        }



        //MEMBERS ASSOCIATED WITH THE ARRAY:

        //SEARCH FOR A NUMBER OF LETTERS AND RETURN WORDS:
   
        public string[] SearchByLength (int input)
        {
            ArrayList templist = new ArrayList();
            foreach(string word in Words)
            {
                if (word.Length==input)
                {
                    templist.Add(word);
                }
            }
            string[] output = (string[])templist.ToArray(typeof(string));
            return output;
        }


        //DISPLAY OF METRICS: 

        //DISPLAY MAX LENGTH WORDS

        public string[] MaximumLength()
        {
            ArrayList templist = new ArrayList();
            foreach (string word in Words)
            {
                if (word.Length == max)
                {
                    templist.Add(word);
                }
            }
            string[] output = (string[])templist.ToArray(typeof(string));
            return output;           
        }


        //DISPLAY AVERAGE LENGTH WORDS

        public string[] AverageLength()
        {
            ArrayList templist = new ArrayList();
            foreach (string word in Words)
            {
                if (word.Length == average)
                {
                    templist.Add(word);
                }
            }
            string[] output = (string[])templist.ToArray(typeof(string));
            return output;
        }


        //DISPLAY MIN LENGTH WORDS

        public string[] MinimumLength()
        {
            ArrayList templist = new ArrayList();
            foreach (string word in Words)
            {
                if (word.Length == min)
                {
                    templist.Add(word);
                }
            }
            string[] output = (string[])templist.ToArray(typeof(string));
            return output;
        }

        public object MostCommon(string p)
        {
            throw new NotImplementedException();
        }
    }
}
