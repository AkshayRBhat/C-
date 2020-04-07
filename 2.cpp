/*
 * 2.cpp
 *
 *  Created on: May 13, 2006
 *      Author: user
 */
#include <iostream>
#include <string.h>
using namespace std;
class student
{
private:
	int id;
	char sub[50];
	int marks;
public:
	student()
	{
		id=0;
		marks=0;
	}
	student(int a,char *b,int c)
	{
		id=a;
		strcpy(sub,b);
		marks=c;
	}
	void input()
	{
		cout<<"\n enter id:";
		cin>>id;
		cout<<"\n enter subject";
		cin>>sub;
		cout<<"\n Enter marks";
		cin>>marks;
	}
	~student()
	{
		cout << "\n Object Destroyed ... ";
	}
	void show();
};
void student ::show()
{
	cout<<"\n ID"<<id;
	cout<<"\n Subject"<<sub;
	cout<<"\n Marks"<<marks;
}
int main()
{
	student s1; // default constructor
	student s2(1001,"Maths",90); // overloaded constructor with 3 parameters
	s1.input();
	s1.show();
	s2.show();
}
