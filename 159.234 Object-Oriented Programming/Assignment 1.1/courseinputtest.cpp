#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

struct course
{
    string code;
    string title;
	 string credits;
    string enrolled[100];
};



int cnumbers();
int toInt (string input);
void populateCourses(course myCourses[], int numcourses);


int main ()
{	

	int cnum = 0;
	cnum = cnumbers();
	
	cout << "Courses: " << cnum << endl;
	
	course myCourses[cnum];
	
	populateCourses(myCourses,cnum);
	
	for (int i = 0; i < cnum; i++)
	{
		cout << myCourses[i].code << endl;
		cout << myCourses[i].title << endl;
		cout << myCourses[i].credits << endl;
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


void populateCourses(course myCourses[], int numcourses)
{
	string temp;
	
   ifstream input;
   input.open("courses.txt");
	
	if(input.good())
	{
		getline(input,temp);
		
		for (int i = 0; i<4; i++)
		{
			if(temp !="-1")
			{
				getline(input,temp);
				cout << temp << endl;
			}
			else
			{
			temp.erase();
			}
		}
   }
	else
	{
		cout << "Cannot open courses.txt"<<  endl;
	}
	
}

int toint(string input)
{
	int temp = 0;
	stringstream line(input);
	line >> temp;
	return temp;
}
