/*
 * 10.cpp
 *
 *  Created on: Mar 10, 2018
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
	static int tot;
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
		tot+=c;
	}
	void input()
	{
		cout<<"\n enter id:";
		cin>>id;
		cout<<"\n enter subject";
		cin>>sub;
		cout<<"\n Enter marks";
		cin>>marks;
		tot+=marks;
	}
	void show();
	static void total()
	{
		cout << "\n Total marks "<<tot;
	}
};
int student::tot=0;
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
	student::total();
}
