/*
 * 1.cpp
 *
 *  Created on: May 13, 2006
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
	myclass(int a)
	{
		no=a;
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
	~myclass()
	{
		cout << "\n Object Destroyed ";
	}
};
int main()
{
	myclass m1;
	myclass m2(100);
	m1.input();
	m1.show();
	m2.show();
	}
