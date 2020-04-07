/*
 * 23.cpp
 *
 *  Created on: Apr 22, 2006
 *      Author: user
 */
#include <iostream>
using namespace std;
class marks
{
private:
	int roll;
	int mks;
public:
	marks()
	{
		roll=-1;mks=0;
	}
	marks(int m,int n)
	{
		roll=m;mks=n;
	}
	friend ostream& operator <<(ostream& ostrm,marks& m);
	friend istream& operator >>(istream& istrm,marks& m);
};
	ostream& operator <<(ostream& ostrm,marks& m)
	{
		ostrm<<endl<<"Roll no:"<<m.roll<<endl<<"Marks:"<<m.mks;
		return ostrm;
	}
	istream& operator >>(istream& istrm,marks& m)
	{
		cout<<endl<<"Enter roll number:";
		istrm>>m.roll;
		cout<<endl<<"Enter marks:";
		istrm>>m.mks;
		return istrm;
	}
	int main()
	{
		marks m1;
		cin>>m1;
		cout<<endl<<"The record is .......";
		cout<<m1;
	}

