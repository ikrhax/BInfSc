/*
***********************************
*                                 *
*     159.234 - Assignment 1      *
*                                 *
*     Rob Harper -Navigator       *
*			  96066910               *
*                                 *
*      Simon Parr - Driver        *
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


/* 
Things that Bother Me: 

	- myCourses.enrolled - how to regulate size so it matches MAX NUMBER OF STUDENTS. 
*/
 
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
 
using namespace std;
 
//Two structures, one for Students, one for Courses:
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
	 
//I could not figure out how to use a constructor to link the size of the arry to the number of students, so allowed for ALL students. 
    int enrolled[101];
};

 
//Funcitons to Get Data from Files:  
int snumbers(ifstream &input);
int cnumbers(ifstream &input);
void populateStudents(ifstream &input, student myStudents[], int size);
void populateCourses(ifstream &input, course myCourses[]);
 
//Functions to Carry out Required Checks:
void emptyCourses (course myCourses[], int cnum);
void notEnrolled (student myStudents[], course myCourses[], int cnum, int snum);
void nonExistent (student myStudents[], course myCourses[], int cnum, int snum);

//Function to Convert a String to an Int - helpful for repetitive calls:
int toint (string input);


int main ()
{   
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
    populateCourses(coursesin, myCourses);
	
	 emptyCourses(myCourses, cnum);
	 notEnrolled (myStudents, myCourses, cnum, snum);
	 nonExistent (myStudents, myCourses, cnum, snum);
	 
	 cout << "\n" << " \n" << "********** ALL DONE *********" << endl;
}
 

int snumbers(ifstream &input)
{
	 /*
	 This function will extract the NUMBER of Students presented in "students.txt" - this number will be used to size everything
	 */
     
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
	 /*
	 This function will extract the NUMBER of Courses presented in "courses.txt" - this number will be used to size everything
	 */
     
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
}
 
void populateStudents(ifstream &input, student myStudents[], int snum)
{
	/*
	This function will extract the BULK of the data from "students.txt" and place it in the array of structures
	*/
	
    string temp;
    int number = 0;
    int i = 0;
     
    if(input.good())
    {
        while (i<snum)
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
		  exit(0);
	 }
	 input.close();
}
 
void populateCourses(ifstream &input, course myCourses[])
{
	/*
	This function will extract the BULK of the data from "courses.txt" and place it in the array of structures
	*/
	
    string temp;
    int num = 0;
    int i = 0;
    int j = 0;
     
    if(input.good())
    {
		 while (!input.eof())
		 {
			 getline(input,temp);
			 num = toint(temp);
			 myCourses[i].code=num;
			 getline(input,temp);
			 myCourses[i].title=temp;
			 getline(input,temp);
			 num = toint(temp);
			 myCourses[i].credits=num;
			 
			 while(temp!="-1")
			 {
				 getline(input,temp);
				 num = toint(temp);
				 myCourses[i].enrolled[j]=num;
				 j++;
			 }
			 j=0;
			 i++;
		 }
   }
    else
    {
        cout << "Cannot open courses.txt"<<  endl;
		  exit(0);
    }
	 input.close();
}


void emptyCourses (course myCourses[], int cnum)
{
	/*
	This function iterates through the array of Course structures, looking for a course that has no students enrolled. I am taking advantage of the '-1' trailing value.
	*/
	
	int i = 0;
	
	cout << "Checking for Empty Courses:" << "\n" << endl;
	while (i < cnum)
	{
		if(myCourses[i].enrolled[0]==-1)
		{
			cout << myCourses[i].code << ", " << myCourses[i].title << ", Credits: " << myCourses[i].credits << ", has no students currently enrolled." << endl;
		}
		i++;
	}
}



void nonExistent(student myStudents[], course myCourses[], int cnum, int snum)
{
	/*
	This fucntion interates through BOTH the array of Student structures, and the array of Course Structures.
	It could make a list of both expected students, and students enrolled in courses? If a student appears in courses, but not in students pring ID number from courses and course title/id 
	*/
	
	int knownstudents[snum];
	bool exists = true;

	
	for (int i=0; i<snum; i++)
	{
		knownstudents[i]=myStudents[i].id;
	}
	
	cout << "\n" << "\n" << "\n" << "\n" << "Checking for IDs enrolled in Courses that don't belong to Valid Students - Finding Non-existent Students:" << "\n" << endl;
	
	int i = 0;
	int j = 0;
	int k = 0;
	
	while (i<cnum)
	{
		while(myCourses[i].enrolled[j]!=-1)
		{
			while (k<snum)
			{
				if(knownstudents[k]==myCourses[i].enrolled[j])
				{
					exists = false;
				}
				k++;
			}
			if(exists)
			{
				cout << "ID: " << myCourses[i].enrolled[j] << ", enrolled in " << myCourses[i].code << ", " << myCourses[i].title << ", Credits: " << myCourses[i].credits <<", is not a Valid Student ID." << endl;
			}
			 k = 0;
			 j++;
			 exists = true;
		}
		j=0;
		i++;
	}
}
				
			

void notEnrolled (student myStudents[], course myCourses[], int cnum, int snum)
{
	/*
	This fucntion interates through BOTH the array of Student structures, and the array of Course Structures.
	It will take a Student ID, and look for it in the course structures. If it does NOT find it, the Student details will be printed. 
	*/
	
	bool isthere = false;
	int i = 0;
	int j = 0;
	int k = 0;
	
	cout << "\n" << "\n" << "\n" << "\n" << "Checking for Students not Enrolled in a Course:" << "\n" << endl;
	
	while(i<snum)
	{
		while (j<cnum)
		{
			while(myCourses[j].enrolled[k]!=-1)
			{
				if(myCourses[j].enrolled[k]==myStudents[i].id)
				{
					isthere = true;
				}
				k++;
			}
			k = 0;
			j++;
		}
		if (!isthere)
		{
			cout << myStudents[i].firstname << " " << myStudents[i].lastname << ", " << "ID: " << myStudents[i].id << ", Paid fees?: " << myStudents[i].paid << endl;
		}
		j = 0;
		isthere = false;
		i++;
	}	
}



int toint(string input)
{
	/*
	Happy Chappy String Coversion Function - makes life easier. 
	*/
	
    int temp = 0;
    stringstream line(input);
    line >> temp;
    return temp;
}

