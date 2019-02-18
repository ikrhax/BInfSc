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
		
	 Date ();
	 Date (int d, string m, int y);
	 Date (int d, int m, int y);
	 ~Date();
	 
	 virtual void print() = 0;
	
	 void validateintmonth();
	 void validatestringmonth();
	 void validateday();
	 void validateyear();
	 void domonthstuff();
	 int calculatedayofweek(int d, int m, int y);
	 


	protected:
		
	 signed int day;
	 signed int month;
	 signed int year;
	
	 string stringmonth;
	 string nameofday;
	 string smonth;
	 string lmonth;
	
	 string shortmonths[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	 string longmonths[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	 string daynames[7] = {"Sunday", "Monday", "Tuesday", "Wedensday", "Thursday", "Friday", "Saturday"};
	 int monthdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	 
};

Date::Date (int y, string m, int d)
{
	 day = d;
	 stringmonth = m;
	 year = y;
	 
	 validatestringmonth();
	 validateday();
	 validateyear();
	 domonthstuff();
}

Date::Date (int d, int m, int y)
{
	 day = d;
	 month = m-1;
	 year = y;
	 
	 validateintmonth();
	 validateday();
	 validateyear();
	 domonthstuff();
}

Date::Date()
{
	 day = 1;
	 month = 0;
	 year = 1;
	
	 validateintmonth();
	 validateday();
	 validateyear();
	 domonthstuff();
}

Date::~Date ()
{

}


void Date::validateyear()
{
	if (year < 0)
	{
		cout << year << " is invalid! Year set to 1." << endl;
		year = 1;
	}
	
	if ((year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0))
	{
		cout << "Leap Year Detected" << endl;
		monthdays[1]=29;
	}
}


void Date::validateintmonth()
{
	if ((month<0)||(month>=12))
	{
		cout << month << " is invalid! Month has been set to January." << endl;
		month = 0;
	}
}
	
void Date::validatestringmonth()
{
	bool valid = false;
	int sz = stringmonth.size();
	
	for (int i = 0; i<sz; i++)
	{
		stringmonth[i] = tolower(stringmonth[i]);
	}
	stringmonth[0] = toupper(stringmonth[0]);
	
	for (int i = 0; i < 12; i++)
	{
		if (stringmonth == shortmonths[i])
		{
			valid = true;
			month = i;
			smonth = shortmonths[month];
		}
	}
		
	for (int i = 0; i < 12; i++)
	{
		if (stringmonth == longmonths[i])
		{
			valid = true;
			month = i;
			lmonth = longmonths[month];
		}
	}
	
	if (!valid)
	{
		cout << stringmonth << " is invalid! Month has been set to January." << endl;
		month = 0;
	}
}
	
void Date::validateday()
 {
   if((day < 0)||(day > monthdays[month]))
	{
		 cout << day << " is invalid! Day has been set to 1." << endl;
		 day = 1;
	}
}

int Date::calculatedayofweek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

void Date::domonthstuff()
{
	lmonth = longmonths[month];
	smonth = shortmonths[month];
	
	int temp = calculatedayofweek(day, month+1, year);
	nameofday = daynames[temp];	
}





/*
SDate Class:
*/
class SDate : public Date
{
	public:
		
	 SDate() : Date(){};
    SDate (int y, string m, int d) : Date (y,m,d){};
	 SDate (int d, int m, int y) : Date (y,m,d){};
		
	 void print ()
	 {
		cout << day << "/" << month+1 << "/" << year;
	 }	
};


class MDate : public Date
{
	public:
		
	 MDate() : Date(){};
	 MDate (int y, string m, int d) : Date (y,m,d){};
	 MDate (int d, int m, int y) : Date (y,m,d){};
		
	 void print ()
	 {
		cout << day << "-" << smonth << "-" << year;
	 }
};


class LDate : public Date
{
	public:
		
	 LDate() : Date(){};
	 LDate (int y, string m, int d) : Date (y,m,d){};
	 LDate (int d, int m, int y) : Date (y,m,d){};
		
	 void print ()
	 {
		cout << nameofday << ", " << day << ", " << lmonth << ", " << year;
	 }
	
};


/*
DATE IMPLIMENTATION
*/

/*
 Prints Authors Information as per Assignment Requirements.  
*/
void info();


int main()
{
/*
	Main for testing purposes only. Should be commented out before we hand in.   
*/
	
	info();
	
	LDate ld;
	SDate sd(-2002, "SEP", -23);
	
	Date *d[12];
	
	d[0] = new SDate;
	d[1] = new MDate;
	d[2] = new LDate;
	d[3] = new LDate(1998,2,29);
	d[4] = &sd;
	d[5] = new MDate(1999,"Dec",31);
	d[6] = new MDate(1990,"august",1);
	d[7] = new LDate(2002,"SeptEMbeR",16);
	d[8] = new SDate(2002,"october",1);
	d[9] = new MDate(2001,"pvc",23);
	d[10] = new SDate(2100,"Feb",29);
	d[11] = new LDate(1990,"june",31);
	
	cout << endl;
	
	for (int i = 0; i<12; i++)
	{
		d[i] -> print();
		cout << endl;
		if ( i%3 == 2)
		{
			cout << endl;
		}
	}
	
	cout << endl;
	cout << "One of the dates again: ";
	sd.print();
	
	return 0;
	
}
	

/*
OLD MAIN FOR TESTING
*/

/*

int main ()
{
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

*/

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
