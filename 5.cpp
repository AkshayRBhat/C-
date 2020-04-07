/*
 * 5.cpp
 *
 *  Created on: May 13, 2006
 *      Author: user
 */

#include <iostream>
using namespace std;
template <class t>
t low(t a,t b)
{
	if(a<b)
		return a;
	else
		return b;
}

int main()
{
	int a,b;float c,d;char e,f;
	a=10;b=20;c=10.50;d=25.10;e='a';f='A';
	cout<<"\n lowest value"<<low(a,b);
	cout<<"\n lowest value"<<low(c,d);
	cout<<"\n lowest value"<<low(e,f);

}
