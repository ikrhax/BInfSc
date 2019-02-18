/*
***********************************
*                                 *
*     159.201 - Assignment 4	    *	
*	       Simon Parr 		       *
*          09233113               *
*                                 *
***********************************
*/


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <locale>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

/////// PART A

// template class list definition
template <class T>

class List 
{
	private:
		
		struct Node 
		{
			T data;
			Node *next;
		};
		Node *front, *current;
		
	public:
		List();
		~List();
		void AddNode(T newthing);
		void Reverse();
		void Display();
		void MakeCopy(List &L);
		bool FirstItem(T &item);
		bool NextItem(T &item);
};

// constructor
template <class T>
List<T>::List() {
	front = NULL; current = NULL;
}


template <class T>
void List<T>::AddNode(T newthing) 
{
	Node *temp1;
	temp1 = front;
	if (temp1 != NULL) 
		{
		while (temp1->next != NULL) 
		{
			temp1 = temp1->next;
		}
	}
	Node *temp2;
	temp2 = new Node;
	temp2->data = newthing;
	temp2->next = NULL;
	if (temp1 != NULL) 
	{
		temp1->next = temp2;
	}
	else 
	{
		front = temp2;
	}
}


template <class T>
void List<T>::Reverse() 
{
	Node *temp1, *temp2;
	current = front->next;
	temp2 = front;
	while (current != NULL) 
	{
		temp1 = current->next;
		current->next = front;
		front = current;
		current = temp1;
	}
	temp2->next = NULL;
}

// display data of current ptr
template <class T>
void List<T>::Display() 
{
	cout << current->data;
}

// copy a list
template <class T>
void List<T>::MakeCopy(List &L) 
{
	Node *temp;
	temp = front;
	while (temp!=NULL) 
	{
		L.AddNode(temp->data);
		temp=temp->next;
	}
}

// return true if FirstItem is valid, set item to value of front
template <class T>
bool List<T>::FirstItem(T &item) 
{
	if (front == NULL) 
	{ 
		return false; 
	}
	item = front->data;
	current = front;
	return true;
}

// return true if NextItem is valid, set item to value of current
template <class T>
bool List<T>::NextItem(T &item) 
{
	current = current->next;
	if (current == NULL) 
	{
		return false; 
	}
	item = current->data;
	return true;
}

/////// PART B

class BigNumber 
{
	private:
		List<int> listOfDigits;
	public:
		BigNumber();
		~BigNumber();
		void ReadFromString(string decstring);
		void PrintBigNumber();
		void AddBigNumbers(BigNumber B1,BigNumber B2);
};


BigNumber::BigNumber()
{

}


BigNumber::~BigNumber()
{
	
}

// read a string, adding a new node per digit of the decimal string
void BigNumber::ReadFromString(string decstring) 
{
	// get rid of signed vs unsigned comparison warning
	int size = decstring.size();
	for (int i = 0; i < size; i++) 
	{
		if (decstring[i] != '\n' && decstring[i] != '\r') 
		{
			int temp=decstring[i]-48;
			listOfDigits.AddNode(temp);
		}
	}
}

// print big number
void BigNumber::PrintBigNumber() 
{
	bool isDigitValid;
	int temp = 0;
	isDigitValid = listOfDigits.FirstItem(temp);
	while (isDigitValid) 
	{
		listOfDigits.Display();
		isDigitValid = listOfDigits.NextItem(temp);
	}
	cout << endl;
	// reverse it because i'm adding to tail, i should have used stacks
	listOfDigits.Reverse();
}

// add two big numbers
void BigNumber::AddBigNumbers(BigNumber B1,BigNumber B2) 
{
	int carry = 0, digit1 = 0, digit2 = 0;

	
	bool isFirstDigitValid = B1.listOfDigits.FirstItem(digit1);
	bool isSecondDigitValid = B2.listOfDigits.FirstItem(digit2);

	
	while ((isFirstDigitValid) || (isSecondDigitValid)) 
		{
		int partialres = 0;

		if ((isFirstDigitValid) && (isSecondDigitValid)) 
		{
			partialres = digit1 + digit2 + carry;
		} 
		else if 
		((isFirstDigitValid) && (!isSecondDigitValid)) 
		{
			partialres = digit1 + carry;
		} 
		else if ((isSecondDigitValid) && (!isFirstDigitValid)) 
		{
			partialres = digit2 + carry;
		}

		
		if (partialres <= 9) 
		{
			carry = 0;
		} 
		else 
		{
			carry = partialres/10;
		}
		
		listOfDigits.AddNode(partialres%10);

		if (isFirstDigitValid) 
		{
			isFirstDigitValid = B1.listOfDigits.NextItem(digit1);
		}
		
		if (isSecondDigitValid) 
		{
			isSecondDigitValid = B2.listOfDigits.NextItem(digit2);
		}
	}

	
	if (carry != 0) 
	{ 
		listOfDigits.AddNode(carry);
	}

	listOfDigits.Reverse();
}



BigNumber B1,B2,RES;

int main(int argc, char ** argv) 
{
	string numberstring;
	int stringseq = 0;
	ifstream input_file;

	
	// input_file.open("samplenumbers1.txt");
	
	if (argc==2) 
	{
		input_file.open(argv[1]);
	} 
	else 
	{ 
		cout << "cannot read the file " << argv[1] << endl; exit(0);
	}
	while (!input_file.eof()) 
	{
		getline(input_file,numberstring);
		if (!input_file.eof()) 
		{
			if (stringseq == 0) 
			{
				B1.ReadFromString(numberstring);
				stringseq = 1;
			} 
			else 
			{ 
				B2.ReadFromString(numberstring); 
			}
		}
	}

  B1.PrintBigNumber();
  cout << "+" << endl;
	
  B2.PrintBigNumber();
  cout << "=" << endl;

  RES.AddBigNumbers(B1,B2);

  RES.PrintBigNumber();
}
