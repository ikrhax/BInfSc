/*
***********************************
*                                 *
*     159.201 - Assignment 1	    *	
*	       Simon Parr 		       *
*          09233113               *
*                                 *
***********************************
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


//Structure of Node:
struct Node 
{
	int xloc;
	int yloc;
	int value;
	Node *next;	
};


//Functions:

//Add the Matrix Together
void generateResultMatrix();

//Print form Linked List to Matrix
void printMatrixFromLL(Node *listpointer);

//Provided addNode 
void addNode(Node *&listpointer, int x, int y, int v);
//Funciton to open the First Matrix from Matrix1.txt
void readMatrix1(Node* &a, char *file_name);

//Function to open the Second Matrix from Matrix2.txt
void readMatrix2(Node* &b, char *file_name);

//Search function Provided. 
int searchLL (Node *listpointer, int r, int c);


int xpos = 0;
int ypos = 0;

//Pointers to begin Linked Lists with:
Node *first;
Node *second;
Node *result;  


int main( int argc, char** argv ) 
{
	//check for the correct number of arguements 
	if(argc!=3) 
	{
		printf("needs two matrices \n"); 
		exit(0);
	}
	
	//Set pointers to NULL
	first = NULL;
	second = NULL;
	result = NULL;
	
	//Read the First Matrix
	readMatrix1(first, argv[1]);
	cout << "Matrix 1: ";
	printMatrixFromLL(first);
	
	//Read the Second Matrix
	readMatrix2(second, argv[2]);
	cout << "Matrix 2: ";
	printMatrixFromLL(second);
	
	//Generate the Result	
	cout << "Matrix Result: ";
	generateResultMatrix();
	printMatrixFromLL(result);
}


void readMatrix1(Node* &a, char *file_name) 
{
	int x = 0;
	int y = 0;
	int value = 0;
	string temp;
	
   ifstream input;
   input.open(file_name);
	
   if(!input.good())
	{
		cout << "Cannot open the first Matrix - Matrix1.txt"<<  endl;
		exit(EXIT_SUCCESS);
   }

	if(input.good())
	{
	   getline(input,temp);
	   stringstream line(temp);
	   line >> x >> y;
   }

	for(int i = 0; i < x; ++i)
	{
      if(input.good()) 
		{
			getline(input,temp);
			stringstream sline(temp);
			
			for(int j = 0; j < y; ++j)
			{
				sline >> value;
				if(value == 0) continue;
				addNode(a, i, j, value);
			}
		}
	}
   input.close();
	xpos = x;
	ypos = y;
}


void readMatrix2(Node* &b, char *file_name) 
{
	int x = 0; 
	int y = 0; 
	int value = 0;
	
   ifstream input;
   input.open(file_name);
	
   if(!input.good())
	{
		cout << "Cannot open the second Matrix - Matrix2.txt" << endl;
		exit(EXIT_SUCCESS);
   }
	string temp;

	if(input.good())
	{
	   getline(input,temp);
	   stringstream stemp(temp);
	   stemp >> x >> y;
   }

	for(int i = 0; i < x; ++i)
	{
      if(input.good()) 
		{
			getline(input,temp);
			stringstream line(temp);
			
			for(int j = 0; j < y; ++j)
			{
				line >> value;
				if(value == 0) continue;
				addNode(b, i, j, value);
			}
		}
	}
   input.close();
	xpos = x;
	ypos = y;
}


void addNode(Node *&listpointer, int x, int y, int v) 
{
	
	/*
	Where:
	x = x location 
	y = y location
	v = actual value from matrix
	*/
	
	Node *current;
	current = listpointer;
	if (current != NULL) 
	{
		while (current->next != NULL) 
		{
			current = current->next;
		}
	}
	
	Node *temp;
	temp = new Node;
	temp->xloc = x;
	temp->yloc = y;
	temp->value = v;
	temp->next = NULL;
	
	if (current != NULL) 
	{
		current->next = temp;
	} 
	else 
	{
		listpointer = temp;
	}
}



void generateResultMatrix() 
{
	for (int i = 0; i < xpos; i++) 
	{
		for (int j = 0; j < ypos; j++) 
		{
			int re = searchLL(first, i, j) + searchLL(second, i, j);
			
			if (re != 0) 
			{
				addNode(result, i, j, re);
			}
		}
	}
}


//Print out Fucntion - accepts the LL that I want to print.
void printMatrixFromLL(Node *listpointer) 
{
	Node *current;
	current = listpointer;
	
	
	//Print the entire contents of the linked list - showing all non-zero values
	while (current != NULL) 
	{
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
	
	
	
	//Print the actual Matrix
	for (int i = 0; i < xpos; i++) 
	{
		for (int j = 0; j < ypos; j++) 
		{
			cout << searchLL(listpointer, i, j) << " ";
		}
		cout << endl;
	}
}


// Search Function
int searchLL (Node *listpointer, int x, int y) 
{
	Node *current;
	current = listpointer;
	while (current != NULL) 
	{
		if (current->xloc == x && current->yloc == y) 
		{
			return current->value;
		}
		current = current->next;
	}
	return 0;
}

