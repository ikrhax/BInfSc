using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment_2._2
{
    class Converter
    {


        Dictionary<string, double> Currency = new Dictionary<string,double>();
        
        public Converter()
        {
            
            // Dictionary of currency names and values

            Currency.Add("USD",1);
            Currency.Add("AUD",0.98);
            Currency.Add("CAD",1.02);
            Currency.Add("EUR",0.75);
            Currency.Add("GBP",0.64);
            Currency.Add("NZD",1.28);

        }

        public double Convert (double amount, string cFrom, string cTo)
        {

            // Actual conversion function - I broke this into two lines because the assignment calls for conversion to USD first, then to the desired currency

            amount /= Currency[cFrom]; //To USD
            amount *= Currency[cTo]; // To desired currency

            //Spit out the result

            return amount;


        }

    }
}
