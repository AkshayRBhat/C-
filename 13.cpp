/*
 * 13.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: user
 */

#include <iostream>
using namespace std;
#include <string.h>
class student
{
private:
	int id;
	char name[50];

public:
	student()
	{id=0;}
	student(int a,char *b)
	{id=a;strcpy(name,b);}
	void input()
	{cout<<"\n enter id:";
	cin>>id;
	cout<<"\n enter name";
	cin>>name;

	}
	void show()
	{
		cout<<"\n ID"<<id;
		cout<<"\n name"<<name;
	}
	void hello()
	{
		cout << "\n Hello from student class";
	}
};
class marks
{
private:
	int mks[3];
public:
	marks()
	{ mks[0]=mks[1]=mks[2]=0;}
	marks(int c,int d,int e)
	{ mks[0]=c;mks[1]=d;mks[2]=e;}
	void input()
	{
		for(int i=0;i<3;i++)
		{
			cout<<"\n Enter marks";
			cin>>mks[i];
		}
	}
	void show()
	{
		for(int i=0;i<3;i++)
			cout<<"\n marks"<<mks[i];
	}
	int gettot() { return mks[0]+mks[1]+mks[2]; }
};

class report:public student,marks
{
private:
		int tot;
		float avg;
public:
		report():student(),marks()
		{
			tot=0;avg=0;
		}
		report(int a,char *b,int c,int d,int e):student(a,b),marks(c,d,e)
		{
			tot=c+d+e;
			avg=tot/3;
		}
		void input()
		{
			student::input();
			marks::input();
			tot=marks::gettot();
			avg=tot/3;
		}
		void show()
		{
			student::show();
			marks::show();
			cout << "\n Total marks : "<< tot;
			cout << "\n Average Marks : " << avg;
		}
};
int main()
{
	report m1;
	report m2(101,"Satish",75,80,85);
	m1.input();
	m1.show();
	m2.show();
}
