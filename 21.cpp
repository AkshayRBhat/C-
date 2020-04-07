/*
 * 21.cpp
 *
 *  Created on: Apr 15, 2006
 *      Author: user
 */


#include <iostream>
using namespace std;
class myclassb;
class myclassa
{
private:
	int a;
public:
	myclassa()
	{
		a=0;
	}

	void input()
	{
		cout<<"\n Enter a number:";
		cin>>a;
	}
	void show()
	{
		cout<<"\n a"<<a;
	}
	friend myclassb;
};
class myclassb
{
private:
	int b;
public:
	myclassb()
	{
		b=0;
	}

	void input()
	{
		cout<<"\n Enter a number:";
		cin>>b;
	}
	void show()
	{
		cout<<"\n b"<<b;
	}
	void add(myclassa x)
	{
		cout<<"\n sum of"<<x.a<<"and"<<b<<"is"<<x.a+b;
	}
};

int main()
{
	myclassa m1;
	myclassb m2;
	m1.input();
	m1.show();
	m2.input();
	m2.show();
	m2.add(m1);
	}

