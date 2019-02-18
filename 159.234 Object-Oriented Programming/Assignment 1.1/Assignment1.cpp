/*
***********************************
*                                 *
*     159.234 - Assignment 1	    *	
*	       Simon Parr 		       *
*          09233113               *
*                                 *
***********************************
*/


/*

This Program Should:

	1. Read all the Data in students.txt and courses.txt
	
	2. Perform 3 Consistancy Checks:
		-Are there any students not enrolled in a course?
		-Are there any courses without students?
		-Are there any courses with non-existant students?



Input File Format:

	Students.txt:
		Contains - an integer expressing the number of students in the file.
		Each Student - first name, last name, id number, and y or n to indicate if fees have been paid. 
	
	Courses.txt:
		Contains - an integer expressing the number of courses in the file.
		Each Course - course identifier, course title, number of credits, and a list of 0 or more students terminated with -1.


*/


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct student
{
    string firstname;
    string lastname;
    int id;
    string paid;
};

struct course
{
    int code;
    string title;
	 int credits;
    int enrolled[];
};


int snumbers();
int cnumbers();

void populateStudents(student tempstudents[], int size);
void populateCourses(course myCourses[], int numcourses, int numstudents);


int main ()
{	
	
	int snum = 0;
	int cnum = 0;
	
	snum = snumbers();
	cnum = cnumbers();
	
	cout << "Students: " << snum << endl;
	cout << "Courses: " << cnum << endl;
	cout << endl;
	
	student myStudents[snum];
	course myCourses[cnum];
	
	populateStudents(myStudents, snum);
	populateCourses(myCourses, cnum, snum);
	
	for (int i = 0; i<snum; i++)
	{
		cout << myStudents[i].firstname << endl;
		cout << myStudents[i].lastname << endl;
		cout << myStudents[i].id << endl;
		cout << myStudents[i].paid << endl;
	}
	
}

int snumbers()
{
	
	ifstream input;
	input.open ("students.txt");
	
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
	}		
}


int cnumbers()
{
	ifstream input;
	input.open ("courses.txt");
	
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
	}
}

void populateStudents(student myStudents[], int size)
{
	string temp;
	int number = 0;
	int i = 0;
	
   ifstream input;
   input.open("students.txt");
	
	if(input.good())
	{
		getline(input,temp);
		
		while (i<size)
		{
				getline(input,temp);
				myStudents[i].firstname = temp;
				getline(input,temp);
				myStudents[i].lastname = temp;
				getline(input,temp);
				stringstream line(temp);
				line >> number;
				myStudents[i].id = number;
				getline(input,temp);
				myStudents[i].paid = temp;
				i++;
		}
   }
	else
	{
		cout << "Cannot open students.txt"<<  endl;
	}
}

void populateCourses(course myCourses[], int numcourses, int numstudents)
{
	string temp;
	string temparray[103];
	int number = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	
   ifstream input;
   input.open("courses.txt");
	
	if(input.good())
	{
		getline(input,temp);

		while (i<numcourses)
		{
			getline(input,temp)
			
			if
			
		
		/*
		while (i<numcourses)
		{
			getline(input,temp);
			stringstream line(temp);
			line >> number;
			myCourses[i].code = number;
			getline(input,temp);
			myCourses[i].title = temp;
			getline(input,temp);
			stringstream line2(temp);
			line2 >> number;
			myCourses[i].credits = number;
			
				while (number >= 0)
				{
					while (getline (input,temp))
					{
						line >> number;
						line.str("");
						cout << number << endl;
						myCourses[i].enrolled[j]=number;
						j++;
					}
				}
				i++;
		}
		*/
   }
	else
	{
		cout << "Cannot open courses.txt"<<  endl;
	}
	
}



