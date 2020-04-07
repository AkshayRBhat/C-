/*
 * 19.cpp
 *
 *  Created on: Apr 8, 2006
 *      Author: user
 */

#include <iostream>
using namespace std;
template <class t>
class myclass
{
protected:
	t a;t b;
public:
	void input()
	{
		cout<<"\n enter a number";
		cin>>a;
		cout<<"\n enter a number";
		cin>>b;
	}
	void show()
	{
		cout<<"\n a"<<a;
		cout<<"\n b"<<b;
	}
};


template <class t>
class newclass:public myclass<t>
{
public:
void add()
{
	cout<<"\n sum of"<<myclass<t>::a<<"and"<<myclass<t>::b<<"is"<<myclass<t>::a+myclass<t>::b;
}
};

int main()
{
	newclass <int> m1;
	newclass <float> m2;
	m1.input();
	m2.input();
	m1.show();
	m2.show();
	m1.add();
	m2.add();
}

