/*
***********************************
*                                 *
*    159.234 - Assignment 1P2     *
*                                 *
*          09233113               *
*      Parr, Simon - Driver       *
*                                 *
*			  96066910               *
*    Harper, Rob - Navigator      *
*                                 *
***********************************
*/


/*
Assignment 2 Part 1


Problem to solve:
You will design a class hierarchy to work with date objects as described below . For submission reasons you must write all your class declara tions & definitions in one file that should be named a2p1.h


Requirements:
In what follows assume that YYYY MM DD, are three integers and YYYY stands for a year number, MM for a month number and, DD stands for a day number (e.g.: 2002 9 16 stands for year 2002, month September 
and day 16; for more info about standard date formats see : https://en.wikipedia.org/wiki/Date_format_by_country

For this assignment you will consider that a date can be given by three integers: YYYY MM DD or by an integer YYYY, a string specifying the name of the month and another integer DD; the name of the month 
may be short -like “Sep.” or long -like “September”.

You have to implement a hierarchy of date classes with a base class named Date. The Date class must have a pure virtual member function print. From Date class derive three classes: SDate, MDate, and LDate. 
Each class will display a date in a different format as explained below.

SDate’s print must display a date using a short format: DD/MM/YYYY (e.g: 10/9/201 6). 
MDate’s print must display a date using a medium format: DD - short month name - YYYY (e.g. 10-Sep-201 6). 
LDate’s print must display a date using a long format: day name, day number, long month name, year (e.g. Saturday, 10, September, 2016).


Note: 
The classes you design for this assign ent must provide at least: default constructors, custom con structors, and a print member function. See the examp le in Figure 1 for a possible driver program and t e corresponding output produced.


Hand-in: 
Submit a1 2.h electronically using STREAM.


Miscellaneous:
 
1.Do not include a main function in your a2p1.file
2.Do not send the file you used to test your classes.
3.Programs that do not compile in the lab, using gcc, get 0 marks.
4.Marks w ill bealloc ated for: correctness, completeness, use of C++ constructs, good OOP style-as
presented in lectures & labs, good structure for the solutio , document tion, and cle ar on screen output display.
5. Using goto, global variables or C-like I/O co nstructs (i.e printf, fprintf, scanf, FIL E*, etc) is not allowed and it will be penalised. Only constlobal variables are allowed.
6. Write YOUR ID NUMBER(S), and YOUR FAMILY NAME(S) first, assignmet number, what the program does at the beginning of the file you send electronic ally and at least comment each function.
7. When working in pairs, send one solution file per pair.
8. For algorithms to find the weekday for a given calendar date see: https:/ /en.wiki edia.org/wiki/Determination_of_the_day_of_the_week
If you have any questions about t his assignm ent, please ask the lecturer before its due time!

*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <array>
#include <string>
#include <cmath>

using namespace std;



/*
DATE PROTOTYPE:
*/

class Date 
{
	public:
		
	 Date (int d, string m, int y);
	 ~Date();
	
	 void sanitise();
	 void validatemonth();
	 void validateday();
	 void validateyear();
	 void domonthstuff();
	 int toint (string input);
	 int calculatedayofweek(int d, int m, int y);

	private:
		
	 int day = 0;
	 int month = 0;
	 int year = 0;
	
	 string stringmonth;
	 string nameofday;
	 string smonth;
	 string lmonth;
	
	 string shortmonths[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	 string longmonths[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	 string daynames[7] = {"Sunday", "Monday", "Tuesday", "Wedensday", "Thursday", "Friday", "Saturday"};
	 int monthdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	 
};

/*
DATE IMPLIMENTATION
*/

Date::Date (int y, string m, int d)
{
	/*
	Date Constructor:
	Accepts the 3 inputs in the following order: Day as an int, 
	*/

	 day = d;
	 stringmonth = m;
	 year = y;
	
	 sanitise();	 
	 void validatemonth();
	 void validatedayday();
	 void validateyears();
}

Date::~Date ()
{
	/*
	Deconstructor doesn't need implimentation - although it probably should have one. 
	*/	
}

void Date::sanitise() 
{
	/*
	TESTED AND WORKING
	Will sanitise the date to make sure that it follows expected norms. 
	*/
	
	if (isdigit(stringmonth[0]))
	{
		month = toint(stringmonth);
		stringmonth = "presentedasadigit";
	}
	else
	{
	 int sz = stringmonth.size();
	 for (int i = 0; i<sz; i++)
	 {
		 stringmonth[i] = tolower(stringmonth[i]);
	 }
	 stringmonth[0] = toupper(stringmonth[0]);
	}
	validateyear();
}

void Date::validateyear()
{
	/*
	TESTED AND WORKING
	Will validate the year and detect for a leap year. 
	*/
	if (year < 1582)
	{
		cout << year << " is invalid! The Georgian calander was adopeted in 1582AD. Year set to 1582AD." << endl;
		year = 1582;
	}
	
	if ((year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0))
	{
		monthdays[1]=29;
	}
	
	validatemonth();
}


void Date::validatemonth()
{
	
	/*
	TESTED AND WORKING
	Will validate months first, because that affects the day validation process. 	
	*/
	
	
	bool invalid = false;
	bool valid = false;
	
	if(stringmonth == "presentedasadigit")
	{
		if ((month<0)||(month>12))
		{
			cout << month << " is invalid! Month has been set to January." << endl;
			month = 0;
			invalid = true;
		}
		else
		{
			month = month-1;
		}
	}
	
	if((stringmonth != "presentedasadigit")&&(!invalid))
	{
		
		for (int i = 0; i < 12; i++)
		{
			if (stringmonth == shortmonths[i])
			{
				valid = true;
				month = i;
			}
		}
		
		for (int i = 0; i < 12; i++)
		{
			if (stringmonth == longmonths[i])
			{
				valid = true;
				month = i;
			}
		}
	}
	if ((!valid)&&(stringmonth != "presentedasadigit"))
	{
		cout << stringmonth << " is invalid! Month has been set to January." << endl;
		month = 0;
	}
	
	validateday();
}
	
void Date::validateday()
 {
	 /*
	 TESTED AND WORKING
	 Will validate days now.	
	 */

	 if((day < 0)||(day > monthdays[month]))
	 {
		 cout << day << " is invalid! Day has been set to 1." << endl;
		 day = 1;
	 }
	 domonthstuff();
}

int Date::calculatedayofweek(int d, int m, int y)
{
	
	/*
	TESTED AND WORKING
	Will successfully calculate the day of the week from the date values. 	
	*/
	
	/*
	From Wikipedia:
	
	The formula (d + m + y+ (y/4)+ c), where:
		d is the day of the month,
		m is the month's number in the months table
		y is the last two digits of the year, and
		c is the century's number in the "100s of Years" table.
	If the result is 0, the date was a Saturday; if 1 it was a Sunday, and so on through the week until 6 = Friday.
	
	
	For the Gregorian date of January 1, 2000 (a leap year):
		The day of the month: 1
		January in the months table: 6
		Last two digits of year: 0
		Last two digits of year divided by 4: 0
		Century number: 0
	The result is 7, leaving a remainder of 0 when divided by 7, so January 1, 2000 was a Saturday.
	*/
	
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

void Date::domonthstuff()
{
	
	/*
	TESTED AND WORKING
	Populates the last of the data members in the Date class. Cout left in for test purposes. 	
	*/

	
	lmonth = longmonths[month];
	smonth = shortmonths[month];
	
	int temp = calculatedayofweek(day, month+1, year);
	nameofday = daynames[temp];
	
	

	
	cout << "Final Class Data is: " << endl;
	cout << "Day: " << day << endl;
	cout << "Name of Day: " << nameofday << endl;
	cout << "Month: " << month << endl;
	cout << "Year: " << year << endl;
	cout << "Stringmonth: " << stringmonth << endl;
	cout << "Short Month: " << smonth << endl;
	cout << "Long Month: " << lmonth << endl;
	
}






int Date::toint(string input)
{	
	/*
	 Standard String to Int Conversion Function. 
	*/
	
    int temp = 0;
    stringstream line(input);
    line >> temp;
    return temp;
}



/*
 Prints Authors Information as per Assignment Requirements.  
*/
void info();


int main()
{
	/*
    Main for testing purposes only. Should be commented out before we hand in.   
   */
	
	int testday = 0;
	string testmonth;
	int testyear = 0;
		
	info();
	
	cout << "Enter a Day" << endl;
	cin >> testday;
	cout << "Enter a Month" << endl;
	cin >> testmonth;
	cout << "Enter a Year" << endl;
	cin >> testyear;
	
	Date testdate (testyear, testmonth, testday);
	
}

/*
 Prints Authors Information as per Assignment Requirements.  
*/
void info()
{
	cout <<"     ***********************************" << endl;
	cout <<"     *                                 *" << endl;
 	cout <<"     *     159.234 - Assignment 2P1    *" << endl;
	cout <<"     *                                 *" << endl;	
	cout <<"     *           ID 09233113           *" << endl;
	cout <<"     *     Parr, Simon - Navigator     *" << endl;
	cout <<"     *                                 *" << endl;
	cout <<"     *           ID 96066910           *" << endl;
	cout <<"     *      Robert Harper - Driver     *" << endl;
	cout <<"     *                                 *" << endl;    
	cout <<"     *                                 *" << endl;
	cout <<"     ***********************************" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
}
