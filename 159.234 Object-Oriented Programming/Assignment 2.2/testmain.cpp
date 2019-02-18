#include "A2P2.h"



/*

Problem to solve: 

You will design and use a class template. The name of the class template must be Bin. The type "Bin" represents an unordered collection of n items (at locations 0 to n-1), where each item is of a generic type called "itemType". 
Duplicate items are allowed. You may assume that the type "itemType" supports "operator=()" and "==".The minimum required interface for the class Bin is presented in the table below. 
Your solution should overload the output operator such that code as presented in Figure 1 will work to provide the output provided in Figure 2. You should write all your code in a file named a2p2.h 

The a2p2.h file should be organized as follows: 
1. Comments about the authors of the solution, about reasonable assumptions you made and any other facts we should be aware when testing your solution 
2. Including all necessary files 
3. The Bin class template listing-no member function implementation inside the class is allowed. 
4. The Bin class template member functions implementations, 
5. Implementation of all global functions, including the function printInfo(), that should display on screen all authors of the assignment solution submitted for marking. 

The Bin class should have (at least) all of the following (both A and B parts): 

A) private members: 

	Capacity - unsigned int - Maximum number of items that can be stored in the Bin before reallocation occurs. 
	Size - unsigned int - The actual number of items in the Bin.  
	Array - itemType* - The address of the array of items.  
	Reallocate() - It increases the Bin's object capacity.
	
	
B) public function members: 

	Bin()  - Default constructor. Initializes the Bin to empty (array points to NULL, size and capacity are 0).  
	~Bin()  - Destructor. De-allocates memory & updates size and capacity to 0.  
	Bin(..), ..   - The copy and the move constructors  
	..operator=(..),..   - The assignment operators (copy and move) 
	length() const   - Returns the number of actual items in the Bin. 
	isEmpty()const  - Returns true if the Bin has no item and false otherwise. 
	print()const  - Displays all "size" elements in a table of  5 elements per row (10 spaces per element). 
	find( const itemType& x ) const  - Locates the first instance of a specified item. Returns the position if it was located; size otherwise.  
   retrieve(itemType& x,unsigned i)const  -  Retrieves the item at position i (unless i is not valid). Returns true if the item was retrieved; false otherwise.  
	remove( itemType& x, unsigned i )  -   Removes the item at position i (unless i is not valid). Rearranges the elements in the Bin such that no empty place occurs inside the Bin object. Returns true if the item was removed; false otherwise.  
	insert(const itemType &x, unsigned i)  - Inserts x into the Bin at position i. If the Bin is full, allocates additional space before inserting the item. Returns true if the item was inserted; false otherwise.  
*/

using namespace std;

int main()
{
	
	Bin<float> flObj;
	
	
	
	flObj.insert(500.6, 0);
	flObj.insert(500.6, 0);
	flObj.insert(500.6, 0);
	flObj.insert(500.6, 0);
	
	flObj.printAll();
	
	cout << "\nValue returned by 'isEmpty': " << (flObj.isEmpty()?"true":"false") << endl;
	
	float item = 0.0;
	bool flag; 
	unsigned last = flObj.length();
	
	for (unsigned i = 0; i<=last; i++)
	{
		flag = flObj.retrieve (item, i);
		cout << "Retrive from position " << i << " was" << (flag === true? "succesful ":" unsuccesful ");
		cout << " item: " << (flag == true? item: 0) << endl;
	}
	
	item = 800;
	
	unsigned position = flObj.find(item);
	
	cout << "Element " << item << (position < flObj.length() ? " ":" not ") << "found.";
	cout << "\nValue returned by 'isEmpty': " << (flObj.isEmpty()? "true":"false");
	cout << "\nValue returned by 'length': " << flObj.length();
	
	cout << "\n\n A bin of strings:\n";
	
	Bin<string> strObj;
	
	strObj.insert(" be happy!", 0); 
	strObj.insert(" worry", 0); 
	strObj.insert("Don't", 0); 
	
	strObj.printAll();
	
	cout << "\n\n All done! Bye, bye...";
	
}
	
		