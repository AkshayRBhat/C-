/*
 * 20.cpp
 *
 *  Created on: Apr 8, 2006
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
	friend void add(myclassa,myclassb);
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
friend void add(myclassa,myclassb);
};
void add(myclassa x,myclassb y)
{
	cout<<"\n sum of"<<x.a<<"and"<<y.b<<"is"<<x.a+y.b;
}
int main()
{
	myclassa m1;
	myclassb m2;
	m1.input();
	m1.show();
	m2.input();
	m2.show();
	add(m1,m2);
	}

