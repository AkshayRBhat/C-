/*
 * 6.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: user
 */

#include <iostream>
using namespace std;
class myclass
{
private:
	int no;
public:
	myclass()
	{
		no=0;
	}
	myclass(int x)
	{
		no=x;
	}
	void input()
	{
		cout<<"\n Enter a number:";
		cin>>no;
	}
	void show()
	{
		cout<<"\n No"<<no;
	}
	void operator ++(int)
		{
		no++;
		}
	myclass operator +(myclass x)
	{
		myclass t;
		t.no=no+x.no;
		return t;
	}
	void operator +=(myclass x)
		{
		no=no+x.no;
		}
};
int main()
{
	myclass m1;
	myclass m2(100);
	m1.input();
	m1.show();
	m2.show();
	m2++;
	m2.show();
	myclass m3=m1+m2;
	m3.show();
	m2+=m3;
	m2.show();
	}

