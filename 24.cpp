/*
 * 24.cpp
 *
 *  Created on: Apr 22, 2006
 *      Author: user
 */
#include<iostream>
using namespace std;
template <class T,int MAX>
class stack
{
private:
	T st[MAX];
	int top;
public:
	stack()
	{
		top=-1;
	}
	void push(T var)
	{
		st[++top]=var;
	}
	T pop()
	{
		return (st[top--]);
	}

};
int main()
{
	stack <int,3> s1;
	stack <char,5> s2;
	s1.push(50);
	s2.push('a');
	int x1=s1.pop();
	char x2=s2.pop();
	cout<<x1<<x2<<endl;
}
