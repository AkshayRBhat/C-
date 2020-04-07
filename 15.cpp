/*
 * 15.cpp
 *
 *  Created on: Apr 8, 2006
 *      Author: user
 */
#include <iostream>
#include <string.h>
using namespace std;
class employee
{
private:
	int id;
	char name[50];
	int basic;
public:
	employee()
	{
		id=0;
		basic=0;
	}
	employee(int a,char *b,int c)
	{
		id=a;
		strcpy(name,b);
		basic=c;
	}
	void input()
	{
		cout<<"\n enter id:";
		cin>>id;
		cout<<"\n enter name:";
		cin>>name;
		cout<<"\n Enter basic:";
		cin>>basic;
	}
	void show()
	{
		cout<<"\n id "<<id<<"\n name "<<name<<"\n basic "<<basic;
	}
};
class manager:virtual public employee
{
protected:
	int da;
public:
	manager():employee()
	{
		da=0;
	}
	manager(int a,char *b,int c,int d):employee(a,b,c)
	{
		da=d;
	}
	void input()
	{
		employee::input();
		cout<<"\n enter da";
		cin>>da;
	}
	void show()
	{
		employee::show();
		cout<<"\n da "<<da;
	}
};
class clerk:virtual public employee
{
protected:
	int ta;
public:
	clerk():employee()
	{
		ta=0;
	}
	clerk(int a,char *b,int c,int d):employee(a,b,c)
	{
		ta=d;
	}
	void input()
	{
		employee::input();
		cout<<"\n enter ta";
		cin>>ta;
	}
	void show()
	{
		employee::show();
		cout<<"\n ta "<<ta;
	}
};
class supervisor:public manager,clerk
{
private:
	int incentive;
public:
	supervisor():employee(),manager(),clerk()
	{
		incentive=0;

	}
	supervisor(int a,char*b,int c,int d,int e,int f):employee(a,b,c),manager(a,b,c,d),clerk(a,b,c,e)
	{
		incentive=f;
	}
	void input()
	{
		manager::input();
		cout<<"\n enter ta: ";
		cin>>ta;
		cout<<"\n enter incentive";
		cin>>incentive;
	}
	void show()
	{
		manager::show();
		cout<<"\n ta:"<<ta;
		cout<<"\n incentive "<<incentive;
	}
};
int main()
{
	supervisor s1;
	supervisor s2(101,"asdf",5000,4000,3000,2000);
	s1.input();
	s1.show();
	s2.show();
	cout<<"\n sizeof supervisor "<< sizeof(s1);
	cout<<"\n sizeof supervisor "<< sizeof(s2);
}

