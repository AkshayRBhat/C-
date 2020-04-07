/*
 * 16.cpp
 *
 *  Created on: Apr 8, 2006
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
};
class marks
{
private:
	student s;
	int mks[3];
public:
	marks()
	{mks[0]=mks[1]=mks[2]=0;}



	void input()
	{
		s.input();
		for(int i=0;i<3;i++)
		{
			cout<<"\n Enter marks";
			cin>>mks[i];
		}
	}
	void show()
	{
		s.show();
		for(int i=0;i<3;i++)
			cout<<"\n marks"<<mks[i];
	}
};
int main()
{
	marks m1;

	m1.input();
	m1.show();

}

