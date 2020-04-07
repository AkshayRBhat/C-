/*
 * 18.cpp
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
	void add();
};
template <class t>
void myclass <t>::add()
{
	cout<<"\n sum of"<<a<<"and"<<b<<"is"<<a+b;
}
int main()
{
	myclass <int> m1;
	myclass <float> m2;
	m1.input();
	m2.input();
	m1.show();
	m2.show();
	m1.add();
	m2.add();
}
