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
TEST MAIN
*/

#include<iostream>
#include<string>

#include "a2p1.h"

using namespace std;

int main()
{

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