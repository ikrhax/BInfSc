/*
***********************************
*                                 *
*    159.234 - Assignment 1P2     *
*                                 *
*			  96066910               *
*     Harper, Rob - Driver        *
*                                 *
*          09233113               *
*    Parr, Simon - Navigator      *
*                                 *
***********************************
*/


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;


/*
STUDENT PROTOTYPE:
*/

class student 
{
	public:

	 void print();
	 void setData(string incoming[]);
	 int giveID();
	
	 int toint (string input);
	 char tochar (string input);
	
	
	private:
		
	 string firstname;
    string lastname;
    int id;
    char paid;
};


/*
COURSE PROTOTYPE:
*/

class course
{
	
	public:
	 
	 void printDetails();
	 void printAll();
	 void setData(string incoming[], int size);
	 void checkForNonExistent(int known[], int snum);
	 bool checkForStudentEnrollment(int id); 
	 bool isEmpty();
	 int toint (string input);
	 char tochar (string input);

	
	
	private:
		
	 int code;
    string title;
	 int credits;
    int enrolled[101];
	 int totalenrolled;
};



/*
STUDENT IMPLIMENTATION:  
*/

/*
This is a simple print function to print out the detials of a Student. Is used by the int main notEnrolled call.  
*/
void student::print()
{
	cout << lastname << ", " << firstname << ": ID " << id << ", paid fees " << paid << endl;
}


/*
This function returns the ID value of a Student. It is used by two int main functions; notEnrolled and nonExistent.
*/
int student::giveID()
{
	return id;
}


/*
This function prints just the finer details of the course; its code, title, and credit value. It is also used by the 
course::checkForNonExistant function. 
*/
void student::setData(string incoming[])
{
	firstname = incoming[0];
	lastname = incoming[1];
	id = toint(incoming[2]);
	paid = tochar(incoming[3]);	
}


 /*
Conversion Functions:
*/

int student::toint(string input)
{	
    int temp = 0;
    stringstream line(input);
    line >> temp;
    return temp;
}

char student::tochar(string input)
{	
    char temp = 0;
    stringstream line(input);
    line >> temp;
    return temp;
}



/*
COURSE IMPLIMENTATION:  
*/

/*
This function prints just the finer details of the course; its code, title, and credit value. It is also used by the 
course::checkForNonExistant function. 
*/
void course::printDetails()
{
	cout << code << ", " << title << ", credits " << credits << endl;
}


/*
This funciton was mainly used during testing. It prints the entire details of the course including enrolled students
*/
void course::printAll()
{
	cout << code << " " << title << " " << credits << endl;
	cout << "There are " << totalenrolled << " students enrolled in this course." << endl;
	
   for (int i = 0; i < 101; i++)
	{
		cout << enrolled[i] << endl;
	}		
}


/*
This the the course's setter. It accepts an array of strings, passed to it from the function populateCourses in main. 
It sorts the information, converting where required, and storing it in the class. 
*/
void course::setData(string incoming[], int size)
{
	string temp;
	
	temp = incoming[0];
	code = toint(temp);
	title = incoming[1];
	temp = incoming[2];
	credits = toint(temp);
	
	for (int i = 3; i < size; i++)
	{
		int j = i - 3;
		totalenrolled = j;
		temp = incoming[i];
		enrolled[j] = toint(temp);
	}

	
/*
Added this here to sanitize the rest of the enrolled array. It would be so much better if I could trim this array to size. 
Or use a vector.
*/
	for (int i = size-3; i < 101; i++)
	{
		enrolled[i] = 1;
	}
}


/*
This function interacts with the int main function emptyCourses. It checks the enrolled array, and if it finds a -1 in the 
first position, returns true. This indicates that the course is empty. 
*/
bool course::isEmpty ()
{
	if (enrolled[0]==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*
This is the function that interacts with the int main function notEnrolled. It is designed to accept a single ID
and iterate through its enrolled students searching. If the ID is found, it no longer cares about anything and returns true.  
*/
bool course::checkForStudentEnrollment (int id)
{	
	int i = 0;
	bool result = false;
	
	while ( i < totalenrolled)
	{
		if (enrolled[i]==id)
		{
			result = true;
			break;
		}
		else
		{
		i++;
		}
	}
	if (result)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*
This function interacts with the int main function nonExistant. It accepts an array of known students, or valid ID numbers, and 
compares them to the ID numbers enrolled in the course. It does this by taking an ID from enrolled, and comparing it to the whole
array of known. If it finds the ID from enrolled in known, it breaks and moves to the next student enrolled. If, at the end of a
compare loop, it still has not found a match, it will print the details of the course. 
*/

void course::checkForNonExistent(int known[], int snum)
{
	int i = 0;
	int j = 0;
	int result = false;
	
	if (enrolled[i]!=-1)
	{
		while (enrolled[i]!=-1)
		{
			while (j < snum)
			{
				if (enrolled[i]==known[j])
				{
					result = true;
					break;
				}
				j++;
			}
			if (!result)
			{
				printDetails();
			}
			j = 0;
			result = false;
			i++;
		}
	}		
}



 /*
Conversion Functions:
*/

int course::toint(string input)
{	
    int temp = 0;
    stringstream line(input);
    line >> temp;
    return temp;
}

char course::tochar(string input)
{	
    char temp = 0;
    stringstream line(input);
    line >> temp;
    return temp;
}




//Function to Print out Author Details:
void printMyDetails();
void printEnd();

//Functions for Testing 
void printAllCourses (course myCourses[], int cnum);
void printAllStudents (student myStudent[], int snum);

//Funcitons to Get Data from Files:  
int snumbers(ifstream &input);
int cnumbers(ifstream &input);
void populateStudents(ifstream &input, student myStudents[], int snum);
void populateCourses(ifstream &input, course myCourses[], int cnum);
 
//Functions to Carry out Required Checks:
void emptyCourses (course myCourses[], int cnum);
void notEnrolled (student myStudents[], course myCourses[], int cnum, int snum);
void nonExistent (student myStudents[], course myCourses[], int cnum, int snum);


int main ()
{
	 printMyDetails();
	
	 int snum = 0;
    int cnum = 0;
	
	 ifstream studentsin;
	 studentsin.open("students.txt");
	 ifstream coursesin;
	 coursesin.open("courses.txt");
     
    snum = snumbers(studentsin);
    cnum = cnumbers(coursesin);
	
	 student myStudents[snum];
	 course myCourses[cnum];
	 
	 populateStudents(studentsin, myStudents, snum);
	 populateCourses(coursesin, myCourses, cnum);
	
	 notEnrolled (myStudents, myCourses, cnum, snum);
	 emptyCourses(myCourses, cnum);
	 nonExistent (myStudents, myCourses, cnum, snum);
	 
	 printEnd();
}

/*
DATA EXTRACTION FUNCTIONS
*/

/*
Snumbers and Cnumbers are the two functions I have created to extract the first line of the text file. This line
lets us know how many students and courses to expect in the file. 
*/
int snumbers(ifstream &input)
{
    string temp;
    int number;
     
    if(input.good())
    {
       getline(input,temp);
       stringstream line(temp);
       line >> number;
		 return number;
    }
    else
    {
        cout << "Cannot open students.txt"<<  endl;
        return 0;
		  exit(0);
    }       
}

int cnumbers(ifstream &input)
{
    string temp;
    int number;
     
     
    if(input.good())
    {
       getline(input,temp);
       stringstream line(temp);
       line >> number;
		 return number;
    }
    else
    {
        cout << "Cannot open courses.txt"<<  endl;
        return 0;
		  exit(0);
    }
};

/*
PopulateStudents and PopulateCourses extract the remaining data. We have added a loop in them to run for the expected
number of data sets. Hopefully this will prevent the functions extracting empty lines etc at the end of the file. 
This was noted as a problem in our feedback from Assignment 1, Part 1. 
*/
void populateStudents(ifstream &input, student myStudents[], int snum)
{
	int i = 0;
	string incoming[4];
	string temp;
	while ( i < snum)
	{
		for (int j = 0; j<4; j++)
		{
			getline(input, temp); 
			incoming[j] = temp;
		}
		myStudents[i].setData(incoming);
		i++;
	}
}

void populateCourses(ifstream &input, course myCourses[], int cnum)
{
	int i = 0;
	int j = 0;
	string temp;
	
	while (i < cnum)
	{
		string incoming[104] = "";
		
		while(temp!="-1")
		{
			getline(input,temp);
			incoming[j]=temp;
			j++;
		}
		myCourses[i].setData(incoming, j);
		j = 0;
		temp = "";
		i++;
	}
}


/*
CONSISTENCY CHECK FUNCTIONS:
*/

/*
emptyCourses - queries each course in the array. It interacts with course::isEmpty, and expects a bool response. 
If the bool returned is true, denoting empty, it calls the course member function printDetails, causing the course
to print its details. 
*/
void emptyCourses (course myCourses[], int cnum)
{
	cout << "Courses with no Students enrolled: " << endl;
	
	bool temp = true;
	
	for (int i = 0; i<cnum; i++)
	{
		temp = myCourses[i].isEmpty();
		if (temp)
		{
			myCourses[i].printDetails();
		}
	}
	cout << endl;
	cout << endl;
}


/*
notEnrolled - this int main function interacts with both the student and course arrays. It known how many students
and courses exist in each array, and will not stray beyond bounds. It queries a single student for an ID number, 
the itterates through the course array checking for an enrollment. If it finds no enrollment, it will print the 
student's details. 
*/
void notEnrolled (student myStudents[], course myCourses[], int cnum, int snum)
{

	int searchingfor = 0;
	bool found = false;
	int i = 0;
	int j = 0;
	
	cout << "Students not enrolled in any paper are: " << endl;
	
	while ( i < snum)
	{
		searchingfor = myStudents[i].giveID();	
		
		while ( j < cnum)
		{
			found = myCourses[j].checkForStudentEnrollment(searchingfor);
			
			if (found)
			{
				break;
			}
			j++;
		}
		if (!found)
		{
			myStudents[i].print();
		}
		j = 0;
		i++;
		found = false;
	}
	
	cout << endl;
	cout << endl;
}


/*
nonExistent - this int main function interacts with both the student and course arrays. It creates a list of known students 
by requesting an ID from each class. It then moves through the courses array, passing each course a list of known students. 
The course::checkForNonExistant then checks this array of known students against the students enrolled in the course, printing 
details of any unknown, and therefor nonexistent students. 
*/
void nonExistent (student myStudents[], course myCourses[], int cnum, int snum)
{
	int knownstudents[snum];
	
	//Generate list of known students.
	for (int i = 0; i < snum; i++)
	{
		knownstudents[i]=myStudents[i].giveID();
	}
	
	cout << "Courses with NON-EXISTENT students enrolled:" << endl;
	
	//Query each course. 
	for (int i = 0; i < cnum; i++)
	{
		myCourses[i].checkForNonExistent(knownstudents, snum);
	}
	cout << endl;
	cout << endl;
}



/*
TEST FUNCTIONS:
*/


/*
This function prints every detail of every course. 
*/
void printAllCourses(course myCourses[], int cnum)
{
	for(int i = 0; i < cnum; i++)
	{
		myCourses[i].printAll();
	}
}


/*
This function prints every details of every student. 
*/
void printAllStudents (student myStudents[], int snum)
{
	for (int i = 0; i<snum; i++)
	{
		myStudents[i].print();
	}
	
}



/*
CONVERSION FUNCTIONS: They are friend functions for each class. 
*/
int toint(string input)
{	
    int temp = 0;
    stringstream line(input);
    line >> temp;
    return temp;
}

char tochar(string input)
{	
    char temp = 0;
    stringstream line(input);
    line >> temp;
    return temp;
}


/*
PRINT AUTHOR DETAILS FUNCTIONS:
These simply print out our details and provide a nice end to the program. 
*/
void printMyDetails()
{
	cout <<"     ***********************************" << endl;
	cout <<"     *                                 *" << endl;
 	cout <<"     *     159.234 - Assignment 1P2    *" << endl;
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

void printEnd()
{
	cout << endl;	
   cout <<"     ***********************************" << endl;
	cout <<"                   ALL DONE             " << endl;
	cout <<"     ***********************************" << endl;
}
