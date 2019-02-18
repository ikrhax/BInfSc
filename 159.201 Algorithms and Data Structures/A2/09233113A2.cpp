/*
***********************************
*                                 *
*     159.201 - Assignment 2	    *	
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

using namespace std;

struct Node 
{
	int data;
	Node *next;
};

class Stack 
{
	private:
		Node *listpointer;
	public:
		Stack();
		~Stack();
		void Push(int newthing);
		void Pop();
		int Top();
		bool isEmpty();
};

Stack::Stack() 
{
	listpointer = NULL;
};

Stack::~Stack() 
{
};


void Stack::Push(int newthing) 
{
	Node *temp;
	temp = new Node;
	temp->data = newthing;
	temp->next = listpointer;
	listpointer = temp;
}


void Stack::Pop() 
{
	Node *p;
	p = listpointer;
	if (listpointer != NULL) 
	{
		listpointer = listpointer->next;
		delete p;
	}
}


int Stack::Top() 
{
	if (listpointer != NULL) 
	{
		return listpointer->data;
	}
	return 0;
}


bool Stack::isEmpty() 
{
	if (listpointer == NULL) 
	{
		return true;
	}
	return false;
}


int main( int argc, char** argv )
{
	Stack stack;
	int result = 0, op1 = 0, op2 = 0, number = 0;
	char oper;
	string expression;
	
	/*
	ifstream input;
   input.open("RPN4.txt");
	*/

	if(argc!=2) 
	{
	  cout<< "needs a filename as argument  " << endl;
	  exit(0);
	}
	input_file.open(argv[1]);
	if(!input_file.good())
	{
	  cout<< "cannot read file " << argv[1] << endl; 
	  exit(0);
	}

	
	while(!input.eof())
		{
		getline(input,expression);
		if(isdigit(expression[0])){
			stringstream line(expression);
		   line >> number;
		   cout << "reading number " << number << endl;
			stack.Push(number);
		} 
		else 
		{
			if(expression[0]=='+' || expression[0]=='-'|| expression[0]=='/'||expression[0]=='*') 
			{
				stringstream line(expression);
				line >> oper;
				cout << "reading operator " << oper << endl;
				if (!stack.isEmpty()) 
				{
					op2 = stack.Top();
					stack.Pop();
				} 
				else 
				{
					cout << "too many operators" << endl;
					exit(0);
				}

				if (!stack.isEmpty()) 
				{
					op1 = stack.Top();
					stack.Pop();
				} 
				else 
				{
					cout << "too many operators" << endl;
					exit(0);
				}
				if(oper=='+') result = op1 + op2;
				if(oper=='*') result = op1 * op2;
				if(oper=='-') result = op1 - op2;
				if(oper=='/') result = op1 / op2;
				stack.Push(result);
			}
		}
	}
	result = stack.Top();
	stack.Pop();
	
	if (!stack.isEmpty()) 
	{
		cout << "too many numbers" << endl;
	} 
	else
	{
		cout << "The result is " << result << endl;
	}
}